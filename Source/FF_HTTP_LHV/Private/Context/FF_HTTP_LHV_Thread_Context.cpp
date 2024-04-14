// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_LHV_Thread.h"
#include "FF_HTTP_LHV_Server.h"

// UE Includes.
#include "Async/Async.h"

#if (LHV_HANDLER_TYPE == 2)

bool FHTTP_Thread_LibHv::Callback_HTTP_Start()
{
#ifdef _WIN64

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

	auto Callback_Router_Error = [this](const HttpContextPtr& Context)->int
		{
			return Context->sendFile(TCHAR_TO_UTF8(*this->Server_Path_404));
		};

	this->HTTP_LVH_Router.AllowCORS();
	this->HTTP_LVH_Router.errorHandler = Callback_Router_Error;
	this->HTTP_LVH_Router.Static("/", TCHAR_TO_UTF8(*this->Server_Path_Root));							// Static Site
	
	this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*this->API_URI), Callback_Router_Handler);					// Non-Querry APIs without "/" at end.
	this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*(this->API_URI + "/")), Callback_Router_Handler);			// Non-Querry APIs with "/" at end.
	this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*(this->API_URI + "/*")), Callback_Router_Handler);			// APIs with Querries.

	this->HTTP_LVH_Server.service = &this->HTTP_LVH_Router;
	this->HTTP_LVH_Server.port = this->Port_HTTP;
	
	this->HTTP_LVH_Server.setThreadNum(this->ThreadsNum);
	this->HTTP_LVH_Server.start();
	
	return true;
#else
	return false;
#endif
}

void FHTTP_Thread_LibHv::Callback_HTTP_Stop()
{
#ifdef _WIN64

	this->HTTP_LVH_Server.stop();

#endif
}

#endif