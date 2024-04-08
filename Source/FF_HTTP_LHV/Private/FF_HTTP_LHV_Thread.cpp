// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_LHV_Thread.h"
#include "FF_HTTP_LHV_Server.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_LibHv::FHTTP_Thread_LibHv(AHTTP_Server_LHV* In_Parent_Actor)
{
#ifdef _WIN64
	this->Parent_Actor = In_Parent_Actor;

	this->Server_Path_Root = this->Parent_Actor->Server_Path_Root;
	this->Server_Path_404 = this->Parent_Actor->Server_Path_404;
	this->API_URI = this->Parent_Actor->API_URI;

	this->Port_HTTP = this->Parent_Actor->Port_HTTP;
	this->Port_HTTPS = this->Parent_Actor->Port_HTTPS;
	this->ThreadsNum = this->Parent_Actor->ThreadsNum;

	this->RunnableThread = FRunnableThread::Create(this, *this->Parent_Actor->Server_Name);
#endif
}

FHTTP_Thread_LibHv::~FHTTP_Thread_LibHv()
{
#ifdef _WIN64
	if (this->RunnableThread)
	{
		this->RunnableThread->Kill(true);
		delete this->RunnableThread;
	}
#endif
}

bool FHTTP_Thread_LibHv::Init()
{
#ifdef _WIN64
	
	return this->Callback_HTTP_Start();

#else
	return false;
#endif
}

uint32 FHTTP_Thread_LibHv::Run()
{
	while (this->bStartThread)
	{
		//UE_LOG(LogTemp, Display, TEXT("LibHv currently working."));
	}

	return 0;
}

void FHTTP_Thread_LibHv::Stop()
{
#ifdef _WIN64
	
	this->HTTP_LVH_Server.stop();

#if (LHV_HANDLER_TYPE == 0 || LHV_HANDLER_TYPE == 2)
	hv::async::cleanup();
#endif

	this->bStartThread = false;

	this->Parent_Actor->Delegate_HTTP_LibHv_Stop.Broadcast();
	this->Parent_Actor->OnHttpAdvStop();

#endif
}

bool FHTTP_Thread_LibHv::Toggle(bool bIsPause)
{
#ifdef _WIN64
	
	if (!this->RunnableThread)
	{
		return false;
	}

	this->RunnableThread->Suspend(bIsPause);

	return true;
#else
	return false;
#endif
}

bool FHTTP_Thread_LibHv::Callback_HTTP_Start()
{
#ifdef _WIN64

#if (LHV_HANDLER_TYPE == 0)

	auto Callback_Router_Handler = [this](HttpRequest* Request, HttpResponse* Response)->int
		{
			UHttpConnectionLhv* LibHvConnection = NewObject<UHttpConnectionLhv>();
			LibHvConnection->Request = Request;
			LibHvConnection->Response = Response;
			LibHvConnection->RequestTime = FDateTime::Now();
			
			this->Parent_Actor->Delegate_HTTP_LibHv_Request.Broadcast(LibHvConnection);
			this->Parent_Actor->OnHttpAdvMessage(LibHvConnection);
			
			LibHvConnection->Future.Wait();
			int StatusCode = LibHvConnection->Future.Get();

			return StatusCode;
		};

#elif (LHV_HANDLER_TYPE == 1)

	auto Callback_Router_Handler = [this](const HttpRequestPtr& Request, const HttpResponseWriterPtr& Response)
		{
			UHttpConnectionLhv* LibHvConnection = NewObject<UHttpConnectionLhv>();
			LibHvConnection->RequestPtr = &Request;
			LibHvConnection->ResponsePtr = &Response;
			LibHvConnection->RequestTime = FDateTime::Now();

			this->Parent_Actor->Delegate_HTTP_LibHv_Request.Broadcast(LibHvConnection);
			this->Parent_Actor->OnHttpAdvMessage(LibHvConnection);
		};

#elif (LHV_HANDLER_TYPE == 2)

	auto Callback_Router_Handler = [this](const HttpContextPtr& Context)->int
		{
			UHttpConnectionLhv* LibHvConnection = NewObject<UHttpConnectionLhv>();
			LibHvConnection->Context = &Context;
			LibHvConnection->RequestTime = FDateTime::Now();

			this->Parent_Actor->Delegate_HTTP_LibHv_Request.Broadcast(LibHvConnection);
			this->Parent_Actor->OnHttpAdvMessage(LibHvConnection);

			LibHvConnection->Future.Wait();
			int StatusCode = LibHvConnection->Future.Get();

			return StatusCode;
		};

#endif

	this->HTTP_LVH_Router.AllowCORS();
	this->HTTP_LVH_Router.Static("/", TCHAR_TO_UTF8(*this->Server_Path_Root));							// Static Site
	
	this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*this->API_URI), Callback_Router_Handler);					// Non-Querry APIs without "/" at end.
	this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*(this->API_URI + "/")), Callback_Router_Handler);			// Non-Querry APIs with "/" at end.
	this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*(this->API_URI + "/*")), Callback_Router_Handler);			// APIs with Querries.

	this->HTTP_LVH_Server.service = &this->HTTP_LVH_Router;
	this->HTTP_LVH_Server.port = this->Port_HTTP;

	int ServerInitResult = 0;

#if (LHV_HANDLER_TYPE == 0 || LHV_HANDLER_TYPE == 2)
	
	ServerInitResult = this->HTTP_LVH_Server.start();

#elif (LHV_HANDLER_TYPE == 1)
	
	this->HTTP_LVH_Server.setThreadNum((int)this->ThreadsNum);
	
	// We don't want to freeze UE5. So, we need to set "wait" false.
	ServerInitResult = this->HTTP_LVH_Server.run(false);

#endif

	if (ServerInitResult == 0)
	{
		// We have notify start and stop at game thread. FRunnableThread's "Stop" function will already use game thread. So, we just need use AsyncTask in here.
		AsyncTask(ENamedThreads::GameThread, [this]()
			{
				this->Parent_Actor->OnHttpAdvStart();
				this->Parent_Actor->Delegate_HTTP_LibHv_Start.Broadcast();
			}
		);

		return true;
	}

	else
	{
		return false;
	}

#else
	return false;
#endif
}