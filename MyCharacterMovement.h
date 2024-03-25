// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GravityBase.h"
#include "Components/CapsuleComponent.h"
#include "MyCharacterMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLAYERSTUFF_API UMyCharacterMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyCharacterMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddForwardMovement(float val);
	void AddRightMovement(float val);
	void AddUpMovement(float val);

	float MaxSpeed;

private:

	void ComputerPosition(float DeltaTime);
	void ComputeVelocity(float DeltaTime);
	FVector Acceleration = FVector::ZeroVector;
	FVector Velocity = FVector::ZeroVector;
	FVector GetGravity();
	bool IsOverlapping(AActor* Actor);
};
