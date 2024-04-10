#pragma once

#include "CoreMinimal.h"

// Custom Includes.
#include "FF_HTTP_LHV_Enums.h"

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#include "hv/HttpServer.h"
#include "hv/hthread.h"    // import hv_gettid
#include "hv/hasync.h"     // import hv::async
#include "hv/requests.h"   // import requests::async
#endif
THIRD_PARTY_INCLUDES_END

#include "FF_HTTP_LHV_Request.generated.h"

// 0 = Handler Sync
// 1 = Handler Async
// 2 = Handler Context
#define LHV_HANDLER_TYPE 1

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegate_LibHv_Request, UHttpConnectionLhv*, Connection);

UCLASS(BlueprintType)
class FF_HTTP_LHV_API UHttpConnectionLhv : public UObject
{
	GENERATED_BODY()

private:

	// Method.

	virtual bool Callback_Type_Method(http_method Type, FString& Out_Type_String);

	// Content.

	virtual bool Callback_Content_Type(http_content_type Type, ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String);
	virtual http_content_type Callback_Content_Type_Convert(ELibHvContentTypes Type);

	// Status.
		
	virtual int32 Callback_Status_To_Code(ELibHvStatusCodes Status);
	virtual http_status Callback_Code_To_Status(int Status);

public:

#if (LHV_HANDLER_TYPE == 0)

	TSharedFuture<int> Future;
	HttpRequest* Request = nullptr;
	HttpResponse* Response = nullptr;

#elif (LHV_HANDLER_TYPE == 1)

	const HttpRequestPtr* RequestPtr = nullptr;
	const HttpResponseWriterPtr* ResponsePtr = nullptr;

#elif (LHV_HANDLER_TYPE == 2)
	
	TSharedFuture<int> Future;
	const HttpContextPtr* Context = nullptr;

#endif

	UPROPERTY(BlueprintReadOnly)
	FDateTime RequestTime;

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool CancelRequest();

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetClientAddress(FString& Out_Ip, int32& Out_Port);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetQuerries(TMap<FString, FString>& Out_Querry, FString& Out_String);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetBody(FString& Out_Body, int32& Out_BodySize);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetPaths(FString& Out_Method, FString& Out_Scheme, FString& Out_Host, int32& Out_Port, FString& Out_Path, FString& Out_Url);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetHeaders(TMap<FString, FString>& Out_Headers, FString& Out_String);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool FindHeader(FString Key, FString& Out_Value);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetContentType(ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool SendString(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode = ELibHvStatusCodes::OK_200);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool SendData(TArray<uint8> In_Bytes, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode = ELibHvStatusCodes::OK_200, bool bNoCopy = false);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool SendResponse(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode = ELibHvStatusCodes::OK_200, ELibHvContentTypes ContentTypes = ELibHvContentTypes::Text_Plain);

};