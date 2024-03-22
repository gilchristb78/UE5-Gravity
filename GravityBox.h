// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GravityBase.h"
#include "Components/ArrowComponent.h" 
#include "Components/BoxComponent.h" 
#include "GravityBox.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERSTUFF_API AGravityBox : public AGravityBase
{
	GENERATED_BODY()
	

public:

	AGravityBox();

	virtual FVector GetGravityDirection(FVector ItemLocation) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UArrowComponent* ArrowComponent; // Arrow component to visualize gravity direction

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* CollisionBox; // Collision box component

};
