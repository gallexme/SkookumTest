// Fill out your copyright notice in the Description page of Project Settings.

#include "SwordFightSimulator.h"
#include "MyCharacterMovementComponent.h"




UMyCharacterMovementComponent::UMyCharacterMovementComponent(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
:UCharacterMovementComponent(ObjectInitializer)
{

}

void UMyCharacterMovementComponent::HandleImpact(const FHitResult& Impact, float TimeSlice, const FVector& MoveDelta)
{
	if (CharacterOwner)
	{
		CharacterOwner->MoveBlockedBy(Impact);
	}

	/*if (PathFollowingComp.IsValid())
	{	// Also notify path following!
		PathFollowingComp->OnMoveBlockedBy(Impact);
	}*/

	APawn* OtherPawn = Cast<APawn>(Impact.GetActor());
	if (OtherPawn)
	{
		NotifyBumpedPawn(OtherPawn);
	}

	
	const FVector ForceAccel = Acceleration + (IsFalling() ? FVector(0.f, 0.f, GetGravityZ()) : FVector::ZeroVector);
	ApplyImpactPhysicsForces(Impact, ForceAccel, Velocity);
	
}
