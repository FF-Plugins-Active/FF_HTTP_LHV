// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_LHV_Thread.h"
#include "FF_HTTP_LHV_Request.h"

#include "FF_HTTP_LHV_Server.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate_LibHv);

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

	// FUNCTIONS

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server LibHv - Start"), Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server LibHv - Stop"), Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server LibHv - Toggle"), Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool HTTP_Server_Toggle(bool bIsPause);

	// EVENTS

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|LibHv")
	void OnHttpAdvStart();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|LibHv")
	void OnHttpAdvStop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|LibHv")
	void OnHttpAdvMessage(UHttpConnectionLhv* Connection);

	// DELEGATES

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|LibHv")
	FDelegate_LibHv Delegate_HTTP_LibHv_Start;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|LibHv")
	FDelegate_LibHv Delegate_HTTP_LibHv_Stop;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|LibHv")
	FDelegate_LibHv_Request Delegate_HTTP_LivHv_Request;

	// PROPERTIES
	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	uint8 ThreadsNum = 4;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString API_URI = "/api/libhv/v1/";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|LibHv")
	FString Server_Name = "";

};