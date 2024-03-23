// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GravityBase.h"
#include "Components/SphereComponent.h" 
#include "GravityPoint.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERSTUFF_API AGravityPoint : public AGravityBase
{
	GENERATED_BODY()

public:

	AGravityPoint();

	virtual FVector GetGravityDirection(FVector ItemLocation) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* GravityCenterMesh; // Mesh component to visualize gravity direction

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* CollisionSphere; // Collision box component
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	bool InverseGravity;
};
