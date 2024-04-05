// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_LHV_Enums.h"
#include "FF_HTTP_LHV_Thread.h"

#include "FF_HTTP_LHV_Server.generated.h"

UCLASS(BlueprintType)
class FF_HTTP_LHV_API UHttpConnectionLhv : public UObject
{
	GENERATED_BODY()

public:

	TSharedFuture<int> Future;
	HttpRequest* Request = nullptr; 
	HttpResponse* Response = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool CancelRequest();

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetBody(FString& Out_Body, int32& Out_BodySize);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetPath(FString& Out_Path);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetHeaders(FString& Out_Headers);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool FindHeader(FString Key, FString& Out_Value);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetContentType(EHttpContentTypeLhv& Out_Content_Type);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool SendResponse(const FString In_Response, TMap<FString, FString> In_Header, const bool bAddAllowOrigin = true, const int32 Status_Code = 200);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateLibHv, UHttpConnectionLhv*, Connection);

UCLASS()
class FF_HTTP_LHV_API AHTTP_Server_LHV : public AActor
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called when the game ends or when destroyed.
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	

	// Sets default values for this actor's properties.
	AHTTP_Server_LHV();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

#ifdef _WIN64
	
	class FHTTP_Thread_LibHv* Thread_LibHv = nullptr;

#endif

public:

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|LibHv")
	void OnHttpAdvStart();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|LibHv")
	void OnHttpAdvStop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|LibHv")
	void OnHttpAdvMessage(UHttpConnectionLhv* Connection);

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|LibHv")
	FDelegateLibHv DelegateHttpLibHv;

public:

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString API_URI = "/api/libhv/v1/";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString Server_Name = "";

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server LibHv - Start"), Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server LibHv - Stop"), Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server LibHv - Toggle"), Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool HTTP_Server_Toggle(bool bIsPause);

};