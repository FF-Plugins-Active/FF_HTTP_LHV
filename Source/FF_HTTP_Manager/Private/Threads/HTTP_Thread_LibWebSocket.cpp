// Fill out your copyright notice in the Description page of Project Settings.

#include "Threads/HTTP_Thread_LibWebSocket.h"
#include "FF_HTTP_Advance.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_LibWebSocket::FHTTP_Thread_LibWebSocket(AHTTP_Server_Advance* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Server_Address_HTTP = "http://0.0.0.0:" + FString::FromInt(this->Parent_Actor->Port_HTTP);
	this->Server_Address_HTTPS = "https://0.0.0.0:" + FString::FromInt(this->Parent_Actor->Port_HTTPS);
}

FHTTP_Thread_LibWebSocket::~FHTTP_Thread_LibWebSocket()
{

}

bool FHTTP_Thread_LibWebSocket::Init()
{
	return true;
}

uint32 FHTTP_Thread_LibWebSocket::Run()
{
	return 0;
}

void FHTTP_Thread_LibWebSocket::Stop()
{

}

void FHTTP_Thread_LibWebSocket::Toggle(bool bIsPause)
{

}

void FHTTP_Thread_LibWebSocket::Callback_HTTP_Start()
{

}