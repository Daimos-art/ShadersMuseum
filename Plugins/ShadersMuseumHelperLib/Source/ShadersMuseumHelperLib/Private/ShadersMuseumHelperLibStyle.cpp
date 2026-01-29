// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShadersMuseumHelperLibStyle.h"
#include "ShadersMuseumHelperLib.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FShadersMuseumHelperLibStyle::StyleInstance = nullptr;

void FShadersMuseumHelperLibStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FShadersMuseumHelperLibStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FShadersMuseumHelperLibStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ShadersMuseumHelperLibStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FShadersMuseumHelperLibStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("ShadersMuseumHelperLibStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("ShadersMuseumHelperLib")->GetBaseDir() / TEXT("Resources"));

	Style->Set("ShadersMuseumHelperLib.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FShadersMuseumHelperLibStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FShadersMuseumHelperLibStyle::Get()
{
	return *StyleInstance;
}
