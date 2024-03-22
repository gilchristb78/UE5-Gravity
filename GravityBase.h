// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GravityBase.generated.h"

UCLASS()
class PLAYERSTUFF_API AGravityBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGravityBase();

	virtual FVector GetGravityDirection(FVector ItemLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
