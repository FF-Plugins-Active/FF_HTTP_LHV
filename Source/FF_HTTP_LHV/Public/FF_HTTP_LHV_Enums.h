#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHttpContentTypeLhv : uint8
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
ENUM_CLASS_FLAGS(EHttpContentTypeLhv)