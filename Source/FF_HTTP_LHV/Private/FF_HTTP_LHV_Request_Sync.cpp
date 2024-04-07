#include "FF_HTTP_LHV_Request.h"

#if (LHV_USE_ASYNC_HANDLER == 0)

bool UHttpConnectionLhv::CancelRequest()
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	this->Request->Cancel();

	return true;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetBody(FString& Out_Body, int32& Out_BodySize)
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	if (this->Request->body.empty())
	{
		return false;
	}

	Out_Body = this->Request->body.c_str();
	Out_BodySize = this->Request->body.size();

	return true;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetPath(FString& Out_Path)
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	if (this->Request->path.empty())
	{
		return false;
	}

	Out_Path = this->Request->path.c_str();

	return true;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetHeaders(TMap<FString, FString>& Out_Headers, FString& Out_String)
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	http_headers Headers = this->Request->headers;

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

	if (this->Request == nullptr)
	{
		return false;
	}

	if (Key.IsEmpty())
	{
		return false;
	}

	Out_Value = this->Request->GetHeader(TCHAR_TO_UTF8(*Key), (std::string)("")).c_str();

	return true;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetContentType(ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String)
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	return this->Callback_ContentType(this->Request->content_type, Out_Content_Type, Out_Type_String);

#else
	return false;
#endif
}

bool UHttpConnectionLhv::SendString(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode)
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	for (TPair<FString, FString>& EachHeader : In_Header)
	{
		Response->SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	Response->String(TCHAR_TO_UTF8(*In_Response));

	TPromise<int> Promise;
	Promise.SetValue(UFF_HTTP_LHVBPLibrary::LibHv_Status_To_Int(StatusCode));
	this->Future = Promise.GetFuture();

	return true;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::SendData(TArray<uint8> In_Bytes, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, bool bNoCopy)
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	for (TPair<FString, FString>& EachHeader : In_Header)
	{
		Response->SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	Response->Data(In_Bytes.GetData(), In_Bytes.Num(), bNoCopy);

	TPromise<int> Promise;
	Promise.SetValue(UFF_HTTP_LHVBPLibrary::LibHv_Status_To_Int(StatusCode));
	this->Future = Promise.GetFuture();

	return true;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::SendResponse(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, ELibHvContentTypes ContentTypes)
{
#ifdef _WIN64

	if (this->Request == nullptr)
	{
		return false;
	}

	for (TPair<FString, FString>& EachHeader : In_Header)
	{
		Response->SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	Response->SetContentType(UFF_HTTP_LHVBPLibrary::LibHv_Type_Bp_To_Original(ContentTypes));
	Response->SetBody(TCHAR_TO_UTF8(*In_Response));

	TPromise<int> Promise;
	Promise.SetValue(UFF_HTTP_LHVBPLibrary::LibHv_Status_To_Int(StatusCode));
	this->Future = Promise.GetFuture();

	return true;
#else
	return false;
#endif
}

#endif