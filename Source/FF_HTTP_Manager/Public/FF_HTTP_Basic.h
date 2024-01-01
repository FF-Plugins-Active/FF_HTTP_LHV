// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Custom Includes.
#include "FF_HTTP_ManagerBPLibrary.h"

// UE Server Includes.
#include "IHttpRouter.h"
#include "HttpResultCallback.h"

#include "FF_HTTP_Basic.generated.h"

/*
* 
* Add these lines to Project/Config/DefaultEngine.ini
	[HTTPServer.Listeners]
	DefaultBindAddress = 0.0.0.0
*/

UCLASS(BlueprintType)
class FF_HTTP_MANAGER_API UHttpServerBasicResponse : public UObject
{
	GENERATED_BODY()

public:

	FHttpResultCallback Response;

	UFUNCTION(BlueprintCallable)
	virtual bool SendResponse(TMap<FString, FStringArrayStruct> In_Headers, FString In_Value, bool bAddAllowOrigin = true, FString ValueType = "text/html")
	{
		TMap<FString, FStringArrayStruct> TempHeaders = In_Headers;

		if (bAddAllowOrigin)
		{
			TArray<FString> AllowOriginHeaderValue;
			AllowOriginHeaderValue.Add("*");

			FStringArrayStruct StrAllowOriginHeaderValue;
			StrAllowOriginHeaderValue.Array_String = AllowOriginHeaderValue;
			TempHeaders.Add("Access-Control-Allow-Origin", StrAllowOriginHeaderValue);
		}

		TMap<FString, TArray<FString>> Headers;

		TArray<FString> Keys;
		TempHeaders.GenerateKeyArray(Keys);
		for (int32 Index_Elems = 0; Index_Elems < Keys.Num(); Index_Elems++)
		{
			Headers.Add(Keys[Index_Elems], TempHeaders.Find(Keys[Index_Elems])->Array_String);
		}

		TUniquePtr<FHttpServerResponse> TempResponse = FHttpServerResponse::Create(In_Value, ValueType);
		TempResponse->Headers = Headers;

		this->Response(MoveTemp(TempResponse));

		return true;
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateHttpMessageBasic, UHttpServerBasicResponse*, Connection, FHttpServerMessage, Request);

UCLASS()
class FF_HTTP_MANAGER_API AHTTP_Server_Basic : public AActor
{
	GENERATED_BODY()
	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	TSharedPtr<IHttpRouter, ESPMode::ThreadSafe> httpRouter = nullptr;
	TArray<FHttpRouteHandle> Array_Routes;

public:	

	// Sets default values for this actor's properties
	AHTTP_Server_Basic();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP Server|Basic")
	int32 Port = 8081;

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP Server|Basic")
	FDelegateHttpMessageBasic DelegateHttpMessageBasic;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Basic - Start", Category = "Frozen Forest|HTTP Server|Basic"))
	virtual void HttpServer_Basic_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server Basic - Stop", Category = "Frozen Forest|HTTP Server|Basic"))
	virtual bool HttpServer_Basic_Stop();

};