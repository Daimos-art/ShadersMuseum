// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShadersMuseumHelperLibCommands.h"

#define LOCTEXT_NAMESPACE "FShadersMuseumHelperLibModule"

void FShadersMuseumHelperLibCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ShadersMuseumHelperLib", "Execute ShadersMuseumHelperLib action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
