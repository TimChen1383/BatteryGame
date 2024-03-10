// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupBattery.h"

// Sets default values
APickupBattery::APickupBattery()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//All pickups start active
	bIsActivate = true;
	
	//Creat battery mesh
	PickUpBattery = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUpBatteryMesh"));
	RootComponent = PickUpBattery;

	//Enable simulate physics
	GetMesh()->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void APickupBattery::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBattery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Return current active state
bool APickupBattery::IsActive()
{
	return bIsActivate;
}

//Set new active state
void APickupBattery::SetActive(bool NewActiveState)
{
	bIsActivate = NewActiveState;
}

