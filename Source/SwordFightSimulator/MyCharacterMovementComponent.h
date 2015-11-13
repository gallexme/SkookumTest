// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class SWORDFIGHTSIMULATOR_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	UMyCharacterMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void HandleImpact(const FHitResult& Impact, float TimeSlice, const FVector& MoveDelta) override;
	
	
};
