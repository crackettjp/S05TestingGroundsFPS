// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "S05TestingGroundsFPS.h"
#include "S05TestingGroundsFPSGameMode.h"
#include "S05TestingGroundsFPSHUD.h"
#include "S05TestingGroundsFPSCharacter.h"

AS05TestingGroundsFPSGameMode::AS05TestingGroundsFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05TestingGroundsFPSHUD::StaticClass();
}
