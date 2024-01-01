// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_ManagerBPLibrary.h"

// Threads.
#include "Threads/HTTP_Thread_Oatpp.h"
#include "Threads/HTTP_Thread_Workflow.h"
#include "Threads/HTTP_Thread_LibHv.h"
#include "Threads/HTTP_Thread_IXWeb.h"

#include "FF_HTTP_Advance.generated.h"

UCLASS()
class FF_HTTP_MANAGER_API UHttpAdvanceConnection : public UObject
{
	GENERATED_BODY()

public:

	// Define this in server's FRunnableThread.
	void* ConnectionPointer;

	UPROPERTY()
	EHttpServers ServerLibrary = EHttpServers::Server_Oatpp;

private:

	virtual bool SendResponse_Oatpp(const FString In_Response, const TMap<FString, FStringArrayStruct> In_Header, const bool bAddAllowOrigin, int32 Status_Code, FString ValueType)
	{
#ifdef _WIN64
		if (!this->ConnectionPointer)
		{
			return false;
		}

		return true;

#else
		return false;
#endif
	}

	virtual bool SendResponse_Workflow(const FString In_Response, const TMap<FString, FStringArrayStruct> In_Header, const bool bAddAllowOrigin, int32 Status_Code, FString ValueType)
	{
#ifdef _WIN64
		if (!this->ConnectionPointer)
		{
			return false;
		}

		return true;

#else
		return false;
#endif
	}

	virtual bool SendResponse_LibHv(const FString In_Response, const TMap<FString, FStringArrayStruct> In_Header, const bool bAddAllowOrigin, int32 Status_Code, FString ValueType)
	{
		if (!this->ConnectionPointer)
		{
			return false;
		}

#ifdef _WIN64
		HttpResponse* Response = (HttpResponse*)this->ConnectionPointer;
		Response->String("Test");

		return true;
#else

		return false;
#endif
	}

	virtual bool SendResponse_IxWebSocket(const FString In_Response, const TMap<FString, FStringArrayStruct> In_Header, const bool bAddAllowOrigin, int32 Status_Code, FString ValueType)
	{
#ifdef _WIN64
		if (!this->ConnectionPointer)
		{
			return false;
		}

		return true;

#else
		return false;
#endif
	}

public:

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse(const FString In_Response, TMap<FString, FStringArrayStruct> In_Header, const bool bAddAllowOrigin = true, int32 Status_Code = 200, FString ValueType = "text/html")
	{
		switch (ServerLibrary)
		{
		
		case EHttpServers::Server_Oatpp:
			return this->SendResponse_Oatpp(In_Response, In_Header, bAddAllowOrigin, Status_Code, ValueType);

		case EHttpServers::Server_Workflow:
			return this->SendResponse_Workflow(In_Response, In_Header, bAddAllowOrigin, Status_Code, ValueType);

		case EHttpServers::Server_LibHv:
			return this->SendResponse_LibHv(In_Response, In_Header, bAddAllowOrigin, Status_Code, ValueType);

		case EHttpServers::Server_IxWebSocket:
			return this->SendResponse_IxWebSocket(In_Response, In_Header, bAddAllowOrigin, Status_Code, ValueType);

		default:
			return false;
		}
	}

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateHttpMessageAdv, UHttpAdvanceConnection*, Connection, FHttpServerMessage, Out_Message);

UCLASS()
class FF_HTTP_MANAGER_API AHTTP_Server_Advance : public AActor
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	

	// Sets default values for this actor's properties
	AHTTP_Server_Advance();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString ThreadName = "";

#ifdef _WIN64
	class FHTTP_Thread_IXWeb* Thread_IXWeb = nullptr;
	class FHTTP_Thread_LibHv* Thread_LibHv = nullptr;
	class FHTTP_Thread_Oatpp* Thread_Oatpp = nullptr;
	class FHTTP_Thread_Workflow* Thread_Workflow = nullptr;
#endif

public:

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP Server|Advance")
	void OnHttpAdvStart();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP Server|Advance")
	void OnHttpAdvStop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP Server|Advance")
	void OnHttpAdvMessage(const FHttpServerMessage Out_Message);

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP Server|Advance")
	FDelegateHttpMessageAdv DelegateHttpMessageAdv;

public:

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "If you want to change API parameter, just put /* to the end. If you don't do that, server won't detect dynamic API requests.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString API_URI = "api/*";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Name = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"))
	EHttpServers ServerLibrary = EHttpServers::Server_Oatpp;

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Start"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Stop"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Toggle"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual void HTTP_Server_Toggle(bool bPause);

};