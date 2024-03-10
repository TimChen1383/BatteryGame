// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBatteryVolume.h"

#include "Components/BoxComponent.h"
#include "PickupBattery.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASpawnBatteryVolume::ASpawnBatteryVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create battery spawn volume
	BatterySpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BatterySpawnBox"));
	RootComponent = BatterySpawnBox;

	//Set spawn delay range
	SpawnDelayrangeLow = 1.0f;
	SpawnDelayrangeHigh = 5.0f;

}

// Called when the game starts or when spawned
void ASpawnBatteryVolume::BeginPlay()
{
	Super::BeginPlay();

	//Set up first spawn delay when begin play
	SpawnDelay = FMath::FRandRange(SpawnDelayrangeLow, SpawnDelayrangeHigh);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnBatteryVolume::SpawnBattery, SpawnDelay, false);
}

// Called every frame
void ASpawnBatteryVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnBatteryVolume::GetRandomSpawnLoc()
{
	FVector SpawnOrigin = BatterySpawnBox->Bounds.Origin;
	FVector SpawnExtend = BatterySpawnBox->Bounds.BoxExtent;
	SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtend);
	return SpawnLocation;
}

void ASpawnBatteryVolume::SpawnBattery()
{
	//Need to check the spawn item has been attached
	if (SpawnItem)
	{
	//Check valid world
		UWorld* const World = GetWorld();
		if(World)
		{
			//Set spawn parameter
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			//SpawnParams.Instigator = Instigator;

			//Get random location to spawn
			FVector RandSpawnLocation = GetRandomSpawnLoc();

			//Get random rotation for spawn actor
			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;

			
			//Spawn new the pick up battery actor. Every new spawned Battery actor will keep spawning another new battery actor with delay
			APickupBattery* const SpawnedPickupBattery = World->SpawnActor<APickupBattery>(SpawnItem, RandSpawnLocation, SpawnRotation, SpawnParams);
			SpawnDelay = FMath::FRandRange(SpawnDelayrangeLow, SpawnDelayrangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnBatteryVolume::SpawnBattery, SpawnDelay, false);
			
		}


	}
}

