// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#include "hv/HttpServer.h"
#include "hv/hthread.h"    // import hv_gettid
#include "hv/hasync.h"     // import hv::async
#endif
THIRD_PARTY_INCLUDES_END

// Fordward Declerations.
class FRunnableThread;
class AHTTP_Server_LHV;

class FHTTP_Thread_LibHv : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_LibHv(AHTTP_Server_LHV* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_LibHv() override;

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual bool Toggle(bool bIsPause);

	AHTTP_Server_LHV* Parent_Actor = nullptr;

#ifdef _WIN64
	hv::HttpService HTTP_LVH_Router;
	hv::HttpServer HTTP_LVH_Server;
#endif

private:

	virtual bool Callback_HTTP_Start();

	int32 Port_HTTP = 8081;
	int32 Port_HTTPS = 8443;
	uint8 ThreadsNum = 4;

	FString Server_Path_Root = "";
	FString Server_Path_404;
	FString API_URI = "/api/libhv/v1/";

	FRunnableThread* RunnableThread = nullptr;
	bool bStartThread = false;

};