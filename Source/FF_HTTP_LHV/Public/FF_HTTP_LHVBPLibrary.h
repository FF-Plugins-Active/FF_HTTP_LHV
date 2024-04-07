// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

// Custom Includes.
#include "FF_HTTP_LHV_Enums.h"

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#include "hv/HttpServer.h"
#include "hv/hthread.h"    // import hv_gettid
#include "hv/hasync.h"     // import hv::async
#include "hv/requests.h"   // import requests::async
#endif
THIRD_PARTY_INCLUDES_END

#include "FF_HTTP_LHVBPLibrary.generated.h"

UCLASS()
class UFF_HTTP_LHVBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LibHv - Status To Int", ToolTip = "", Keywords = "convert, http, status, code, int"), Category = "Frozen Forest|HTTP|Server|LibHv")
	static FF_HTTP_LHV_API int32 LibHv_Status_To_Int(ELibHvStatusCodes Status);

	static FF_HTTP_LHV_API http_status LibHv_Int_To_Status(int Status);

	static FF_HTTP_LHV_API http_content_type LibHv_Type_Bp_To_Original(ELibHvContentTypes Type);
};