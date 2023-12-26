// Fill out your copyright notice in the Description page of Project Settings.

#include "Threads/HTTP_Thread_IXWeb.h"
#include "FF_HTTP_Actor.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_IXWeb::FHTTP_Thread_IXWeb(AFF_HTTP_Actor* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Server_Address_HTTP = this->Parent_Actor->Server_Address_HTTP;
	this->Server_Address_HTTPS = this->Parent_Actor->Server_Address_HTTPS;
}

FHTTP_Thread_IXWeb::~FHTTP_Thread_IXWeb()
{

}

bool FHTTP_Thread_IXWeb::Init()
{
	return true;
}

uint32 FHTTP_Thread_IXWeb::Run()
{
	return 0;
}

void FHTTP_Thread_IXWeb::Stop()
{

}

void FHTTP_Thread_IXWeb::Toggle(bool bIsPause)
{

}

void FHTTP_Thread_IXWeb::Callback_HTTP_Start()
{

}