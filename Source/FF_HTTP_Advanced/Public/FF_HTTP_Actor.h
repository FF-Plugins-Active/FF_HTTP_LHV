// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "HTTP_Server_Enums.h"

// Threads.
#include "Threads/HTTP_Thread_Oatpp.h"
#include "Threads/HTTP_Thread_Workflow.h"
#include "Threads/HTTP_Thread_LibHv.h"
#include "Threads/HTTP_Thread_IXWeb.h"

#include "FF_HTTP_Actor.generated.h"

UCLASS()
class FF_HTTP_ADVANCE_API UHttpAdvanceConnection : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	EHttpServers ServerLibrary = EHttpServers::Server_Oatpp;

	UFUNCTION(BlueprintCallable)
	virtual void SendResponse(FString Response, TMap<FString, FString> In_Header, bool bAddAllowOrigin = true, int32 Status_Code = 200)
	{
		switch (this->ServerLibrary)
		{
		case EHttpServers::Server_Oatpp:
			break;

		case EHttpServers::Server_Workflow:
			break;

		case EHttpServers::Server_LibHv:
			break;

		case EHttpServers::Server_IxWebSocket:
			break;
		default:
			break;
		}
	}
};

UCLASS(BlueprintType)
class FF_HTTP_ADVANCE_API UHttpAdvanceMessage : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	UHttpAdvanceConnection* Connection;

	UPROPERTY(BlueprintReadWrite)
	FString Body;

	UPROPERTY(BlueprintReadWrite)
	FString Head;

	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FString> Headers;

	UPROPERTY(BlueprintReadWrite)
	FString Message;

	UPROPERTY(BlueprintReadWrite)
	FString Method;

	UPROPERTY(BlueprintReadWrite)
	FString Proto;

	UPROPERTY(BlueprintReadWrite)
	FString Query;

	UPROPERTY(BlueprintReadWrite)
	FString Uri;

};

UCLASS()
class FF_HTTP_ADVANCE_API AFF_HTTP_Actor : public AActor
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	

	// Sets default values for this actor's properties
	AFF_HTTP_Actor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class FHTTP_Server_Oatpp_Thread* Oatpp_Thread = nullptr;
	FString ThreadName = "";

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Address_HTTP = "http://0.0.0.0:8081";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Address_HTTPS = "http://0.0.0.0:8081";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "If you want to change API parameter, just put /* to the end. If you don't do that, server won't detect dynamic API requests.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString API_URI = "api/*";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Name = "";

	UPROPERTY(BlueprintReadOnly)
	EHttpServers ServerLibrary = EHttpServers::Server_Oatpp;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Start"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Stop"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Toggle"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual void HTTP_Server_Toggle(bool bPause);

};