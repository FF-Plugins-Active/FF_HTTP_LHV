// Fill out your copyright notice in the Description page of Project Settings.

#include "Threads/HTTP_Thread_LibHv.h"
#include "FF_HTTP_Actor.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_LibHv::FHTTP_Thread_LibHv(AFF_HTTP_Actor* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Server_Address_HTTP = "http://0.0.0.0:" + FString::FromInt(this->Parent_Actor->Port_HTTP);
	this->Server_Address_HTTPS = "https://0.0.0.0:" + FString::FromInt(this->Parent_Actor->Port_HTTPS);
}

FHTTP_Thread_LibHv::~FHTTP_Thread_LibHv()
{

}

bool FHTTP_Thread_LibHv::Init()
{
	return true;
}

uint32 FHTTP_Thread_LibHv::Run()
{
	return 0;
}

void FHTTP_Thread_LibHv::Stop()
{

}

void FHTTP_Thread_LibHv::Toggle(bool bIsPause)
{

}

void FHTTP_Thread_LibHv::Callback_HTTP_Start()
{

}