// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShadersMuseumHelperLib.h"
#include "ShadersMuseumHelperLibStyle.h"
#include "ShadersMuseumHelperLibCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "EditorUtilitySubsystem.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "Editor.h"

static const FName ShadersMuseumHelperLibTabName("ShadersMuseumHelperLib");

#define LOCTEXT_NAMESPACE "FShadersMuseumHelperLibModule"

void FShadersMuseumHelperLibModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FShadersMuseumHelperLibStyle::Initialize();
	FShadersMuseumHelperLibStyle::ReloadTextures();

	FShadersMuseumHelperLibCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FShadersMuseumHelperLibCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FShadersMuseumHelperLibModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FShadersMuseumHelperLibModule::RegisterMenus));
}

void FShadersMuseumHelperLibModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FShadersMuseumHelperLibStyle::Shutdown();

	FShadersMuseumHelperLibCommands::Unregister();
}

void FShadersMuseumHelperLibModule::PluginButtonClicked()
{
	FString WidgetPath = TEXT("/ShadersMuseumHelperLib/EUW_ShaderHelperLib.EUW_ShaderHelperLib"); //Renseigne le chemin menant vers l'EditorWidget que l'on souhaite jouer. Attention, suivre les règles concernant la nomenclature.
	UEditorUtilityWidgetBlueprint* WidgetBP = LoadObject<UEditorUtilityWidgetBlueprint>(nullptr, *WidgetPath); //On crée une variable dans laquel on load l'EditorWidhet créer
	if (WidgetBP) //On vérifie si le widget est bien valide.
	{
		if (UEditorUtilitySubsystem* EditorSubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>()) //On va cherche l'EditorUtilitySubsystem qui possède des fonctions permettant de gérer les Tabs
		{
			EditorSubsystem->SpawnAndRegisterTab(WidgetBP); //On utilise le subsystem pour exécuter le spawn du widget.
		}
	}
}

void FShadersMuseumHelperLibModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FShadersMuseumHelperLibCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FShadersMuseumHelperLibCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FShadersMuseumHelperLibModule, ShadersMuseumHelperLib)