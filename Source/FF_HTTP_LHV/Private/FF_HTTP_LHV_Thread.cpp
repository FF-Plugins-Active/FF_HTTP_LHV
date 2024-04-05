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
	hv::async::cleanup();

	this->bStartThread = false;
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
	auto Callback_Router_Handler = [this](HttpRequest* Request, HttpResponse* Response)->int
		{
			UHttpConnectionLhv* LibHvConnection = NewObject<UHttpConnectionLhv>();
			LibHvConnection->Request = Request;
			LibHvConnection->Response = Response;
			
			this->Parent_Actor->DelegateHttpLibHv.Broadcast(LibHvConnection);
			this->Parent_Actor->OnHttpAdvMessage(LibHvConnection);
			
			LibHvConnection->Future.Wait();
			int ResponseCode = LibHvConnection->Future.Get();

			return ResponseCode;
		};

	this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*this->API_URI), Callback_Router_Handler);

	this->HTTP_LVH_Router.Static("/", TCHAR_TO_UTF8(*this->Server_Path_Root));
	this->HTTP_LVH_Router.AllowCORS();

	this->HTTP_LVH_Server.service = &this->HTTP_LVH_Router;
	this->HTTP_LVH_Server.port = this->Port_HTTP;
	this->HTTP_LVH_Server.start();
	//this->HTTP_LVH_Server.setThreadNum(4);
	//this->HTTP_LVH_Server.run();

	return true;
#else
	return false;
#endif
}