#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ELibHvStatusCodes : uint8
{
	Continue_100								UMETA(DisplayName = "Continue_100"),
	Switching_Protocols_101						UMETA(DisplayName = "Switching_Protocols_101"),
	Processing_102								UMETA(DisplayName = "Processing_102"),
	
	OK_200										UMETA(DisplayName = "OK_200"),
	Created_201									UMETA(DisplayName = "Created_201"),
	Accepted_202								UMETA(DisplayName = "Accepted_202"),
	Non_Authoratative_Information_203			UMETA(DisplayName = "Non_Authoratative_Information_203"),
	No_Content_204								UMETA(DisplayName = "No_Content_204"),
	Reset_Content_205							UMETA(DisplayName = "Reset_Content_205"),
	Partial_Content_206							UMETA(DisplayName = "Partial_Content_206"),
	Multi_Status_207							UMETA(DisplayName = "Multi_Status_207"),
	Already_Reported_208						UMETA(DisplayName = "Already_Reported_208"),
	Im_Used_226									UMETA(DisplayName = "Im_Used_226"),
	
	Multiple_Choice_300							UMETA(DisplayName = "Multiple_Choice_300"),
	Moved_Permanently_301						UMETA(DisplayName = "Moved_Permanently_301"),
	Found_302									UMETA(DisplayName = "Found_302"),
	See_Other_303								UMETA(DisplayName = "See_Other_303"),
	Not_Modified_304							UMETA(DisplayName = "Not_Modified_304"),
	Use_Proxy_305								UMETA(DisplayName = "Use_Proxy_305"),
	Temporary_Redirect_307						UMETA(DisplayName = "Temporary_Redirect_307"),
	Permanent_Redirect_308						UMETA(DisplayName = "Permanent_Redirect_308"),
	
	Bad_Request_400								UMETA(DisplayName = "Bad_Request_400"),
	Unauthorized_401							UMETA(DisplayName = "Unauthorized_401"),
	Payment_Required_402						UMETA(DisplayName = "Payment_Required_402"),
	Forbidden_403								UMETA(DisplayName = "Not_Found_404"),
	Not_Found_404								UMETA(DisplayName = "Not_Found_404"),
	Method_Not_Allowed_405						UMETA(DisplayName = "Method_Not_Allowed_405"),
	Not_Acceptable_406							UMETA(DisplayName = "Not_Acceptable_406"),
	Proxy_Authentication_Required_407			UMETA(DisplayName = "Proxy_Authentication_Required_407"),
	Request_Timeout_408							UMETA(DisplayName = "Request_Timeout_408"),
	Conflict_409								UMETA(DisplayName = "Conflict_409"),
	Gone_410									UMETA(DisplayName = "Gone_410"),
	Lenght_Required_411							UMETA(DisplayName = "Lenght_Required_411"),
	Precondition_Failed_412						UMETA(DisplayName = "Precondition_Failed_412"),
	Payload_Too_Large_413						UMETA(DisplayName = "Payload_Too_Large_413"),
	Uri_Too_Long_414							UMETA(DisplayName = "Uri_Too_Long_414"),
	Unsupported_Media_Type_415					UMETA(DisplayName = "Unsupported_Media_Type_415"),
	Range_Not_Satisfiable_416					UMETA(DisplayName = "Range_Not_Satisfiable_416"),
	Expectation_Failed_417						UMETA(DisplayName = "Expectation_Failed_417"),

	Misdirected_Request_421						UMETA(DisplayName = "Misdirected_Request_421"),
	Unprocessable_Entity_422					UMETA(DisplayName = "Unprocessable_Entity_422"),
	Locked_423									UMETA(DisplayName = "Locked_423"),
	Failed_Dependency_424						UMETA(DisplayName = "Failed_Dependency_424"),
	Upgrade_Required_426						UMETA(DisplayName = "Upgrade_Required_426"),
	Precondition_Required_428					UMETA(DisplayName = "Precondition_Required_428"),
	Too_Many_Requests_429						UMETA(DisplayName = "Too_Many_Requests_429"),
	Request_Header_Fields_Too_Large_431			UMETA(DisplayName = "Request_Header_Fields_Too_Large_431"),
	Unavailable_For_Legal_Reasons_451			UMETA(DisplayName = "Unavailable_For_Legal_Reasons_451"),

	Internal_Server_Error_500					UMETA(DisplayName = "Internal_Server_Error_500"),
	Not_Implemented_501							UMETA(DisplayName = "Not_Implemented_501"),
	Bad_Gateway_502								UMETA(DisplayName = "Bad_Gateway_502"),
	Service_Unavailable_503						UMETA(DisplayName = "Service_Unavailable_503"),
	Gateway_Timeout_504							UMETA(DisplayName = "Gateway_Timeout_504"),
	Http_Version_Not_Supported_505				UMETA(DisplayName = "Http_Version_Not_Supported_505"),
	Variant_Also_Negotiates_506					UMETA(DisplayName = "Variant_Also_Negotiates_506"),
	Insufficient_Storage_507					UMETA(DisplayName = "Insufficient_Storage_507"),
	Loop_Detected_508							UMETA(DisplayName = "Loop_Detected_508"),
	Not_Extended_510							UMETA(DisplayName = "Not_Extended_510"),
	Network_Authentication_Required_511			UMETA(DisplayName = "Network_Authentication_Required_511"),
};
ENUM_CLASS_FLAGS(ELibHvStatusCodes)

UENUM(BlueprintType)
enum class ELibHvContentTypes : uint8
{
	// Applications
	
	Application_7z				UMETA(DisplayName = "Application_7z"),
	Application_Atom			UMETA(DisplayName = "Application_Atom"),
	Application_Docx			UMETA(DisplayName = "Application_Docx"),
	Application_Eot				UMETA(DisplayName = "Application_Eot"),
	Application_Excel			UMETA(DisplayName = "Application_Excel"),
	Application_gRPC			UMETA(DisplayName = "Application_gRPC"),
	Application_gzip			UMETA(DisplayName = "Application_gzip"),
	Application_JAR				UMETA(DisplayName = "Application_JAR"),
	Application_JS				UMETA(DisplayName = "Application_JavaScript"),
	Application_Json			UMETA(DisplayName = "Application_Json"),
	Application_M3U8			UMETA(DisplayName = "Application_M3U8"),
	Application_Octet_Stream	UMETA(DisplayName = "Application_Octet_Stream"),
	Application_PDF				UMETA(DisplayName = "Application_PDF"),
	Application_PPT				UMETA(DisplayName = "Application_PPT"),
	Application_PPTX			UMETA(DisplayName = "Application_PPTX"),
	Application_RAR				UMETA(DisplayName = "Application_RAR"),
	Application_RSS				UMETA(DisplayName = "Application_RSS"),
	Application_RTF				UMETA(DisplayName = "Application_RTF"),
	Application_URLENCODED		UMETA(DisplayName = "Application_URLENCODED"),
	Application_WASM			UMETA(DisplayName = "Application_WASM"),
	Application_WORD			UMETA(DisplayName = "Application_WORD"),
	Application_XHTML			UMETA(DisplayName = "Application_XHTML"),
	Application_XLSX			UMETA(DisplayName = "Application_XLSX"),
	Application_XML				UMETA(DisplayName = "Application_XML"),
	Application_ZIP				UMETA(DisplayName = "Application_ZIP"),

	// Audio
	
	Audio_AAC					UMETA(DisplayName = "Audio_AAC"),
	Audio_M4A					UMETA(DisplayName = "Audio_M4A"),
	Audio_MP3					UMETA(DisplayName = "Audio_MP3"),
	Audio_OGG					UMETA(DisplayName = "Audio_OGG"),
	Audio_OPUS					UMETA(DisplayName = "Audio_OPUS"),
	Audio_PCMA					UMETA(DisplayName = "Audio_PCMA"),

	// Content Type
	
	Content_Type_Application	UMETA(DisplayName = "Content_Type_Application"),
	Content_Type_Audio			UMETA(DisplayName = "Content_Type_Audio"),
	Content_Type_Font			UMETA(DisplayName = "Content_Type_Font"),
	Content_Type_Image			UMETA(DisplayName = "Content_Type_Image"),
	Content_Type_Multipart		UMETA(DisplayName = "Content_Type_Multipart"),
	Content_Type_NONE			UMETA(DisplayName = "Content_Type_NONE"),
	Content_Type_Text			UMETA(DisplayName = "Content_Type_Text"),
	Content_Type_Undefined		UMETA(DisplayName = "Content_Type_Undefined"),
	Content_Type_Video			UMETA(DisplayName = "Content_Type_Video"),

	// Font

	Font_OTF					UMETA(DisplayName = "Font_OTF"),
	Font_TTF					UMETA(DisplayName = "Font_TTF"),
	Font_WOFF					UMETA(DisplayName = "Font_WOFF"),
	Font_WOFF2					UMETA(DisplayName = "Font_WOFF2"),

	// Image

	Image_BMP					UMETA(DisplayName = "Image_BMP"),
	Image_GIF					UMETA(DisplayName = "Image_GIF"),
	Image_ICO					UMETA(DisplayName = "Image_ICO"),
	Image_JPG					UMETA(DisplayName = "Image_JPG"),
	Image_PNG					UMETA(DisplayName = "Image_PNG"),
	Image_SVG					UMETA(DisplayName = "Image_SVG"),
	Image_TIFF					UMETA(DisplayName = "Image_TIFF"),
	Image_WEBP					UMETA(DisplayName = "Image_WEBP"),

	// Multi Part Form

	Multiplart_Form_Data		UMETA(DisplayName = "Multiplart_Form_Data"),

	// Text

	Text_CSS					UMETA(DisplayName = "Text_CSS"),
	Text_CSV					UMETA(DisplayName = "Text_CSV"),
	Text_Event_Stream			UMETA(DisplayName = "Text_Event_Stream"),
	Text_HTML					UMETA(DisplayName = "Text_HTML"),
	Text_Markdown				UMETA(DisplayName = "Text_Markdown"),
	Text_Plain					UMETA(DisplayName = "Text_Plain"),

	// Video

	Video_3GPP					UMETA(DisplayName = "Video_3GPP"),
	Video_ASF					UMETA(DisplayName = "Video_ASF"),
	Video_AVI					UMETA(DisplayName = "Video_AVI"),
	Video_FLV					UMETA(DisplayName = "Video_FLV"),
	Video_M4V					UMETA(DisplayName = "Video_M4V"),
	Video_MNG					UMETA(DisplayName = "Video_MNG"),
	Video_MOV					UMETA(DisplayName = "Video_MOV"),
	Video_MP4					UMETA(DisplayName = "Video_MP4"),
	Video_MPEG					UMETA(DisplayName = "Video_MPEG"),
	Video_TS					UMETA(DisplayName = "Video_TS"),
	Video_WEBM					UMETA(DisplayName = "Video_WEBM"),
	Video_WMV					UMETA(DisplayName = "Video_WMV"),

};
ENUM_CLASS_FLAGS(ELibHvContentTypes)