// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

// Custom Includes
#include "HTTP_Server_Enums.h"

#include "FF_HTTP_AdvanceBPLibrary.generated.h"

USTRUCT(BlueprintType)
struct FMailAttachments
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	FString Attachment_Name;

	UPROPERTY(BlueprintReadWrite)
	TArray<uint8> Base64_Bytes;

};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateHttpClient, bool, bIsSuccessfull, const TArray<uint8>&, Bytes);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateMailSent, bool, bIsSuccessfull, FString, Out_Code);

UCLASS()
class UFF_HTTP_AdvanceBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Client - Post", Keywords = "http, web, url, post"), Category = "Frozen Forest|HTTP Client|Basic")
	static void FF_HTTP_Post(FDelegateHttpClient DelegateClientPost, TArray<uint8> In_Array, FString In_URL, FString ContentType = "application/pdf");

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Client - Get", Keywords = "http, web, url, get"), Category = "Frozen Forest|HTTP Client|Basic")
	static void FF_HTTP_Get(FDelegateHttpClient DelegateClientGet, FString In_URL, FString ContentType = "application/pdf");

	UFUNCTION(BlueprintPure, meta = (DisplayName = "HTTP Server - Response Lenght", Keywords = "http, server, response, helper, content, lenght"), Category = "Frozen Forest|HTTP Server")
	static bool HTTP_Server_Response_Lenght(FString& Out_Lenght, FString In_Response);

	/*
	* @param Attachments LibCurl automatically converts bytes to base64.
	* @param CustomServerSecurity You don't have to define it if you won't use CustomServer.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LibCurl - Send Email", Keywords = "libcurl, curl, send, email, mail, smtp"), Category = "Frozen Forest|LibCurl|Mail")
	static void LibCurl_Send_Email(FDelegateMailSent DelegateMailSent, TArray<FMailAttachments> Attachments, TArray<FString> To, TArray<FString> Cc, TArray<FString> Bcc, FString Subject, FString Message, FString Sender, FString Password, FString CustomServer, FString In_Cert_Path, EMailServers KnownServers = EMailServers::Gmail, EMailSecurity CustomServerSecurity = EMailSecurity::NoSecurity);

};