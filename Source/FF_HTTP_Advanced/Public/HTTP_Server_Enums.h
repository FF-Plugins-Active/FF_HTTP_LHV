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