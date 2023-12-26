namespace UnrealBuildTool.Rules
{
    using System.IO;

    public class Oatpp : ModuleRules
    {
        public Oatpp(ReadOnlyTargetRules Target) : base(Target)
        {
    		Type = ModuleType.External;
            bEnableUndefinedIdentifierWarnings = false;
            bEnableExceptions = true;
            bUseRTTI = true;

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp", "include"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp", "lib", "oatpp.lib"));

                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp-openssl", "include"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp-openssl", "lib", "oatpp-openssl.lib"));

                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp-swagger", "include"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp-swagger", "lib", "oatpp-swagger.lib"));

                PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp-zlib", "include"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Win64", "oatpp-zlib", "lib", "oatpp-zlib.lib"));
            }
        }
    }
}
