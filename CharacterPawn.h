// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "CharacterPawn.generated.h"


UCLASS()
class PLAYERSTUFF_API ACharacterPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACharacterPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Robot")
	USkeletalMeshComponent* Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	UCapsuleComponent* CollisionCapsule;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveXAxis(float val);
	void MoveYAxis(float val);
	void MoveZAxis(float val);
	void LookXAxis(float val);
	FVector velocity = FVector::ZeroVector;
	FVector rotVelocity = FVector::ZeroVector;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
