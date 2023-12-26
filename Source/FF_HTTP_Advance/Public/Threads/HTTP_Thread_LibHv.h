// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START
#include "hv/HttpServer.h"
THIRD_PARTY_INCLUDES_END

// Fordward Declerations.
class FRunnableThread;
class AFF_HTTP_Actor;

class FHTTP_Thread_LibHv : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_LibHv(AFF_HTTP_Actor* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_LibHv() override;

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual void Toggle(bool bIsPause);

private:

	virtual void Callback_HTTP_Start();

	FString Server_Address_HTTPS = "";
	FString Server_Address_HTTP = "";
	FString Server_Path_Root = "";
	FString API_URI = "";

private:

	FRunnableThread* RunnableThread = nullptr;
	AFF_HTTP_Actor* Parent_Actor = nullptr;

};
