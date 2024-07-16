// Copyright Epic Games, Inc. All Rights Reserved.

#include "FF_HTTP_LHV.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FFF_HTTP_LHVModule"

void FFF_HTTP_LHVModule::StartupModule()
{
	/*
	const FString DLL_Path = FPaths::Combine(*IPluginManager::Get().FindPlugin("FF_HTTP_LHV")->GetBaseDir(), TEXT("Source/LibHv/Win64/lib/hv.dll"));

	if (!FPaths::FileExists(DLL_Path))
	{
		UE_LOG(LogTemp, Fatal, TEXT("hv.dll couldn't be found at given location !"));
		return;
	}

	this->Libhv_Handle = FPlatformProcess::GetDllHandle(*DLL_Path);

	if (this->Libhv_Handle != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("hv.dll loaded successfully for FF_HTTP_LHV plugin."));
		return;
	}

	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("hv.dll failed to load for FF_HTTP_LHV plugin !"));
		return;
	}
	*/
}

void FFF_HTTP_LHVModule::ShutdownModule()
{
	/*
	if (this->Libhv_Handle)
	{
		FPlatformProcess::FreeDllHandle(this->Libhv_Handle);
		this->Libhv_Handle = nullptr;
	}
	*/
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFF_HTTP_LHVModule, FF_HTTP_LHV)