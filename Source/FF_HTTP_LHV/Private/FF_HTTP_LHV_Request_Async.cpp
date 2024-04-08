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

bool UHttpConnectionLhv::GetClientAddress(FString& Out_Ip, int32& Out_Port)
{
#ifdef _WIN64

	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	Out_Ip = this->RequestPtr->get()->client_addr.ip.c_str();
	Out_Port = this->RequestPtr->get()->client_addr.port;

	return true;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetQuerries(TMap<FString, FString>& Out_Querry, FString& Out_String)
{
#ifdef _WIN64

	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	const hv::QueryParams Querries = this->RequestPtr->get()->query_params;
	
	const size_t Count_Querries = Querries.size();
	int Index_Header = 0;

	for (auto& Each_Querry : Querries)
	{
		FString Key = Each_Querry.first.c_str();
		FString Value = Each_Querry.second.c_str();

		Out_Querry.Add(Key, Value);

		if (Index_Header == (Count_Querries - 1))
		{
			Out_String += Key + ":" + Value;
		}

		else
		{
			Out_String += Key + ":" + Value + "&";
			Index_Header++;
		}
	}

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

	const std::string Body = this->RequestPtr->get()->body;

	if (Body.empty())
	{
		return false;
	}

	Out_Body = Body.c_str();
	Out_BodySize = Body.size();

	return true;
#else
	return false;
#endif
}

bool UHttpConnectionLhv::GetPaths(FString& Out_Method, FString& Out_Scheme, FString& Out_Host, int32& Out_Port, FString& Out_Path, FString& Out_Url)
{
#ifdef _WIN64
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	if (!this->RequestPtr->get()->scheme.empty())
	{
		Out_Scheme = this->RequestPtr->get()->scheme.c_str();
	}

	if (!this->RequestPtr->get()->host.empty())
	{
		Out_Host = this->RequestPtr->get()->host.c_str();
	}

	if (!this->RequestPtr->get()->path.empty())
	{
		Out_Path = this->RequestPtr->get()->path.c_str();
	}

	if (!this->RequestPtr->get()->url.empty())
	{
		Out_Url = this->RequestPtr->get()->url.c_str();
	}

	this->Callback_Type_Method(this->RequestPtr->get()->method, Out_Method);
	Out_Port = this->RequestPtr->get()->port;

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

	const http_headers Headers = this->RequestPtr->get()->headers;
	
	const size_t Count_Headers = Headers.size();
	int Index_Header = 0;

	for (auto& Each_Header : Headers)
	{
		FString Key = Each_Header.first.c_str();
		FString Value = Each_Header.second.c_str();

		Out_Headers.Add(Key, Value);

		if (Index_Header == (Count_Headers - 1))
		{
			Out_String += Key + ":" + Value;
		}

		else
		{
			Out_String += Key + ":" + Value + LINE_TERMINATOR_ANSI;
			Index_Header++;
		}
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

	const http_headers Headers = this->RequestPtr->get()->headers;

	if (Headers.size() == 0)
	{
		return false;
	}

	if (!Headers.contains(TCHAR_TO_UTF8(*Key)))
	{
		return false;
	}
	
	const std::string Value = Headers.at(TCHAR_TO_UTF8(*Key));

	if (Value.empty())
	{
		return false;
	}
	
	Out_Value = Value.c_str();

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

	return this->Callback_Content_Type(this->RequestPtr->get()->content_type, Out_Content_Type, Out_Type_String);

#else
	return false;
#endif
}

bool UHttpConnectionLhv::SendString(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode)
{
#ifdef _WIN64

	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	HttpResponse TempResponse;
	TempResponse.String(TCHAR_TO_UTF8(*In_Response));

	for (TPair<FString, FString>& EachHeader : In_Header)
	{
		TempResponse.SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	int ReturnValue = 0;
	ReturnValue = ResponsePtr->get()->Begin();
	ReturnValue = ResponsePtr->get()->WriteResponse(&TempResponse);
	ReturnValue = ResponsePtr->get()->End();

	return (ReturnValue == 0) ? true : false;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::SendData(TArray<uint8> In_Bytes, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, bool bNoCopy)
{
#ifdef _WIN64

	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	HttpResponse TempResponse;
	TempResponse.Data(In_Bytes.GetData(), In_Bytes.Num(), bNoCopy);

	for (TPair<FString, FString>& EachHeader : In_Header)
	{
		TempResponse.SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	int ReturnValue = 0;
	ReturnValue = ResponsePtr->get()->Begin();
	ReturnValue = ResponsePtr->get()->WriteResponse(&TempResponse);
	ReturnValue = ResponsePtr->get()->End();

	return (ReturnValue == 0) ? true : false;

#else
	return false;
#endif
}

bool UHttpConnectionLhv::SendResponse(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, ELibHvContentTypes ContentTypes)
{
#ifdef _WIN64

	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	HttpResponse TempResponse;
	TempResponse.SetContentType(this->Callback_Content_Type_Convert(ContentTypes));
	TempResponse.SetBody(TCHAR_TO_UTF8(*In_Response));
	
	for (TPair<FString, FString>& EachHeader : In_Header)
	{
		TempResponse.SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
	}

	int ReturnValue = 0;
	ReturnValue = ResponsePtr->get()->Begin();
	ReturnValue = ResponsePtr->get()->WriteResponse(&TempResponse);
	ReturnValue = ResponsePtr->get()->End();

	return (ReturnValue == 0) ? true : false;

#else
	return false;
#endif
}

#endif