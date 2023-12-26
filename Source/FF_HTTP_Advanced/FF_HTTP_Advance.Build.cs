// Some copyright should be here...

using System;
using System.IO;
using UnrealBuildTool;
public class FF_HTTP_Advance : ModuleRules
{
	public FF_HTTP_Advance(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;
        bUseRTTI = true;

        if (UnrealTargetPlatform.Win64 == Target.Platform)
        {
            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "zlib",
                    "FF_OpenSSL",
                    "FF_MBedTLS",
					"Oatpp",
                    "LibHv",
                    "IXWebSocket",
                }
                );

            // Workflow
            PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "ThirdParty", "Workflow", "Win64", "include"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "Workflow", "Win64", "lib", "workflow.lib"));
        }

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
            }
			);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Projects",		// We need it for LibHv DLL delayed load.
            }
			);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
			}
            );
	}
}