// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_LHV_Thread.h"
#include "FF_HTTP_LHV_Server.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_LibHv::FHTTP_Thread_LibHv(AHTTP_Server_LHV* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;

	this->Server_Path_Root = this->Parent_Actor->Server_Path_Root;
	this->Server_Path_404 = this->Parent_Actor->Server_Path_404;
	this->API_URI = this->Parent_Actor->API_URI;

	this->Port_HTTP = this->Parent_Actor->Port_HTTP;
	this->Port_HTTPS = this->Parent_Actor->Port_HTTPS;
	this->ThreadsNum = this->Parent_Actor->ThreadsNum;

	this->RunnableThread = FRunnableThread::Create(this, *this->Parent_Actor->Server_Name);
}

FHTTP_Thread_LibHv::~FHTTP_Thread_LibHv()
{
	if (this->RunnableThread)
	{
		this->RunnableThread->Kill(true);
		delete this->RunnableThread;
	}
}

bool FHTTP_Thread_LibHv::Init()
{
	return this->Callback_HTTP_Start();
}

uint32 FHTTP_Thread_LibHv::Run()
{
	while (this->bStartThread)
	{
		
	}

	return 0;
}

void FHTTP_Thread_LibHv::Stop()
{
	this->Callback_HTTP_Stop();

	this->bStartThread = false;

	this->Parent_Actor->Delegate_HTTP_LibHv_Stop.Broadcast();
	this->Parent_Actor->OnHttpAdvStop();
}

bool FHTTP_Thread_LibHv::Toggle(bool bIsPause)
{
	if (!this->RunnableThread)
	{
		return false;
	}

	this->RunnableThread->Suspend(bIsPause);

	return true;
}