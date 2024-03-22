// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#include "Libwebsockets.h"
#endif
THIRD_PARTY_INCLUDES_END

// Fordward Declerations.
class FRunnableThread;
class AHTTP_Server_Advance;

class FHTTP_Thread_LibWebSocket : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_LibWebSocket(AHTTP_Server_Advance* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_LibWebSocket() override;

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual void Toggle(bool bIsPause);

private:

	virtual void Callback_HTTP_Start();

	int32 Port_HTTP = 8081;
	int32 Port_HTTPS = 8443;

	FString Server_Address_HTTPS = "";
	FString Server_Address_HTTP = "";
	FString Server_Path_Root = "";
	FString API_URI = "";

	lws_context_creation_info Server_Info;
	TArray<lws_protocols> Server_Protocols;
	lws_context* Server_Context;

	FCriticalSection DataGuard;

private:

	FRunnableThread* RunnableThread = nullptr;
	AHTTP_Server_Advance* Parent_Actor = nullptr;
	bool bStartThread = false;

};