// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AoHGameMode.h"
#include "AoHPlayerController.h"
#include "AoHPawn.h"

AAoHGameMode::AAoHGameMode()
{
	// no pawn by default
	DefaultPawnClass = AAoHPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AAoHPlayerController::StaticClass();
}
