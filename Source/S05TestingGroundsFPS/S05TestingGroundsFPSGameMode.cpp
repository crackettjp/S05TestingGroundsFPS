// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "S05TestingGroundsFPS.h"
#include "S05TestingGroundsFPSGameMode.h"
#include "Player/TestingGroundsHUD.h"
#include "Player/FirstPersonCharacter.h"

AS05TestingGroundsFPSGameMode::AS05TestingGroundsFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundsHUD::StaticClass();
}
