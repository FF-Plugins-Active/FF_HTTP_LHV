// Fill out your copyright notice in the Description page of Project Settings.

#include "Threads/HTTP_Thread_Oatpp.h"
#include "FF_HTTP_Actor.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_Oatpp::FHTTP_Thread_Oatpp(AFF_HTTP_Actor* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Server_Address_HTTP = this->Parent_Actor->Server_Address_HTTP;
	this->Server_Address_HTTPS = this->Parent_Actor->Server_Address_HTTPS;
}

FHTTP_Thread_Oatpp::~FHTTP_Thread_Oatpp()
{

}

bool FHTTP_Thread_Oatpp::Init()
{
	return true;
}

uint32 FHTTP_Thread_Oatpp::Run()
{
	return 0;
}

void FHTTP_Thread_Oatpp::Stop()
{

}

void FHTTP_Thread_Oatpp::Toggle(bool bIsPause)
{

}

void FHTTP_Thread_Oatpp::Callback_HTTP_Start()
{

}