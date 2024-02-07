// Some copyright should be here...

using System;
using System.IO;
using UnrealBuildTool;
public class FF_HTTP_Manager : ModuleRules
{
	public FF_HTTP_Manager(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableUndefinedIdentifierWarnings = false;
        bEnableExceptions = true;
        bUseRTTI = true;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "zlib",
                "OpenSSL",      // We don't need OpenSSL certificate functions
                "nghttp2",      // We need it for LibCurl
                "libcurl",
            }
            );

        if (UnrealTargetPlatform.Win64 == Target.Platform)
        {
            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "FF_MBedTLS",
					"Oatpp", 
                }
                );

            // Workflow
            PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "ThirdParty", "Workflow", "Win64", "include"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "ThirdParty", "Workflow", "Win64", "lib", "workflow.lib"));
        }
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Projects",		// We need it for LibHv DLL delayed load.
                "HTTP",
                "HTTPServer",
                "LibWebSocket",
                "IXWebSocket",
            }
			);
	}
}