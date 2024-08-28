// Some copyright should be here...

using System;
using System.IO;
using UnrealBuildTool;
public class FF_HTTP_LHV : ModuleRules
{
	public FF_HTTP_LHV(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
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
            }
		);
	}
}