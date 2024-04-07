// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_LHV_Server.h"

// Sets default values
AHTTP_Server_LHV::AHTTP_Server_LHV()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned.
void AHTTP_Server_LHV::BeginPlay()
{
#ifdef _WIN64
	this->HTTP_Server_Start();
#endif
	
	Super::BeginPlay();
}

// Called when the game ends or when destroyed.
void AHTTP_Server_LHV::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#ifdef _WIN64
	this->HTTP_Server_Stop();
#endif

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_LHV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHTTP_Server_LHV::HTTP_Server_Start()
{
#ifdef _WIN64
	
	if (this->Server_Name.IsEmpty())
	{
		return false;
	}

	this->Thread_LibHv = new FHTTP_Thread_LibHv(this);

	return (this->Thread_LibHv) ? true : false;

#else

	return false;

#endif
}

void AHTTP_Server_LHV::HTTP_Server_Stop()
{
#ifdef _WIN64
	
	if (this->Thread_LibHv)
	{
		delete this->Thread_LibHv;
		this->Thread_LibHv = nullptr;
	}

	return;

#else
	return;
#endif
}

bool AHTTP_Server_LHV::HTTP_Server_Toggle(bool bIsPause)
{
#ifdef _WIN64
	if (!this->Thread_LibHv)
	{
		return false;
	}

	return this->Thread_LibHv->Toggle(bIsPause);
#else
	return false;
#endif
}

#if (LHV_USE_POINTER == 0)

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

bool UHttpConnectionLhv::GetContentType(ELibHvContentTypes& Out_Content_Type)
{
#ifdef _WIN64
	
	if (this->Request == nullptr)
	{
		return false;
	}

	http_content_type Type = this->Request->content_type;

	switch (Type)
	{
	
	case CONTENT_TYPE_NONE:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_NONE;
		return true;
	
	case CONTENT_TYPE_TEXT:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_Text;
		return true;
	
	case TEXT_PLAIN:
		
		Out_Content_Type = ELibHvContentTypes::Text_Plain;
		return true;
	
	case TEXT_HTML:
		
		Out_Content_Type = ELibHvContentTypes::Text_HTML;
		return true;
	
	case TEXT_CSS:
		
		Out_Content_Type = ELibHvContentTypes::Text_CSS;
		return true;
	
	case TEXT_CSV:
		
		Out_Content_Type = ELibHvContentTypes::Text_CSV;
		return true;
	
	case TEXT_MARKDOWN:
		
		Out_Content_Type = ELibHvContentTypes::Text_Markdown;
		return true;
	
	case TEXT_EVENT_STREAM:
		
		Out_Content_Type = ELibHvContentTypes::Text_Event_Stream;
		return true;
	
	case CONTENT_TYPE_APPLICATION:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_Application;
		return true;
	
	case APPLICATION_JAVASCRIPT:
		
		Out_Content_Type = ELibHvContentTypes::Application_JS;
		return true;
	
	case APPLICATION_JSON:
		
		Out_Content_Type = ELibHvContentTypes::Application_Json;
		return true;
	
	case APPLICATION_XML:
		
		Out_Content_Type = ELibHvContentTypes::Application_XML;
		return true;
	
	case APPLICATION_URLENCODED:
		
		Out_Content_Type = ELibHvContentTypes::Application_URLENCODED;
		return true;
	
	case APPLICATION_OCTET_STREAM:
		
		Out_Content_Type = ELibHvContentTypes::Application_Octet_Stream;
		return true;
	
	case APPLICATION_ZIP:
		
		Out_Content_Type = ELibHvContentTypes::Application_ZIP;
		return true;
	
	case APPLICATION_GZIP:
		
		Out_Content_Type = ELibHvContentTypes::Application_gzip;
		return true;
	
	case APPLICATION_7Z:
		
		Out_Content_Type = ELibHvContentTypes::Application_7z;
		return true;
	
	case APPLICATION_RAR:
		
		Out_Content_Type = ELibHvContentTypes::Application_RAR;
		return true;
	
	case APPLICATION_PDF:
		
		Out_Content_Type = ELibHvContentTypes::Application_PDF;
		return true;
	
	case APPLICATION_RTF:
		
		Out_Content_Type = ELibHvContentTypes::Application_RTF;
		return true;
	
	case APPLICATION_GRPC:
		
		Out_Content_Type = ELibHvContentTypes::Application_gRPC;
		return true;
	
	case APPLICATION_WASM:
		
		Out_Content_Type = ELibHvContentTypes::Application_WASM;
		return true;
	
	case APPLICATION_JAR:
		
		Out_Content_Type = ELibHvContentTypes::Application_JAR;
		return true;
	
	case APPLICATION_XHTML:
		
		Out_Content_Type = ELibHvContentTypes::Application_XHTML;
		return true;
	
	case APPLICATION_ATOM:
		
		Out_Content_Type = ELibHvContentTypes::Application_Atom;
		return true;
	
	case APPLICATION_RSS:
		
		Out_Content_Type = ELibHvContentTypes::Application_RSS;
		return true;
	
	case APPLICATION_WORD:
		
		Out_Content_Type = ELibHvContentTypes::Application_WORD;
		return true;
	
	case APPLICATION_EXCEL:
		
		Out_Content_Type = ELibHvContentTypes::Application_Excel;
		return true;
	
	case APPLICATION_PPT:
		
		Out_Content_Type = ELibHvContentTypes::Application_PPT;
		return true;
	
	case APPLICATION_EOT:
		
		Out_Content_Type = ELibHvContentTypes::Application_Eot;
		return true;
	
	case APPLICATION_M3U8:
		
		Out_Content_Type = ELibHvContentTypes::Application_M3U8;
		return true;
	
	case APPLICATION_DOCX:
		
		Out_Content_Type = ELibHvContentTypes::Application_Docx;
		return true;
	
	case APPLICATION_XLSX:
		
		Out_Content_Type = ELibHvContentTypes::Application_XLSX;
		return true;
	
	case APPLICATION_PPTX:
		
		Out_Content_Type = ELibHvContentTypes::Application_PPTX;
		return true;
	
	case CONTENT_TYPE_MULTIPART:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_Multipart;
		return true;
	
	case MULTIPART_FORM_DATA:
		
		Out_Content_Type = ELibHvContentTypes::Multiplart_Form_Data;
		return true;
	
	case CONTENT_TYPE_IMAGE:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_Image;
		return true;
	
	case IMAGE_JPEG:
		
		Out_Content_Type = ELibHvContentTypes::Image_JPG;
		return true;
	
	case IMAGE_PNG:
		
		Out_Content_Type = ELibHvContentTypes::Image_PNG;
		return true;
	
	case IMAGE_GIF:
	
		Out_Content_Type = ELibHvContentTypes::Image_GIF;
		return true;
	
	case IMAGE_ICO:
		
		Out_Content_Type = ELibHvContentTypes::Image_ICO;
		return true;
	
	case IMAGE_BMP:
	
		Out_Content_Type = ELibHvContentTypes::Image_BMP;
		return true;
	
	case IMAGE_SVG:
	
		Out_Content_Type = ELibHvContentTypes::Image_SVG;
		return true;
	
	case IMAGE_TIFF:
	
		Out_Content_Type = ELibHvContentTypes::Image_TIFF;
		return true;
	
	case IMAGE_WEBP:
	
		Out_Content_Type = ELibHvContentTypes::Image_WEBP;
		return true;
	
	case CONTENT_TYPE_VIDEO:
	
		Out_Content_Type = ELibHvContentTypes::Content_Type_Video;
		return true;
	
	case VIDEO_MP4:
	
		Out_Content_Type = ELibHvContentTypes::Video_MP4;
		return true;
	
	case VIDEO_FLV:
	
		Out_Content_Type = ELibHvContentTypes::Video_FLV;
		return true;
	
	case VIDEO_M4V:
	
		Out_Content_Type = ELibHvContentTypes::Video_M4V;
		return true;
	
	case VIDEO_MNG:
		
		Out_Content_Type = ELibHvContentTypes::Video_MNG;
		return true;
	
	case VIDEO_TS:
		
		Out_Content_Type = ELibHvContentTypes::Video_TS;
		return true;
	
	case VIDEO_MPEG:
		
		Out_Content_Type = ELibHvContentTypes::Video_MPEG;
		return true;
	
	case VIDEO_WEBM:
		
		Out_Content_Type = ELibHvContentTypes::Video_WEBM;
		return true;
	
	case VIDEO_MOV:
		
		Out_Content_Type = ELibHvContentTypes::Video_MOV;
		return true;
	
	case VIDEO_3GPP:
		
		Out_Content_Type = ELibHvContentTypes::Video_3GPP;
		return true;
	
	case VIDEO_AVI:
		
		Out_Content_Type = ELibHvContentTypes::Video_AVI;
		return true;
	
	case VIDEO_WMV:
		
		Out_Content_Type = ELibHvContentTypes::Video_WMV;
		return true;
	
	case VIDEO_ASF:
		
		Out_Content_Type = ELibHvContentTypes::Video_ASF;
		return true;
	
	case CONTENT_TYPE_AUDIO:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_Audio;
		return true;
	
	case AUDIO_MP3:
		
		Out_Content_Type = ELibHvContentTypes::Audio_MP3;
		return true;
	
	case AUDIO_OGG:
		
		Out_Content_Type = ELibHvContentTypes::Audio_OGG;
		return true;
	
	case AUDIO_M4A:
		
		Out_Content_Type = ELibHvContentTypes::Audio_M4A;
		return true;
	
	case AUDIO_AAC:
		
		Out_Content_Type = ELibHvContentTypes::Audio_AAC;
		return true;
	
	case AUDIO_PCMA:
		
		Out_Content_Type = ELibHvContentTypes::Audio_PCMA;
		return true;
	
	case AUDIO_OPUS:
		
		Out_Content_Type = ELibHvContentTypes::Audio_OPUS;
		return true;
	
	case CONTENT_TYPE_FONT:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_Font;
		return true;
	
	case FONT_TTF:
		
		Out_Content_Type = ELibHvContentTypes::Font_TTF;
		return true;
	
	case FONT_OTF:
		
		Out_Content_Type = ELibHvContentTypes::Font_OTF;
		return true;
	
	case FONT_WOFF:
		
		Out_Content_Type = ELibHvContentTypes::Font_WOFF;
		return true;
	
	case FONT_WOFF2:
		
		Out_Content_Type = ELibHvContentTypes::Font_WOFF2;
		return true;
	
	case CONTENT_TYPE_UNDEFINED:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_Undefined;
		return true;
	
	default:
		
		Out_Content_Type = ELibHvContentTypes::Content_Type_NONE;
		return true;
	}

	return false;

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

#else

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

	http_content_type Type = this->RequestPtr->get()->content_type;

	switch (Type)
	{

	case CONTENT_TYPE_NONE:

		Out_Content_Type = ELibHvContentTypes::Content_Type_NONE;
		return true;

	case CONTENT_TYPE_TEXT:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Text;
		return true;

	case TEXT_PLAIN:

		Out_Content_Type = ELibHvContentTypes::Text_Plain;
		return true;

	case TEXT_HTML:

		Out_Content_Type = ELibHvContentTypes::Text_HTML;
		return true;

	case TEXT_CSS:

		Out_Content_Type = ELibHvContentTypes::Text_CSS;
		return true;

	case TEXT_CSV:

		Out_Content_Type = ELibHvContentTypes::Text_CSV;
		return true;

	case TEXT_MARKDOWN:

		Out_Content_Type = ELibHvContentTypes::Text_Markdown;
		return true;

	case TEXT_EVENT_STREAM:

		Out_Content_Type = ELibHvContentTypes::Text_Event_Stream;
		return true;

	case CONTENT_TYPE_APPLICATION:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Application;
		return true;

	case APPLICATION_JAVASCRIPT:

		Out_Content_Type = ELibHvContentTypes::Application_JS;
		return true;

	case APPLICATION_JSON:

		Out_Content_Type = ELibHvContentTypes::Application_Json;
		return true;

	case APPLICATION_XML:

		Out_Content_Type = ELibHvContentTypes::Application_XML;
		return true;

	case APPLICATION_URLENCODED:

		Out_Content_Type = ELibHvContentTypes::Application_URLENCODED;
		return true;

	case APPLICATION_OCTET_STREAM:

		Out_Content_Type = ELibHvContentTypes::Application_Octet_Stream;
		return true;

	case APPLICATION_ZIP:

		Out_Content_Type = ELibHvContentTypes::Application_ZIP;
		return true;

	case APPLICATION_GZIP:

		Out_Content_Type = ELibHvContentTypes::Application_gzip;
		return true;

	case APPLICATION_7Z:

		Out_Content_Type = ELibHvContentTypes::Application_7z;
		return true;

	case APPLICATION_RAR:

		Out_Content_Type = ELibHvContentTypes::Application_RAR;
		return true;

	case APPLICATION_PDF:

		Out_Content_Type = ELibHvContentTypes::Application_PDF;
		return true;

	case APPLICATION_RTF:

		Out_Content_Type = ELibHvContentTypes::Application_RTF;
		return true;

	case APPLICATION_GRPC:

		Out_Content_Type = ELibHvContentTypes::Application_gRPC;
		return true;

	case APPLICATION_WASM:

		Out_Content_Type = ELibHvContentTypes::Application_WASM;
		return true;

	case APPLICATION_JAR:

		Out_Content_Type = ELibHvContentTypes::Application_JAR;
		return true;

	case APPLICATION_XHTML:

		Out_Content_Type = ELibHvContentTypes::Application_XHTML;
		return true;

	case APPLICATION_ATOM:

		Out_Content_Type = ELibHvContentTypes::Application_Atom;
		return true;

	case APPLICATION_RSS:

		Out_Content_Type = ELibHvContentTypes::Application_RSS;
		return true;

	case APPLICATION_WORD:

		Out_Content_Type = ELibHvContentTypes::Application_WORD;
		return true;

	case APPLICATION_EXCEL:

		Out_Content_Type = ELibHvContentTypes::Application_Excel;
		return true;

	case APPLICATION_PPT:

		Out_Content_Type = ELibHvContentTypes::Application_PPT;
		return true;

	case APPLICATION_EOT:

		Out_Content_Type = ELibHvContentTypes::Application_Eot;
		return true;

	case APPLICATION_M3U8:

		Out_Content_Type = ELibHvContentTypes::Application_M3U8;
		return true;

	case APPLICATION_DOCX:

		Out_Content_Type = ELibHvContentTypes::Application_Docx;
		return true;

	case APPLICATION_XLSX:

		Out_Content_Type = ELibHvContentTypes::Application_XLSX;
		return true;

	case APPLICATION_PPTX:

		Out_Content_Type = ELibHvContentTypes::Application_PPTX;
		return true;

	case CONTENT_TYPE_MULTIPART:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Multipart;
		return true;

	case MULTIPART_FORM_DATA:

		Out_Content_Type = ELibHvContentTypes::Multiplart_Form_Data;
		return true;

	case CONTENT_TYPE_IMAGE:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Image;
		return true;

	case IMAGE_JPEG:

		Out_Content_Type = ELibHvContentTypes::Image_JPG;
		return true;

	case IMAGE_PNG:

		Out_Content_Type = ELibHvContentTypes::Image_PNG;
		return true;

	case IMAGE_GIF:

		Out_Content_Type = ELibHvContentTypes::Image_GIF;
		return true;

	case IMAGE_ICO:

		Out_Content_Type = ELibHvContentTypes::Image_ICO;
		return true;

	case IMAGE_BMP:

		Out_Content_Type = ELibHvContentTypes::Image_BMP;
		return true;

	case IMAGE_SVG:

		Out_Content_Type = ELibHvContentTypes::Image_SVG;
		return true;

	case IMAGE_TIFF:

		Out_Content_Type = ELibHvContentTypes::Image_TIFF;
		return true;

	case IMAGE_WEBP:

		Out_Content_Type = ELibHvContentTypes::Image_WEBP;
		return true;

	case CONTENT_TYPE_VIDEO:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Video;
		return true;

	case VIDEO_MP4:

		Out_Content_Type = ELibHvContentTypes::Video_MP4;
		return true;

	case VIDEO_FLV:

		Out_Content_Type = ELibHvContentTypes::Video_FLV;
		return true;

	case VIDEO_M4V:

		Out_Content_Type = ELibHvContentTypes::Video_M4V;
		return true;

	case VIDEO_MNG:

		Out_Content_Type = ELibHvContentTypes::Video_MNG;
		return true;

	case VIDEO_TS:

		Out_Content_Type = ELibHvContentTypes::Video_TS;
		return true;

	case VIDEO_MPEG:

		Out_Content_Type = ELibHvContentTypes::Video_MPEG;
		return true;

	case VIDEO_WEBM:

		Out_Content_Type = ELibHvContentTypes::Video_WEBM;
		return true;

	case VIDEO_MOV:

		Out_Content_Type = ELibHvContentTypes::Video_MOV;
		return true;

	case VIDEO_3GPP:

		Out_Content_Type = ELibHvContentTypes::Video_3GPP;
		return true;

	case VIDEO_AVI:

		Out_Content_Type = ELibHvContentTypes::Video_AVI;
		return true;

	case VIDEO_WMV:

		Out_Content_Type = ELibHvContentTypes::Video_WMV;
		return true;

	case VIDEO_ASF:

		Out_Content_Type = ELibHvContentTypes::Video_ASF;
		return true;

	case CONTENT_TYPE_AUDIO:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Audio;
		return true;

	case AUDIO_MP3:

		Out_Content_Type = ELibHvContentTypes::Audio_MP3;
		return true;

	case AUDIO_OGG:

		Out_Content_Type = ELibHvContentTypes::Audio_OGG;
		return true;

	case AUDIO_M4A:

		Out_Content_Type = ELibHvContentTypes::Audio_M4A;
		return true;

	case AUDIO_AAC:

		Out_Content_Type = ELibHvContentTypes::Audio_AAC;
		return true;

	case AUDIO_PCMA:

		Out_Content_Type = ELibHvContentTypes::Audio_PCMA;
		return true;

	case AUDIO_OPUS:

		Out_Content_Type = ELibHvContentTypes::Audio_OPUS;
		return true;

	case CONTENT_TYPE_FONT:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Font;
		return true;

	case FONT_TTF:

		Out_Content_Type = ELibHvContentTypes::Font_TTF;
		return true;

	case FONT_OTF:

		Out_Content_Type = ELibHvContentTypes::Font_OTF;
		return true;

	case FONT_WOFF:

		Out_Content_Type = ELibHvContentTypes::Font_WOFF;
		return true;

	case FONT_WOFF2:

		Out_Content_Type = ELibHvContentTypes::Font_WOFF2;
		return true;

	case CONTENT_TYPE_UNDEFINED:

		Out_Content_Type = ELibHvContentTypes::Content_Type_Undefined;
		return true;

	default:

		Out_Content_Type = ELibHvContentTypes::Content_Type_NONE;
		return true;
	}

	return false;
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