namespace UnrealBuildTool.Rules
{
    using System.IO;

    public class LibHv : ModuleRules
    {
        public LibHv(ReadOnlyTargetRules Target) : base(Target)
        {
    		Type = ModuleType.External;
            bEnableUndefinedIdentifierWarnings = false;
            bEnableExceptions = true;
            bUseRTTI = true;

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                //PublicDefinitions.Add("HV_STATICLIB");

                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "include"));
                //PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "hv_static.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "hv.lib"));
                RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries", "Win64", "hv.dll"));
                //RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "hv.dll"));
                //PublicDelayLoadDLLs.Add("hv.dll");
            }
        }
    }
}
