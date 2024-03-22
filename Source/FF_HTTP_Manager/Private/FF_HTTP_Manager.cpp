// Copyright Epic Games, Inc. All Rights Reserved.

#include "FF_HTTP_Manager.h"
#include "Interfaces/IPluginManager.h"

#ifdef _WIN64
#include "errhandlingapi.h"
#include "winbase.h"
#endif // _WIN64

#define LOCTEXT_NAMESPACE "FFF_HTTP_ManagerModule"

void FFF_HTTP_ManagerModule::StartupModule()
{
#ifdef _WIN64

	const FString BasePluginDir = IPluginManager::Get().FindPlugin("FF_HTTP_MANAGER")->GetBaseDir();
	const FString DLL_Pthreads_VC2 = FPaths::Combine(*BasePluginDir, TEXT("Source/Pthreads/Win64/dll/x64/pthreadVC2.dll"));
	const FString DLL_Pthreads_GC2 = FPaths::Combine(*BasePluginDir, TEXT("Source/Pthreads/Win64/dll/x64/pthreadGC2.dll"));

	Handle_Pthreads_VC2 = FPlatformProcess::GetDllHandle(*DLL_Pthreads_VC2);
	Handle_Pthreads_GC2 = FPlatformProcess::GetDllHandle(*DLL_Pthreads_GC2);

	if (Handle_Pthreads_VC2 != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("pthreadVC2.dll loaded successfully !"));
	}

	else
	{
		DWORD DLL_Error = GetLastError();
		UE_LOG(LogTemp, Fatal, TEXT("pthreadVC2.dll failed to load ! : %d"), DLL_Error);
	}

	if (Handle_Pthreads_GC2 != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("pthreadGC2.dll loaded successfully !"));
	}

	else
	{
		DWORD DLL_Error = GetLastError();
		UE_LOG(LogTemp, Fatal, TEXT("pthreadGC2.dll failed to load ! : %d"), DLL_Error);
	}

#endif
}

void FFF_HTTP_ManagerModule::ShutdownModule()
{

#ifdef _WIN64
	FPlatformProcess::FreeDllHandle(Handle_Pthreads_VC2);
	Handle_Pthreads_VC2 = nullptr;

	FPlatformProcess::FreeDllHandle(Handle_Pthreads_GC2);
	Handle_Pthreads_GC2 = nullptr;
#endif

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFF_HTTP_ManagerModule, FF_HTTP_Manager)