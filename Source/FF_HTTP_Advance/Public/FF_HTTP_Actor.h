// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_AdvanceBPLibrary.h"

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

#ifdef _WIN64

	// Add server variables to here.

#endif

	UPROPERTY(BlueprintReadOnly)
	EHttpServers ServerLibrary = EHttpServers::Server_Oatpp;

	UFUNCTION(BlueprintCallable)
	virtual void SendResponse(FString Response, const TMap<FString, FString> In_Header, bool bAddAllowOrigin = true, int32 Status_Code = 200)
	{
		#ifdef _WIN64

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

		#endif
	}
};

USTRUCT(BlueprintType)
struct FF_HTTP_ADVANCE_API FHttpAdvanceMessage
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	UHttpAdvanceConnection* Connection;

	UPROPERTY(BlueprintReadOnly)
	FString Body;

	UPROPERTY(BlueprintReadOnly)
	FString Head;

	UPROPERTY(BlueprintReadOnly)
	TMap<FString, FString> Headers;

	UPROPERTY(BlueprintReadOnly)
	FString Message;

	UPROPERTY(BlueprintReadOnly)
	FString Method;

	UPROPERTY(BlueprintReadOnly)
	FString Proto;

	UPROPERTY(BlueprintReadOnly)
	FString Query;

	UPROPERTY(BlueprintReadOnly)
	FString Uri;

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateHttpAdvMessage, FHttpAdvanceMessage, Out_Message);

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
	void OnHttpAdvMessage(const FHttpAdvanceMessage Out_Message);

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP Server|Advance")
	FDelegateHttpAdvMessage DelegateHttpAdvanceMessage;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Address_HTTP = "http://0.0.0.0:8081";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Address_HTTPS = "http://0.0.0.0:8081";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "If you want to change API parameter, just put /* to the end. If you don't do that, server won't detect dynamic API requests.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString API_URI = "api/*";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Advance")
	FString Server_Name = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"))
	EHttpServers ServerLibrary = EHttpServers::Server_Oatpp;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Start"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Stop"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Advance - Toggle"), Category = "Frozen Forest|HTTP Server|Advance")
	virtual void HTTP_Server_Toggle(bool bPause);

};