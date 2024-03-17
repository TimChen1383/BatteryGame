// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYGAME_API UTestFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BPCallableFunction();

	UFUNCTION(BlueprintPure)
	int BPPureFunction();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int BPCallablePureFunction();


	UFUNCTION(BlueprintImplementableEvent)
	void NotifyQuestActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void BPCallableImplementEvent();


};
