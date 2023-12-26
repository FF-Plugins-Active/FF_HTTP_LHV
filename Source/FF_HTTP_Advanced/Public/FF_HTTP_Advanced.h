// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

#define LIBHV_SHARED 1

class FFF_HTTP_AdvancedModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#if defined(_WIN64) && LIBHV_SHARED == 1
	void* Libhv_Handle;
#endif

};
