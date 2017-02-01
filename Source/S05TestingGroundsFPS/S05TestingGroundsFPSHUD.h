// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "S05TestingGroundsFPSHUD.generated.h"

UCLASS()
class AS05TestingGroundsFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	AS05TestingGroundsFPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

