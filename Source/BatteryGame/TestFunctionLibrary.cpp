// Fill out your copyright notice in the Description page of Project Settings.


#include "TestFunctionLibrary.h"

void UTestFunctionLibrary::BPCallableFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Blueprint Callable function"));
}

int UTestFunctionLibrary::BPPureFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Blueprint Pure function"));
	return 4; 
}

int UTestFunctionLibrary::BPCallablePureFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Blueprint Callable Pure function"));
	return 5;

}
