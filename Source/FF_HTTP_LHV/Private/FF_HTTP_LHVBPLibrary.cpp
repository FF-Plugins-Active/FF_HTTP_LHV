// Copyright Epic Games, Inc. All Rights Reserved.

#include "FF_HTTP_LHVBPLibrary.h"
#include "FF_HTTP_LHV.h"

UFF_HTTP_LHVBPLibrary::UFF_HTTP_LHVBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

http_content_type UFF_HTTP_LHVBPLibrary::LibHv_Type_Bp_To_Original(ELibHvContentTypes Type)
{
	switch (Type)
	{
	case ELibHvContentTypes::Application_7z:
		return http_content_type::APPLICATION_7Z;

	case ELibHvContentTypes::Application_Atom:
		return http_content_type::APPLICATION_ATOM;

	case ELibHvContentTypes::Application_Docx:
		return http_content_type::APPLICATION_DOCX;

	case ELibHvContentTypes::Application_Eot:
		return http_content_type::APPLICATION_EOT;

	case ELibHvContentTypes::Application_Excel:
		return http_content_type::APPLICATION_EXCEL;

	case ELibHvContentTypes::Application_gRPC:
		return http_content_type::APPLICATION_GRPC;

	case ELibHvContentTypes::Application_gzip:
		return http_content_type::APPLICATION_GZIP;

	case ELibHvContentTypes::Application_JAR:
		return http_content_type::APPLICATION_JAR;

	case ELibHvContentTypes::Application_JS:
		return http_content_type::APPLICATION_JAVASCRIPT;

	case ELibHvContentTypes::Application_Json:
		return http_content_type::APPLICATION_JSON;

	case ELibHvContentTypes::Application_M3U8:
		return http_content_type::APPLICATION_M3U8;

	case ELibHvContentTypes::Application_Octet_Stream:
		return http_content_type::APPLICATION_OCTET_STREAM;

	case ELibHvContentTypes::Application_PDF:
		return http_content_type::APPLICATION_PDF;

	case ELibHvContentTypes::Application_PPT:
		return http_content_type::APPLICATION_PPT;

	case ELibHvContentTypes::Application_PPTX:
		return http_content_type::APPLICATION_PPTX;

	case ELibHvContentTypes::Application_RAR:
		return http_content_type::APPLICATION_RAR;

	case ELibHvContentTypes::Application_RSS:
		return http_content_type::APPLICATION_RSS;

	case ELibHvContentTypes::Application_RTF:
		return http_content_type::APPLICATION_RTF;

	case ELibHvContentTypes::Application_URLENCODED:
		return http_content_type::APPLICATION_URLENCODED;

	case ELibHvContentTypes::Application_WASM:
		return http_content_type::APPLICATION_WASM;

	case ELibHvContentTypes::Application_WORD:
		return http_content_type::APPLICATION_WORD;

	case ELibHvContentTypes::Application_XHTML:
		return http_content_type::APPLICATION_XHTML;

	case ELibHvContentTypes::Application_XLSX:
		return http_content_type::APPLICATION_XLSX;

	case ELibHvContentTypes::Application_XML:
		return http_content_type::APPLICATION_XML;

	case ELibHvContentTypes::Application_ZIP:
		return http_content_type::APPLICATION_ZIP;

	case ELibHvContentTypes::Audio_AAC:
		return http_content_type::AUDIO_AAC;

	case ELibHvContentTypes::Audio_M4A:
		return http_content_type::AUDIO_M4A;

	case ELibHvContentTypes::Audio_MP3:
		return http_content_type::AUDIO_MP3;

	case ELibHvContentTypes::Audio_OGG:
		return http_content_type::AUDIO_OGG;

	case ELibHvContentTypes::Audio_OPUS:
		return http_content_type::AUDIO_OPUS;

	case ELibHvContentTypes::Audio_PCMA:
		return http_content_type::AUDIO_PCMA;

	case ELibHvContentTypes::Content_Type_Application:
		return http_content_type::CONTENT_TYPE_APPLICATION;

	case ELibHvContentTypes::Content_Type_Audio:
		return http_content_type::CONTENT_TYPE_AUDIO;

	case ELibHvContentTypes::Content_Type_Font:
		return http_content_type::CONTENT_TYPE_FONT;

	case ELibHvContentTypes::Content_Type_Image:
		return http_content_type::CONTENT_TYPE_IMAGE;

	case ELibHvContentTypes::Content_Type_Multipart:
		return http_content_type::CONTENT_TYPE_MULTIPART;

	case ELibHvContentTypes::Content_Type_NONE:
		return http_content_type::CONTENT_TYPE_NONE;

	case ELibHvContentTypes::Content_Type_Text:
		return http_content_type::CONTENT_TYPE_TEXT;

	case ELibHvContentTypes::Content_Type_Undefined:
		return http_content_type::CONTENT_TYPE_UNDEFINED;

	case ELibHvContentTypes::Content_Type_Video:
		return http_content_type::CONTENT_TYPE_VIDEO;

	case ELibHvContentTypes::Font_OTF:
		return http_content_type::FONT_OTF;

	case ELibHvContentTypes::Font_TTF:
		return http_content_type::FONT_TTF;

	case ELibHvContentTypes::Font_WOFF:
		return http_content_type::FONT_WOFF;

	case ELibHvContentTypes::Font_WOFF2:
		return http_content_type::FONT_WOFF2;

	case ELibHvContentTypes::Image_BMP:
		return http_content_type::IMAGE_BMP;

	case ELibHvContentTypes::Image_GIF:
		return http_content_type::IMAGE_GIF;

	case ELibHvContentTypes::Image_ICO:
		return http_content_type::IMAGE_ICO;

	case ELibHvContentTypes::Image_JPG:
		return http_content_type::IMAGE_JPEG;

	case ELibHvContentTypes::Image_PNG:
		return http_content_type::IMAGE_PNG;

	case ELibHvContentTypes::Image_SVG:
		return http_content_type::IMAGE_SVG;

	case ELibHvContentTypes::Image_TIFF:
		return http_content_type::IMAGE_TIFF;

	case ELibHvContentTypes::Image_WEBP:
		return http_content_type::IMAGE_WEBP;

	case ELibHvContentTypes::Multiplart_Form_Data:
		return http_content_type::MULTIPART_FORM_DATA;

	case ELibHvContentTypes::Text_CSS:
		return http_content_type::TEXT_CSS;

	case ELibHvContentTypes::Text_CSV:
		return http_content_type::TEXT_CSV;

	case ELibHvContentTypes::Text_Event_Stream:
		return http_content_type::TEXT_EVENT_STREAM;

	case ELibHvContentTypes::Text_HTML:
		return http_content_type::TEXT_HTML;

	case ELibHvContentTypes::Text_Markdown:
		return http_content_type::TEXT_MARKDOWN;

	case ELibHvContentTypes::Text_Plain:
		return http_content_type::TEXT_PLAIN;

	case ELibHvContentTypes::Video_3GPP:
		return http_content_type::VIDEO_3GPP;

	case ELibHvContentTypes::Video_ASF:
		return http_content_type::VIDEO_ASF;

	case ELibHvContentTypes::Video_AVI:
		return http_content_type::VIDEO_AVI;

	case ELibHvContentTypes::Video_FLV:
		return http_content_type::VIDEO_FLV;

	case ELibHvContentTypes::Video_M4V:
		return http_content_type::VIDEO_M4V;

	case ELibHvContentTypes::Video_MNG:
		return http_content_type::VIDEO_MNG;

	case ELibHvContentTypes::Video_MOV:
		return http_content_type::VIDEO_MOV;

	case ELibHvContentTypes::Video_MP4:
		return http_content_type::VIDEO_MP4;

	case ELibHvContentTypes::Video_MPEG:
		return http_content_type::VIDEO_MPEG;

	case ELibHvContentTypes::Video_TS:
		return http_content_type::VIDEO_TS;

	case ELibHvContentTypes::Video_WEBM:
		return http_content_type::VIDEO_WEBM;

	case ELibHvContentTypes::Video_WMV:
		return http_content_type::VIDEO_WMV;

	default:
		return http_content_type::TEXT_PLAIN;
	}

	return http_content_type::TEXT_PLAIN;
}

int32 UFF_HTTP_LHVBPLibrary::LibHv_Status_To_Int(ELibHvStatusCodes Status)
{
	switch (Status)
	{
	case ELibHvStatusCodes::Continue_100:
		return 100;

	case ELibHvStatusCodes::Switching_Protocols_101:
		return 101;

	case ELibHvStatusCodes::Processing_102:
		return 102;

	case ELibHvStatusCodes::OK_200:
		return 200;

	case ELibHvStatusCodes::Created_201:
		return 201;

	case ELibHvStatusCodes::Accepted_202:
		return 202;

	case ELibHvStatusCodes::Non_Authoratative_Information_203:
		return 203;

	case ELibHvStatusCodes::No_Content_204:
		return 204;

	case ELibHvStatusCodes::Reset_Content_205:
		return 205;

	case ELibHvStatusCodes::Partial_Content_206:
		return 206;

	case ELibHvStatusCodes::Multi_Status_207:
		return 207;

	case ELibHvStatusCodes::Already_Reported_208:
		return 208;

	case ELibHvStatusCodes::Im_Used_226:
		return 226;

	case ELibHvStatusCodes::Multiple_Choice_300:
		return 300;

	case ELibHvStatusCodes::Moved_Permanently_301:
		return 301;

	case ELibHvStatusCodes::Found_302:
		return 302;

	case ELibHvStatusCodes::See_Other_303:
		return 303;

	case ELibHvStatusCodes::Not_Modified_304:
		return 304;

	case ELibHvStatusCodes::Use_Proxy_305:
		return 305;

	case ELibHvStatusCodes::Temporary_Redirect_307:
		return 307;

	case ELibHvStatusCodes::Permanent_Redirect_308:
		return 308;

	case ELibHvStatusCodes::Bad_Request_400:
		return 400;

	case ELibHvStatusCodes::Unauthorized_401:
		return 401;

	case ELibHvStatusCodes::Payment_Required_402:
		return 402;

	case ELibHvStatusCodes::Forbidden_403:
		return 403;

	case ELibHvStatusCodes::Not_Found_404:
		return 404;

	case ELibHvStatusCodes::Method_Not_Allowed_405:
		return 405;

	case ELibHvStatusCodes::Not_Acceptable_406:
		return 406;

	case ELibHvStatusCodes::Proxy_Authentication_Required_407:
		return 407;

	case ELibHvStatusCodes::Request_Timeout_408:
		return 408;

	case ELibHvStatusCodes::Conflict_409:
		return 409;

	case ELibHvStatusCodes::Gone_410:
		return 410;

	case ELibHvStatusCodes::Lenght_Required_411:
		return 411;

	case ELibHvStatusCodes::Precondition_Failed_412:
		return 412;

	case ELibHvStatusCodes::Payload_Too_Large_413:
		return 413;

	case ELibHvStatusCodes::Uri_Too_Long_414:
		return 414;

	case ELibHvStatusCodes::Unsupported_Media_Type_415:
		return 415;

	case ELibHvStatusCodes::Range_Not_Satisfiable_416:
		return 416;

	case ELibHvStatusCodes::Expectation_Failed_417:
		return 417;

	case ELibHvStatusCodes::Misdirected_Request_421:
		return 421;

	case ELibHvStatusCodes::Unprocessable_Entity_422:
		return 422;

	case ELibHvStatusCodes::Locked_423:
		return 423;

	case ELibHvStatusCodes::Failed_Dependency_424:
		return 424;

	case ELibHvStatusCodes::Upgrade_Required_426:
		return 426;

	case ELibHvStatusCodes::Precondition_Required_428:
		return 428;

	case ELibHvStatusCodes::Too_Many_Requests_429:
		return 429;

	case ELibHvStatusCodes::Request_Header_Fields_Too_Large_431:
		return 431;

	case ELibHvStatusCodes::Unavailable_For_Legal_Reasons_451:
		return 451;

	case ELibHvStatusCodes::Internal_Server_Error_500:
		return 500;

	case ELibHvStatusCodes::Not_Implemented_501:
		return 501;

	case ELibHvStatusCodes::Bad_Gateway_502:
		return 502;

	case ELibHvStatusCodes::Service_Unavailable_503:
		return 503;

	case ELibHvStatusCodes::Gateway_Timeout_504:
		return 504;

	case ELibHvStatusCodes::Http_Version_Not_Supported_505:
		return 505;

	case ELibHvStatusCodes::Variant_Also_Negotiates_506:
		return 506;

	case ELibHvStatusCodes::Insufficient_Storage_507:
		return 507;

	case ELibHvStatusCodes::Loop_Detected_508:
		return 508;

	case ELibHvStatusCodes::Not_Extended_510:
		return 510;

	case ELibHvStatusCodes::Network_Authentication_Required_511:
		return 511;

	default:
		return 404;
	};

	return 404;
}

http_status UFF_HTTP_LHVBPLibrary::LibHv_Int_To_Status(int Status)
{
	switch (Status)
	{
	case 100:
		return http_status::HTTP_STATUS_CONTINUE;
	
	case 101:
		return http_status::HTTP_STATUS_SWITCHING_PROTOCOLS;

	case 102:
		return http_status::HTTP_STATUS_PROCESSING;
	
	case 200:
		return http_status::HTTP_STATUS_OK;
	
	case 201:
		return http_status::HTTP_STATUS_CREATED;

	case 202:
		return http_status::HTTP_STATUS_ACCEPTED;

	case 203:
		return http_status::HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION;

	case 204:
		return http_status::HTTP_STATUS_NO_CONTENT;

	case 205:
		return http_status::HTTP_STATUS_RESET_CONTENT;

	case 206:
		return http_status::HTTP_STATUS_PARTIAL_CONTENT;

	case 207:
		return http_status::HTTP_STATUS_MULTI_STATUS;

	case 208:
		return http_status::HTTP_STATUS_ALREADY_REPORTED;

	case 226:
		return http_status::HTTP_STATUS_IM_USED;

	case 300:
		return http_status::HTTP_STATUS_MULTIPLE_CHOICES;

	case 301:
		return http_status::HTTP_STATUS_MOVED_PERMANENTLY;

	case 302:
		return http_status::HTTP_STATUS_FOUND;

	case 303:
		return http_status::HTTP_STATUS_SEE_OTHER;

	case 304:
		return http_status::HTTP_STATUS_NOT_MODIFIED;

	case 305:
		return http_status::HTTP_STATUS_USE_PROXY;

	case 307:
		return http_status::HTTP_STATUS_TEMPORARY_REDIRECT;

	case 308:
		return http_status::HTTP_STATUS_PERMANENT_REDIRECT;

	case 400:
		return http_status::HTTP_STATUS_BAD_REQUEST;

	case 401:
		return http_status::HTTP_STATUS_UNAUTHORIZED;

	case 402:
		return http_status::HTTP_STATUS_PAYMENT_REQUIRED;

	case 403:
		return http_status::HTTP_STATUS_FORBIDDEN;

	case 404:
		return http_status::HTTP_STATUS_NOT_FOUND;

	case 405:
		return http_status::HTTP_STATUS_METHOD_NOT_ALLOWED;

	case 406:
		return http_status::HTTP_STATUS_NOT_ACCEPTABLE;

	case 407:
		return http_status::HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED;

	case 408:
		return http_status::HTTP_STATUS_REQUEST_TIMEOUT;

	case 409:
		return http_status::HTTP_STATUS_CONFLICT;

	case 410:
		return http_status::HTTP_STATUS_GONE;

	case 411:
		return http_status::HTTP_STATUS_LENGTH_REQUIRED;

	case 412:
		return http_status::HTTP_STATUS_PRECONDITION_FAILED;

	case 413:
		return http_status::HTTP_STATUS_PAYLOAD_TOO_LARGE;

	case 414:
		return http_status::HTTP_STATUS_URI_TOO_LONG;

	case 415:
		return http_status::HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE;

	case 416:
		return http_status::HTTP_STATUS_RANGE_NOT_SATISFIABLE;

	case 417:
		return http_status::HTTP_STATUS_EXPECTATION_FAILED;

	case 421:
		return http_status::HTTP_STATUS_MISDIRECTED_REQUEST;

	case 422:
		return http_status::HTTP_STATUS_UNPROCESSABLE_ENTITY;

	case 423:
		return http_status::HTTP_STATUS_LOCKED;

	case 424:
		return http_status::HTTP_STATUS_FAILED_DEPENDENCY;

	case 426:
		return http_status::HTTP_STATUS_UPGRADE_REQUIRED;

	case 428:
		return http_status::HTTP_STATUS_PRECONDITION_REQUIRED;

	case 429:
		return http_status::HTTP_STATUS_TOO_MANY_REQUESTS;

	case 431:
		return http_status::HTTP_STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE;

	case 451:
		return http_status::HTTP_STATUS_UNAVAILABLE_FOR_LEGAL_REASONS;

	case 500:
		return http_status::HTTP_STATUS_INTERNAL_SERVER_ERROR;

	case 501:
		return http_status::HTTP_STATUS_NOT_IMPLEMENTED;

	case 502:
		return http_status::HTTP_STATUS_BAD_GATEWAY;

	case 503:
		return http_status::HTTP_STATUS_SERVICE_UNAVAILABLE;

	case 504:
		return http_status::HTTP_STATUS_GATEWAY_TIMEOUT;

	case 505:
		return http_status::HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED;

	case 506:
		return http_status::HTTP_STATUS_VARIANT_ALSO_NEGOTIATES;

	case 507:
		return http_status::HTTP_STATUS_INSUFFICIENT_STORAGE;

	case 508:
		return http_status::HTTP_STATUS_LOOP_DETECTED;

	case 510:
		return http_status::HTTP_STATUS_NOT_EXTENDED;

	case 511:
		return http_status::HTTP_STATUS_NETWORK_AUTHENTICATION_REQUIRED;
	
	default:
		return http_status::HTTP_STATUS_NOT_FOUND;
	};

	return http_status::HTTP_STATUS_NOT_FOUND;
}