// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

// Custom Includes
#include "FF_HTTP_Enums.h"

#include "FF_HTTP_ManagerBPLibrary.generated.h"

USTRUCT(BlueprintType)
struct FF_HTTP_MANAGER_API FStringArrayStruct
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> Array_String;

};

USTRUCT(BlueprintType)
struct FF_HTTP_MANAGER_API FHttpServerMessage
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	TArray<uint8> Body;

	UPROPERTY(BlueprintReadOnly)
	TMap<FString, FString> Query;

	UPROPERTY(BlueprintReadOnly)
	TMap<FString, FStringArrayStruct> Headers;

	UPROPERTY(BlueprintReadOnly)
	FString Head;

	UPROPERTY(BlueprintReadOnly)
	FString Message;

	UPROPERTY(BlueprintReadOnly)
	FString Method;

	UPROPERTY(BlueprintReadOnly)
	FString Proto;

	UPROPERTY(BlueprintReadOnly)
	FString RelativePath;

	/** UE Basic Server Only */
	UPROPERTY(BlueprintReadOnly)
	FString PeerAddress;

	/** UE Basic Server Only */
	UPROPERTY(BlueprintReadOnly)
	TMap<FString, FString> Path_Params;

};

USTRUCT(BlueprintType)
struct FF_HTTP_MANAGER_API FHttpClientResponse
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	TArray<uint8> Content;

	UPROPERTY(BlueprintReadOnly)
	FString ContentString;

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> Headers;

	UPROPERTY(BlueprintReadOnly)
	int64 ContentLenght = 0;

	UPROPERTY(BlueprintReadOnly)
	FString ContentType;

	UPROPERTY(BlueprintReadOnly)
	FString Url;

	UPROPERTY(BlueprintReadOnly)
	int32 ResponseCode = 0;

};

USTRUCT(BlueprintType)
struct FF_HTTP_MANAGER_API FMailAttachments
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	FString Attachment_Name;

	UPROPERTY(BlueprintReadWrite)
	TArray<uint8> Base64_Bytes;

};

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateHttpClient, bool, bIsSuccessfull, FHttpClientResponse, ResponseStruct);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDelegateMailSent, bool, bIsSuccessfull, FString, Out_Code);

UCLASS()
class UFF_HTTP_ManagerBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/*
	* @param bAddDefaultHeaders It adds these headers "Cache-Control: no-cache & Accept:"*"/"*" & Accept-Encoding:gzip, deflate, br & Connection:keep-alive
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Client Basic (Content as Bytes)", Keywords = "http, web, url, post"), Category = "Frozen Forest|HTTP Client|Basic")
	static FF_HTTP_MANAGER_API void FF_HTTP_Client_Basic_Bytes(FDelegateHttpClient DelegateClient, FString In_Url, TMap<FString, FString> In_Header, TArray<uint8> In_Body, EHttpRequestTypes In_Request_Type = EHttpRequestTypes::GET, EHttpContentTypes ContentType = EHttpContentTypes::PDF, bool bAddDefaultHeaders = true);

	/*
	* @param bAddDefaultHeaders It adds these headers "Cache-Control: no-cache & Accept:"*"/"*" & Accept-Encoding:gzip, deflate, br & Connection:keep-alive
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Client Basic (Content as String)", Keywords = "http, web, url, post"), Category = "Frozen Forest|HTTP Client|Basic")
	static FF_HTTP_MANAGER_API void FF_HTTP_Client_Basic_String(FDelegateHttpClient DelegateClient, FString In_Url, TMap<FString, FString> In_Header, FString In_Body, EHttpRequestTypes In_Request_Type = EHttpRequestTypes::GET, EHttpContentTypes ContentType = EHttpContentTypes::PDF, bool bAddDefaultHeaders = true);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "HTTP Server - Response Lenght", Keywords = "http, server, response, helper, content, lenght"), Category = "Frozen Forest|HTTP Server")
	static FF_HTTP_MANAGER_API bool HTTP_Server_Response_Lenght(FString& Out_Lenght, FString In_Response);

	/*
	* @param Attachments LibCurl automatically converts bytes to base64.
	* @param CustomServerSecurity You don't have to define it if you won't use CustomServer.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LibCurl - Send Email", Keywords = "libcurl, curl, send, email, mail, smtp"), Category = "Frozen Forest|LibCurl|Mail")
	static FF_HTTP_MANAGER_API void LibCurl_Send_Email(FDelegateMailSent DelegateMailSent, TArray<FMailAttachments> Attachments, TArray<FString> To, TArray<FString> Cc, TArray<FString> Bcc, FString Subject, FString Message, FString Sender, FString Password, FString CustomServer, FString In_Cert_Path, EMailServers KnownServers = EMailServers::Gmail, EMailSecurity CustomServerSecurity = EMailSecurity::NoSecurity);

};