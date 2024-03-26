// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GravityBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "MyFloatingPawnMovement.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERSTUFF_API UMyFloatingPawnMovement : public UFloatingPawnMovement
{
	GENERATED_BODY()

public:

	UMyFloatingPawnMovement();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:

	void AddGravity(float DeltaTime);

	FVector GravityDirection = FVector::DownVector;
};
