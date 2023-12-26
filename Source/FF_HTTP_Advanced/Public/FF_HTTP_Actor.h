// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes
#include "HTTP_Server_Enums.h"

#include "FF_HTTP_Actor.generated.h"

UCLASS()
class FF_HTTP_ADVANCED_API AFF_HTTP_Actor : public AActor
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Oatpp")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Oatpp")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Oatpp")
	FString Server_Address_HTTP = "http://0.0.0.0:8081";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Oatpp")
	FString Server_Address_HTTPS = "http://0.0.0.0:8081";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "If you want to change API parameter, just put /* to the end. If you don't do that, server won't detect dynamic API requests.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Oatpp")
	FString API_URI = "api/*";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Oatpp")
	FString Server_Name = "";

	UPROPERTY(BlueprintReadOnly)
	EHttpServers ServerLibrary = EHttpServers::Server_Oatpp;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Oatpp HTTP Async - Start"), Category = "Frozen Forest|HTTP Server|Oatpp")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Oatpp HTTP Async - Stop"), Category = "Frozen Forest|HTTP Server|Oatpp")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Oatpp HTTP Async - Toggle"), Category = "Frozen Forest|HTTP Server|Oatpp")
	virtual void HTTP_Server_Toggle(bool bPause);

};
