// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBattery.h"
#include "GameFramework/Actor.h"
#include "SpawnBatteryVolume.generated.h"

UCLASS()
class BATTERYGAME_API ASpawnBatteryVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnBatteryVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Choose the spawn actor. Only Pickup Battery can be spawned with this volume
	UPROPERTY(EditAnywhere, Category="Battery")
	TSubclassOf<APickupBattery>SpawnItem;

	
	//Random location inside spawn volume
	FVector SpawnLocation;

	//retuen battery spawn box
	class UBoxComponent* GetBatterySpawnBox() const { return BatterySpawnBox; };
	
	//Get random location in volume for spawning battery
	UFUNCTION(BlueprintPure, Category="Battery")
	FVector GetRandomSpawnLoc();
	
	//Create battery spawn volume
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Battery")
	class UBoxComponent* BatterySpawnBox;

	//Spawn Battery actor with delay. Every new spawned Battery actor will keep spawning another new battery actor with delay
	FTimerHandle SpawnTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Battery")
	float SpawnDelayrangeLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Battery")
	float SpawnDelayrangeHigh;
	float SpawnDelay;

	void SpawnBattery();

};
