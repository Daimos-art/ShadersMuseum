// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/Commands/Commands.h"
#include "ShadersMuseumHelperLibStyle.h"

class FShadersMuseumHelperLibCommands : public TCommands<FShadersMuseumHelperLibCommands>
{
public:

	FShadersMuseumHelperLibCommands()
		: TCommands<FShadersMuseumHelperLibCommands>(TEXT("ShadersMuseumHelperLib"), NSLOCTEXT("Contexts", "ShadersMuseumHelperLib", "ShadersMuseumHelperLib Plugin"), NAME_None, FShadersMuseumHelperLibStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
