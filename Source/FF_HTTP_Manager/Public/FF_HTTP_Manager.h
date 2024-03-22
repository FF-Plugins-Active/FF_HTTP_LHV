// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FFF_HTTP_ManagerModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#ifdef _WIN64
	void* Handle_Pthreads_VC2 = nullptr;
	void* Handle_Pthreads_GC2 = nullptr;
#endif

};
