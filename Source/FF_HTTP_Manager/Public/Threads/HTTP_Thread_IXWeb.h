// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#include <ixwebsocket/IXHttpServer.h>
#endif
THIRD_PARTY_INCLUDES_END

// Fordward Declerations.
class FRunnableThread;
class AHTTP_Server_Advance;

class FHTTP_Thread_IXWeb : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_IXWeb(AHTTP_Server_Advance* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_IXWeb() override;

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
	AHTTP_Server_Advance* Parent_Actor = nullptr;

};
