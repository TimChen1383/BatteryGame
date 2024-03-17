// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBattery.generated.h"

UCLASS()
class BATTERYGAME_API APickupBattery : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBattery();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Function that help us get current mesh
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickUpBattery; }

	//Get current active status
	UFUNCTION(BlueprintPure, Category="Battery")
	bool IsActive();

	//Set new active status
	UFUNCTION(BlueprintCallable, Category="Battery")
	void SetActive(bool NewActiveState);

	
	//Static mesh that represent the battery
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Battery")
	class UStaticMeshComponent* PickUpBattery;

	//Add collect custom event. Cll the event when this object has been collected
	UFUNCTION(BlueprintCallable)
	void WasCollected();


protected:
	//True when it can be picked up, false when it can't be picked up 
	bool bIsActivate;

};
