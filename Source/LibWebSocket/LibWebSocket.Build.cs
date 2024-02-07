namespace UnrealBuildTool.Rules
{
    using System.IO;

    public class LibWebSocket : ModuleRules
    {
        public LibWebSocket(ReadOnlyTargetRules Target) : base(Target)
        {
    		Type = ModuleType.External;
            bEnableUndefinedIdentifierWarnings = false;
            bEnableExceptions = true;
            bUseRTTI = true;

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "include"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "websockets_static.lib"));

                /*
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "websockets.lib"));
                RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Win64", "lib", "websockets.dll"));
                PublicDelayLoadDLLs.Add("websockets.dll");
                */
            }
        }
    }
}
