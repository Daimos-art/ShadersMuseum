// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShadersMuseumHelperLib : ModuleRules
{
	public ShadersMuseumHelperLib(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {

            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Projects",
                "InputCore",
                "EditorFramework",
                "UnrealEd",
                "ToolMenus",
                "CoreUObject",
                "Engine",
                "UMGEditor",
                "Slate",
                "SlateCore",
                "Blutility",
                "EditorSubsystem",
                "EditorScriptingUtilities",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
