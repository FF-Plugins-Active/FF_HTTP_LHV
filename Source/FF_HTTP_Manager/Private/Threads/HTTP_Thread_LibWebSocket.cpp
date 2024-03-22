// Fill out your copyright notice in the Description page of Project Settings.

#include "Threads/HTTP_Thread_LibWebSocket.h"
#include "FF_HTTP_Advance.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_LibWebSocket::FHTTP_Thread_LibWebSocket(AHTTP_Server_Advance* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Port_HTTP = this->Parent_Actor->Port_HTTP;
	this->Port_HTTPS = this->Parent_Actor->Port_HTTPS;

	this->RunnableThread = FRunnableThread::Create(this, *this->Parent_Actor->ThreadName);
}

FHTTP_Thread_LibWebSocket::~FHTTP_Thread_LibWebSocket()
{
	if (this->RunnableThread)
	{
		//this->RunnableThread->Suspend(true);
		//this->bStartThread = false;
		//this->RunnableThread->Suspend(false);
		//this->RunnableThread->WaitForCompletion();

		this->RunnableThread->Kill(true);
		delete this->RunnableThread;
	}
}

bool FHTTP_Thread_LibWebSocket::Init()
{	
	this->Callback_HTTP_Start();
	this->bStartThread = true;

	return true;
}

uint32 FHTTP_Thread_LibWebSocket::Run()
{
	while (this->bStartThread)
	{
		if (this->Server_Context)
		{
			lws_service(this->Server_Context, 0);
		}
	}

	return 0;
}

void FHTTP_Thread_LibWebSocket::Stop()
{
	lws_context_destroy(this->Server_Context);
	this->Server_Context = NULL;
	this->Server_Protocols.Empty();

	this->bStartThread = false;
}

void FHTTP_Thread_LibWebSocket::Toggle(bool bIsPause)
{
	if (this->RunnableThread)
	{
		this->RunnableThread->Suspend(bIsPause);
	}
}

void FHTTP_Thread_LibWebSocket::Callback_HTTP_Start()
{
	auto Callback_HTTP = [](lws* wsi, lws_callback_reasons reason, void* user, void* in, size_t len)->int
		{
			uint8_t buf[LWS_PRE + 2048], * start = &buf[LWS_PRE], *p = start, *end = &buf[sizeof(buf) - 1];

			if (reason == LWS_CALLBACK_HTTP)
			{
				if (lws_add_http_common_headers(wsi, HTTP_STATUS_OK, "text/html", LWS_ILLEGAL_HTTP_CONTENT_LEN, &p, end))
				{
					return 1;
				}

				if (lws_finalize_write_http_header(wsi, start, &p, end))
				{
					return 1;
				}

				lws_callback_on_writable(wsi);
			}

			return lws_callback_http_dummy(wsi, reason, user, in, len);
		};

	this->Server_Protocols.SetNum(2);
	this->Server_Protocols[0].name = "http";
	this->Server_Protocols[0].callback = Callback_HTTP;
	this->Server_Protocols[0].per_session_data_size = 0;
	
	this->Server_Protocols[1].name = NULL;
	this->Server_Protocols[1].callback = NULL;
	this->Server_Protocols[1].per_session_data_size = 0;
	
	memset(&this->Server_Info, 0, sizeof(this->Server_Info));
	this->Server_Info.port = this->Port_HTTP;
	this->Server_Info.protocols = this->Server_Protocols.GetData();
	this->Server_Info.uid = -1;
	this->Server_Info.gid = -1;

	this->Server_Context = lws_create_context(&this->Server_Info);
}