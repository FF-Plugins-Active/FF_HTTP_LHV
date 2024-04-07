#pragma once

#include "CoreMinimal.h"

// Custom Includes.
#include "FF_HTTP_LHV_Enums.h"
#include "FF_HTTP_LHVBPLibrary.h"

#include "FF_HTTP_LHV_Request.generated.h"

#define LHV_USE_ASYNC_HANDLER 0

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegate_LibHv_Request, UHttpConnectionLhv*, Connection);

UCLASS(BlueprintType)
class FF_HTTP_LHV_API UHttpConnectionLhv : public UObject
{
	GENERATED_BODY()

private:

	virtual bool Callback_ContentType(http_content_type Type, ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String);

public:

#if (LHV_USE_ASYNC_HANDLER == 0)

	TSharedFuture<int> Future;
	HttpRequest* Request = nullptr;
	HttpResponse* Response = nullptr;

#else

	const HttpRequestPtr* RequestPtr = nullptr;
	const HttpResponseWriterPtr* ResponsePtr = nullptr;

#endif

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool CancelRequest();

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetBody(FString& Out_Body, int32& Out_BodySize);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetPath(FString& Out_Path);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetHeaders(TMap<FString, FString>& Out_Headers, FString& Out_String);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool FindHeader(FString Key, FString& Out_Value);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool GetContentType(ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool SendString(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool SendData(TArray<uint8> In_Bytes, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, bool bNoCopy);

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|LibHv")
	virtual bool SendResponse(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode = ELibHvStatusCodes::OK_200, ELibHvContentTypes ContentTypes = ELibHvContentTypes::Text_Plain);

};