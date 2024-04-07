#include "FF_HTTP_LHV_Request.h"

#if (LHV_USE_ASYNC_HANDLER == 1)

bool UHttpConnectionLhv::CancelRequest()
{
#ifdef _WIN64
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	this->RequestPtr->get()->Cancel();

	return true;
#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetBody(FString& Out_Body, int32& Out_BodySize)
{
#ifdef _WIN64
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	if (this->RequestPtr->get()->body.empty())
	{
		return false;
	}

	Out_Body = this->RequestPtr->get()->body.c_str();
	Out_BodySize = this->RequestPtr->get()->body.size();

	return true;
#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetPath(FString& Out_Path)
{
#ifdef _WIN64
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	if (this->RequestPtr->get()->path.empty())
	{
		return false;
	}

	Out_Path = this->RequestPtr->get()->path.c_str();

	return true;
#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetHeaders(TMap<FString, FString>& Out_Headers, FString& Out_String)
{
#ifdef _WIN64
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	http_headers Headers = this->RequestPtr->get()->headers;

	for (auto& Each_Header : Headers)
	{
		FString Key = Each_Header.first.c_str();
		FString Value = Each_Header.second.c_str();

		Out_String += Key + ":" + Value + LINE_TERMINATOR_ANSI;
		Out_Headers.Add(Key, Value);
	}

	return true;
#else
	return false;
#endif
}

bool UHttpConnectionLhv::FindHeader(FString Key, FString& Out_Value)
{
#ifdef _WIN64
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	if (Key.IsEmpty())
	{
		return false;
	}

	Out_Value = this->RequestPtr->get()->GetHeader(TCHAR_TO_UTF8(*Key), (std::string)("")).c_str();

	return true;
#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetContentType(ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String)
{
#ifdef _WIN64
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	return this->Callback_ContentType(this->RequestPtr->get()->content_type, Out_Content_Type, Out_Type_String);

#else
	return false;
#endif
}

bool UHttpConnectionLhv::SendString(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode)
{
	UE_LOG(LogTemp, Error, TEXT("LibHv - Pointer type response doesn't support \"Send String and Send Data\" nodes. Please use \"Send Response\" or disable pointer type."));
	return false;
}

bool UHttpConnectionLhv::SendData(TArray<uint8> In_Bytes, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, bool bNoCopy)
{
	UE_LOG(LogTemp, Error, TEXT("LibHv - Pointer type response doesn't support \"Send String and Send Data\" nodes. Please use \"Send Response\" or disable pointer type."));
	return false;
}

bool UHttpConnectionLhv::SendResponse(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, ELibHvContentTypes ContentTypes)
{
#ifdef _WIN64

	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	int ReturnValue = 0;

	ReturnValue = ResponsePtr->get()->Begin();

	for (TPair<FString, FString>& EachHeader : In_Header)
	{
		ResponsePtr->get()->WriteHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	ReturnValue = ResponsePtr->get()->WriteStatus(UFF_HTTP_LHVBPLibrary::LibHv_Int_To_Status(UFF_HTTP_LHVBPLibrary::LibHv_Status_To_Int(StatusCode)));
	ReturnValue = ResponsePtr->get()->WriteBody(TCHAR_TO_UTF8(*In_Response));
	ReturnValue = ResponsePtr->get()->End();

	return (ReturnValue == 0) ? false : true;

#else
	return false;
#endif
}

#endif