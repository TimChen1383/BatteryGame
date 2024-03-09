// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryGameGameMode.h"
#include "BatteryGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABatteryGameGameMode::ABatteryGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
