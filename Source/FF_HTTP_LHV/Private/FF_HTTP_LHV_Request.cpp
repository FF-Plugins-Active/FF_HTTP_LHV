#include "FF_HTTP_LHV_Request.h"

// Method

bool UHttpConnectionLhv::Callback_Type_Method(http_method Type, FString& Out_Type_String)
{
	switch (Type)
	{
	case HTTP_DELETE:

		Out_Type_String = "DELETE";
		return true;

	case HTTP_GET:

		Out_Type_String = "GET";
		return true;

	case HTTP_HEAD:

		Out_Type_String = "HEAD";
		return true;

	case HTTP_POST:

		Out_Type_String = "POST";
		return true;

	case HTTP_PUT:

		Out_Type_String = "PUT";
		return true;

	case HTTP_CONNECT:

		Out_Type_String = "CONNECT";
		return true;

	case HTTP_OPTIONS:

		Out_Type_String = "OPTIONS";
		return true;

	case HTTP_TRACE:

		Out_Type_String = "TRACE";
		return true;

	case HTTP_COPY:

		Out_Type_String = "COPY";
		return true;

	case HTTP_LOCK:

		Out_Type_String = "LOCK";
		return true;

	case HTTP_MKCOL:

		Out_Type_String = "MKCOL";
		return true;

	case HTTP_MOVE:

		Out_Type_String = "MOVE";
		return true;

	case HTTP_PROPFIND:

		Out_Type_String = "PROFIND";
		return true;

	case HTTP_PROPPATCH:

		Out_Type_String = "PROPPATCH";
		return true;

	case HTTP_SEARCH:

		Out_Type_String = "SEARCH";
		return true;

	case HTTP_UNLOCK:

		Out_Type_String = "UNLOCK";
		return true;

	case HTTP_BIND:

		Out_Type_String = "BIND";
		return true;

	case HTTP_REBIND:

		Out_Type_String = "REBIND";
		return true;

	case HTTP_UNBIND:

		Out_Type_String = "UNBIND";
		return true;

	case HTTP_ACL:

		Out_Type_String = "ACL";
		return true;

	case HTTP_REPORT:

		Out_Type_String = "REPORT";
		return true;

	case HTTP_MKACTIVITY:

		Out_Type_String = "MKACTIVITY";
		return true;

	case HTTP_CHECKOUT:

		Out_Type_String = "CHECKOUT";
		return true;

	case HTTP_MERGE:

		Out_Type_String = "MERGE";
		return true;

	case HTTP_MSEARCH:

		Out_Type_String = "MSEARCH";
		return true;

	case HTTP_NOTIFY:

		Out_Type_String = "NOTIFY";
		return true;

	case HTTP_SUBSCRIBE:

		Out_Type_String = "SUBSCRIBE";
		return true;

	case HTTP_UNSUBSCRIBE:

		Out_Type_String = "UNSUBSCRIBE";
		return true;

	case HTTP_PATCH:

		Out_Type_String = "PATCH";
		return true;

	case HTTP_PURGE:

		Out_Type_String = "PURGE";
		return true;

	case HTTP_MKCALENDAR:

		Out_Type_String = "MKCALENDAR";
		return true;

	case HTTP_LINK:

		Out_Type_String = "LINK";
		return true;

	case HTTP_UNLINK:

		Out_Type_String = "UNLINK";
		return true;

	case HTTP_SOURCE:

		Out_Type_String = "SOURCE";
		return true;

	case HTTP_CUSTOM_METHOD:

		Out_Type_String = "CUSTOM_METHOD";
		return true;

	default:

		Out_Type_String = "NONE";
		return false;
	}
}

// Content

bool UHttpConnectionLhv::Callback_Content_Type(http_content_type Type, ELibHvContentTypes& Out_Content_Type, FString& Out_Type_String)
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
		return false;
	}
}

http_content_type UHttpConnectionLhv::Callback_Content_Type_Convert(ELibHvContentTypes Type)
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
}

// Status

int32 UHttpConnectionLhv::Callback_Status_To_Code(ELibHvStatusCodes Status)
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
}

http_status UHttpConnectionLhv::Callback_Code_To_Status(int Status)
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
}