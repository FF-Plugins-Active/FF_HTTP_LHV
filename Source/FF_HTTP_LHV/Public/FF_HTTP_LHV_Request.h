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

	virtual bool Callback_ContentType(http_content_type Type, ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String)
	{
		switch (Type)
		{

		case CONTENT_TYPE_NONE:

			Out_Content_Type = ELibHvContentTypes::Content_Type_NONE;
			Out_Type_String = "";
			return true;

		case CONTENT_TYPE_TEXT:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Text;
			Out_Type_String = "";
			return true;

		case TEXT_PLAIN:

			Out_Content_Type = ELibHvContentTypes::Text_Plain;
			Out_Type_String = "text/plain";
			return true;

		case TEXT_HTML:

			Out_Content_Type = ELibHvContentTypes::Text_HTML;
			Out_Type_String = "text/html";
			return true;

		case TEXT_CSS:

			Out_Content_Type = ELibHvContentTypes::Text_CSS;
			Out_Type_String = "text/css";
			return true;

		case TEXT_CSV:

			Out_Content_Type = ELibHvContentTypes::Text_CSV;
			Out_Type_String = "text/csv";
			return true;

		case TEXT_MARKDOWN:

			Out_Content_Type = ELibHvContentTypes::Text_Markdown;
			Out_Type_String = "text/markdown";
			return true;

		case TEXT_EVENT_STREAM:

			Out_Content_Type = ELibHvContentTypes::Text_Event_Stream;
			Out_Type_String = "text/event-stream";
			return true;

		case CONTENT_TYPE_APPLICATION:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Application;
			Out_Type_String = "";
			return true;

		case APPLICATION_JAVASCRIPT:

			Out_Content_Type = ELibHvContentTypes::Application_JS;
			Out_Type_String = "application/javascript";
			return true;

		case APPLICATION_JSON:

			Out_Content_Type = ELibHvContentTypes::Application_Json;
			Out_Type_String = "application/json";
			return true;

		case APPLICATION_XML:

			Out_Content_Type = ELibHvContentTypes::Application_XML;
			Out_Type_String = "application/xml";
			return true;

		case APPLICATION_URLENCODED:

			Out_Content_Type = ELibHvContentTypes::Application_URLENCODED;
			Out_Type_String = "application/x-www-form-urlencoded";
			return true;

		case APPLICATION_OCTET_STREAM:

			Out_Content_Type = ELibHvContentTypes::Application_Octet_Stream;
			Out_Type_String = "application/octet-stream";
			return true;

		case APPLICATION_ZIP:

			Out_Content_Type = ELibHvContentTypes::Application_ZIP;
			Out_Type_String = "application/zip";
			return true;

		case APPLICATION_GZIP:

			Out_Content_Type = ELibHvContentTypes::Application_gzip;
			Out_Type_String = "application/gzip";
			return true;

		case APPLICATION_7Z:

			Out_Content_Type = ELibHvContentTypes::Application_7z;
			Out_Type_String = "application/x-7z-compressed";
			return true;

		case APPLICATION_RAR:

			Out_Content_Type = ELibHvContentTypes::Application_RAR;
			Out_Type_String = "application/x-rar-compressed";
			return true;

		case APPLICATION_PDF:

			Out_Content_Type = ELibHvContentTypes::Application_PDF;
			Out_Type_String = "application/pdf";
			return true;

		case APPLICATION_RTF:

			Out_Content_Type = ELibHvContentTypes::Application_RTF;
			Out_Type_String = "application/rtf";
			return true;

		case APPLICATION_GRPC:

			Out_Content_Type = ELibHvContentTypes::Application_gRPC;
			Out_Type_String = "application/grpc";
			return true;

		case APPLICATION_WASM:

			Out_Content_Type = ELibHvContentTypes::Application_WASM;
			Out_Type_String = "application/wasm";
			return true;

		case APPLICATION_JAR:

			Out_Content_Type = ELibHvContentTypes::Application_JAR;
			Out_Type_String = "application/java-archive";
			return true;

		case APPLICATION_XHTML:

			Out_Content_Type = ELibHvContentTypes::Application_XHTML;
			Out_Type_String = "application/xhtml+xml";
			return true;

		case APPLICATION_ATOM:

			Out_Content_Type = ELibHvContentTypes::Application_Atom;
			Out_Type_String = "application/atom+xml";
			return true;

		case APPLICATION_RSS:

			Out_Content_Type = ELibHvContentTypes::Application_RSS;
			Out_Type_String = "application/rss+xml";
			return true;

		case APPLICATION_WORD:

			Out_Content_Type = ELibHvContentTypes::Application_WORD;
			Out_Type_String = "application/msword";
			return true;

		case APPLICATION_EXCEL:

			Out_Content_Type = ELibHvContentTypes::Application_Excel;
			Out_Type_String = "application/vnd.ms-excel";
			return true;

		case APPLICATION_PPT:

			Out_Content_Type = ELibHvContentTypes::Application_PPT;
			Out_Type_String = "application/vnd.ms-powerpoint";
			return true;

		case APPLICATION_EOT:

			Out_Content_Type = ELibHvContentTypes::Application_Eot;
			Out_Type_String = "application/vnd.ms-fontobject";
			return true;

		case APPLICATION_M3U8:

			Out_Content_Type = ELibHvContentTypes::Application_M3U8;
			Out_Type_String = "application/vnd.apple.mpegurl";
			return true;

		case APPLICATION_DOCX:

			Out_Content_Type = ELibHvContentTypes::Application_Docx;
			Out_Type_String = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
			return true;

		case APPLICATION_XLSX:

			Out_Content_Type = ELibHvContentTypes::Application_XLSX;
			Out_Type_String = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
			return true;

		case APPLICATION_PPTX:

			Out_Content_Type = ELibHvContentTypes::Application_PPTX;
			Out_Type_String = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
			return true;

		case CONTENT_TYPE_MULTIPART:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Multipart;
			Out_Type_String = "";
			return true;

		case MULTIPART_FORM_DATA:

			Out_Content_Type = ELibHvContentTypes::Multiplart_Form_Data;
			Out_Type_String = "multipart/form-data";
			return true;

		case CONTENT_TYPE_IMAGE:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Image;
			Out_Type_String = "";
			return true;

		case IMAGE_JPEG:

			Out_Content_Type = ELibHvContentTypes::Image_JPG;
			Out_Type_String = "image/jpeg";
			return true;

		case IMAGE_PNG:

			Out_Content_Type = ELibHvContentTypes::Image_PNG;
			Out_Type_String = "image/png";
			return true;

		case IMAGE_GIF:

			Out_Content_Type = ELibHvContentTypes::Image_GIF;
			Out_Type_String = "image/gif";
			return true;

		case IMAGE_ICO:

			Out_Content_Type = ELibHvContentTypes::Image_ICO;
			Out_Type_String = "image/x-icon";
			return true;

		case IMAGE_BMP:

			Out_Content_Type = ELibHvContentTypes::Image_BMP;
			Out_Type_String = "image/x-ms-bmp";
			return true;

		case IMAGE_SVG:

			Out_Content_Type = ELibHvContentTypes::Image_SVG;
			Out_Type_String = "image/svg+xml";
			return true;

		case IMAGE_TIFF:

			Out_Content_Type = ELibHvContentTypes::Image_TIFF;
			Out_Type_String = "image/tiff";
			return true;

		case IMAGE_WEBP:

			Out_Content_Type = ELibHvContentTypes::Image_WEBP;
			Out_Type_String = "image/webp";
			return true;

		case CONTENT_TYPE_VIDEO:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Video;
			Out_Type_String = "";
			return true;

		case VIDEO_MP4:

			Out_Content_Type = ELibHvContentTypes::Video_MP4;
			Out_Type_String = "video/mp4";
			return true;

		case VIDEO_FLV:

			Out_Content_Type = ELibHvContentTypes::Video_FLV;
			Out_Type_String = "video/x-flv";
			return true;

		case VIDEO_M4V:

			Out_Content_Type = ELibHvContentTypes::Video_M4V;
			Out_Type_String = "video/x-m4v";
			return true;

		case VIDEO_MNG:

			Out_Content_Type = ELibHvContentTypes::Video_MNG;
			Out_Type_String = "video/x-mng";
			return true;

		case VIDEO_TS:

			Out_Content_Type = ELibHvContentTypes::Video_TS;
			Out_Type_String = "video/mp2t";
			return true;

		case VIDEO_MPEG:

			Out_Content_Type = ELibHvContentTypes::Video_MPEG;
			Out_Type_String = "video/mpeg";
			return true;

		case VIDEO_WEBM:

			Out_Content_Type = ELibHvContentTypes::Video_WEBM;
			Out_Type_String = "video/webm";
			return true;

		case VIDEO_MOV:

			Out_Content_Type = ELibHvContentTypes::Video_MOV;
			Out_Type_String = "video/quicktime";
			return true;

		case VIDEO_3GPP:

			Out_Content_Type = ELibHvContentTypes::Video_3GPP;
			Out_Type_String = "video/3gpp";
			return true;

		case VIDEO_AVI:

			Out_Content_Type = ELibHvContentTypes::Video_AVI;
			Out_Type_String = "video/x-msvideo";
			return true;

		case VIDEO_WMV:

			Out_Content_Type = ELibHvContentTypes::Video_WMV;
			Out_Type_String = "video/x-ms-wmv";
			return true;

		case VIDEO_ASF:

			Out_Content_Type = ELibHvContentTypes::Video_ASF;
			Out_Type_String = "video/x-ms-asf";
			return true;

		case CONTENT_TYPE_AUDIO:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Audio;
			Out_Type_String = "";
			return true;

		case AUDIO_MP3:

			Out_Content_Type = ELibHvContentTypes::Audio_MP3;
			Out_Type_String = "audio/mpeg";
			return true;

		case AUDIO_OGG:

			Out_Content_Type = ELibHvContentTypes::Audio_OGG;
			Out_Type_String = "audio/ogg";
			return true;

		case AUDIO_M4A:

			Out_Content_Type = ELibHvContentTypes::Audio_M4A;
			Out_Type_String = "audio/x-m4a";
			return true;

		case AUDIO_AAC:

			Out_Content_Type = ELibHvContentTypes::Audio_AAC;
			Out_Type_String = "audio/aac";
			return true;

		case AUDIO_PCMA:

			Out_Content_Type = ELibHvContentTypes::Audio_PCMA;
			Out_Type_String = "audio/PCMA";
			return true;

		case AUDIO_OPUS:

			Out_Content_Type = ELibHvContentTypes::Audio_OPUS;
			Out_Type_String = "audio/opus";
			return true;

		case CONTENT_TYPE_FONT:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Font;
			Out_Type_String = "";
			return true;

		case FONT_TTF:

			Out_Content_Type = ELibHvContentTypes::Font_TTF;
			Out_Type_String = "font/ttf";
			return true;

		case FONT_OTF:

			Out_Content_Type = ELibHvContentTypes::Font_OTF;
			Out_Type_String = "font/otf";
			return true;

		case FONT_WOFF:

			Out_Content_Type = ELibHvContentTypes::Font_WOFF;
			Out_Type_String = "font/woff";
			return true;

		case FONT_WOFF2:

			Out_Content_Type = ELibHvContentTypes::Font_WOFF2;
			Out_Type_String = "font/woff2";
			return true;

		case CONTENT_TYPE_UNDEFINED:

			Out_Content_Type = ELibHvContentTypes::Content_Type_Undefined;
			Out_Type_String = "";
			return true;

		default:

			Out_Content_Type = ELibHvContentTypes::Content_Type_NONE;
			Out_Type_String = "";
			return true;
		}

		return false;
	}

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