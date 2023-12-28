#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHttpServers : uint8
{
	Server_Oatpp			UMETA(DisplayName = "Oatpp"),
	Server_Workflow			UMETA(DisplayName = "Workflow"),
	Server_LibHv			UMETA(DisplayName = "LibHv"),
	Server_IxWebSocket		UMETA(DisplayName = "IxWebSokcet"),
};
ENUM_CLASS_FLAGS(EHttpServers)

UENUM(BlueprintType)
enum class EHttpRequestTypes : uint8
{
	None	UMETA(DisplayName = "None"),
	GET		UMETA(DisplayName = "Get"),
	POST	UMETA(DisplayName = "Post"),
	PUT		UMETA(DisplayName = "Put"),
	DEL		UMETA(DisplayName = "Delete"),
};
ENUM_CLASS_FLAGS(EHttpRequestTypes)

UENUM(BlueprintType)
enum class EMailServers : uint8
{
	Gmail		UMETA(DisplayName = "Gmail"),
	Outlook		UMETA(DisplayName = "Outlook"),
	Office365	UMETA(DisplayName = "Office 365")
};
ENUM_CLASS_FLAGS(EMailServers)

UENUM(BlueprintType)
enum class EMailSecurity : uint8
{
	NoSecurity	UMETA(DisplayName = "No Security"),
	TLS			UMETA(DisplayName = "TLS"),
	StartTLS	UMETA(DisplayName = "Start TLS")
};
ENUM_CLASS_FLAGS(EMailSecurity)