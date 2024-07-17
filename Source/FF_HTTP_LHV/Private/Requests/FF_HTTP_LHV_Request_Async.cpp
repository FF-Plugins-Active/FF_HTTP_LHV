#include "FF_HTTP_LHV_Request.h"

#if (LHV_HANDLER_TYPE == 1)

bool UHttpConnectionLhv::CancelRequest()
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	try
	{
		this->RequestPtr.get()->Cancel();
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	return true;
}

bool UHttpConnectionLhv::GetClientAddress(FString& Out_Ip, int32& Out_Port)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	try
	{
		Out_Ip = this->RequestPtr->client_addr.ip.c_str();
		Out_Port = this->RequestPtr->client_addr.port;
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	return true;
}

bool UHttpConnectionLhv::GetQueries(TMap<FString, FString>& Out_Query, FString& Out_String)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	TMap<FString, FString> Temp_Query;
	FString Query_String;
	
	try
	{
		const hv::QueryParams Queries = this->RequestPtr.get()->query_params;
		const size_t Count_Querries = Queries.size();
		int Index_Header = 0;

		for (const std::pair<const std::string, std::string>& Each_Query : Queries)
		{
			FString Key = Each_Query.first.c_str();
			FString Value = Each_Query.second.c_str();

			Temp_Query.Add(Key, Value);

			if (Index_Header == (Count_Querries - 1))
			{
				Query_String += Key + ":" + Value;
			}

			else
			{
				Query_String += Key + ":" + Value + "&";
				Index_Header++;
			}
		}
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}
	
	Out_Query = Temp_Query;
	Out_String = Query_String;

	return true;
}

bool UHttpConnectionLhv::FindQuery(FString& Value, FString Key)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	FString TempValue;

	try
	{
		const std::string RawString = this->RequestPtr->GetParam(TCHAR_TO_UTF8(*Key), std::string());

		if (RawString.empty())
		{
			return false;
		}

		TempValue = UTF8_TO_TCHAR(RawString.c_str());
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	Value = TempValue;
	return true;
}

bool UHttpConnectionLhv::GetBody(FString& Out_Body, int64& Out_BodySize)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	FString TempBody;
	size_t TempLenght = 0;

	try
	{
		const std::string RawString = this->RequestPtr->body;
		
		if (RawString.empty())
		{
			return false;
		}

		TempBody = UTF8_TO_TCHAR(RawString.c_str());
		TempLenght = RawString.size();
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	Out_Body = TempBody;
	Out_BodySize = (int64)TempLenght;

	return true;
}

bool UHttpConnectionLhv::GetPaths(FString& Out_Method, FString& Out_Scheme, FString& Out_Host, int32& Out_Port, FString& Out_Path, FString& Out_Url)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	try
	{
		Out_Port = this->RequestPtr->port;

		if (!this->RequestPtr->scheme.empty())
		{
			Out_Scheme = UTF8_TO_TCHAR(this->RequestPtr->scheme.c_str());
		}

		if (!this->RequestPtr->host.empty())
		{
			Out_Host = UTF8_TO_TCHAR(this->RequestPtr->host.c_str());
		}

		if (!this->RequestPtr->path.empty())
		{
			Out_Path = UTF8_TO_TCHAR(this->RequestPtr->path.c_str());
		}

		if (!this->RequestPtr->url.empty())
		{
			Out_Url = UTF8_TO_TCHAR(this->RequestPtr->url.c_str());
		}
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	Out_Method = this->Callback_Type_Method(this->RequestPtr->method);
	return true;
}

bool UHttpConnectionLhv::GetHeaders(TMap<FString, FString>& Out_Headers, FString& Out_String)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}
	
	FString Header_String;
	TMap<FString, FString> Temp_Headers;

	try
	{
		const http_headers Headers = this->RequestPtr->headers;
		const size_t Count_Headers = Headers.size();
		
		int Index_Header = 0;

		for (const std::pair<const std::string, std::string>& Each_Header : Headers)
		{
			const FString Key = UTF8_TO_TCHAR(Each_Header.first.c_str());
			const FString Value = UTF8_TO_TCHAR(Each_Header.second.c_str());

			Temp_Headers.Add(Key, Value);

			if (Index_Header == (Count_Headers - 1))
			{
				Header_String += Key + ":" + Value;
			}

			else
			{
				Header_String += Key + ":" + Value + LINE_TERMINATOR_ANSI;
				Index_Header++;
			}
		}
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	Out_Headers = Temp_Headers;
	Out_String = Header_String;

	return true;
}

bool UHttpConnectionLhv::FindHeader(FString Key, FString& Out_Value)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	if (Key.IsEmpty())
	{
		return false;
	}

	std::string Value;

	try
	{
		const http_headers Headers = this->RequestPtr->headers;

		if (Headers.size() == 0)
		{
			return false;
		}

		if (!Headers.contains(TCHAR_TO_UTF8(*Key)))
		{
			return false;
		}

		Value = Headers.at(TCHAR_TO_UTF8(*Key));

		if (Value.empty())
		{
			return false;
		}
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	Out_Value = UTF8_TO_TCHAR(Value.c_str());

	return true;
}

bool UHttpConnectionLhv::GetContentType(FString& Out_Type_String, ELibHvContentTypes& Out_Content_Type)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	this->Callback_Content_Type(Out_Content_Type, Out_Type_String, this->RequestPtr->content_type);
	return true;
}

bool UHttpConnectionLhv::GetContentLenght(int64& Out_Lenght)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	size_t ContentLeght = 0;

	try
	{
		ContentLeght = this->RequestPtr->content_length;
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	Out_Lenght = ContentLeght;
	return true;
}

bool UHttpConnectionLhv::SendString(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	int ReturnValue = 0;

	try
	{
		HttpResponse TempResponse;
		TempResponse.String(TCHAR_TO_UTF8(*In_Response));

		for (TPair<FString, FString>& EachHeader : In_Header)
		{
			TempResponse.SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
		}

		ReturnValue = ResponsePtr.get()->Begin();
		ReturnValue = ResponsePtr.get()->WriteResponse(&TempResponse);
		ReturnValue = ResponsePtr.get()->End();
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	return (ReturnValue == 0) ? true : false;
}

bool UHttpConnectionLhv::SendData(TArray<uint8> In_Bytes, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, bool bNoCopy)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	int ReturnValue = 0;

	try
	{
		HttpResponse TempResponse;
		TempResponse.Data(In_Bytes.GetData(), In_Bytes.Num(), bNoCopy);

		for (TPair<FString, FString>& EachHeader : In_Header)
		{
			TempResponse.SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
		}

		ReturnValue = ResponsePtr.get()->Begin();
		ReturnValue = ResponsePtr.get()->WriteResponse(&TempResponse);
		ReturnValue = ResponsePtr.get()->End();
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	return (ReturnValue == 0) ? true : false;
}

bool UHttpConnectionLhv::SendResponse(const FString In_Response, TMap<FString, FString> In_Header, ELibHvStatusCodes StatusCode, ELibHvContentTypes ContentTypes)
{
	if (this->RequestPtr == nullptr)
	{
		return false;
	}

	int ReturnValue = 0;

	try
	{
		HttpResponse TempResponse;
		TempResponse.SetContentType(this->Callback_Content_Type_Convert(ContentTypes));
		TempResponse.SetBody(TCHAR_TO_UTF8(*In_Response));

		for (TPair<FString, FString>& EachHeader : In_Header)
		{
			TempResponse.SetHeader(TCHAR_TO_UTF8(*EachHeader.Key), TCHAR_TO_UTF8(*EachHeader.Value));
		}

		ReturnValue = ResponsePtr.get()->Begin();
		ReturnValue = ResponsePtr.get()->WriteResponse(&TempResponse);
		ReturnValue = ResponsePtr.get()->End();
	}

	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ExceptionString);
		return false;
	}

	return (ReturnValue == 0) ? true : false;
}

#endif