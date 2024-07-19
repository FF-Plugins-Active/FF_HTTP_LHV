// Some copyright should be here...

using System;
using System.IO;
using UnrealBuildTool;
public class FF_HTTP_LHV : ModuleRules
{
	public FF_HTTP_LHV(ReadOnlyTargetRules Target) : base(Target)
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
                "FF_MBedTLS",
                "LibHv",
            }
        );
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "Projects",
            }
		);
	}
}