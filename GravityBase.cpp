// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityBase.h"

// Sets default values
AGravityBase::AGravityBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

FVector AGravityBase::GetGravityDirection(FVector ItemLocation)
{
	return FVector::DownVector;
}

// Called when the game starts or when spawned
void AGravityBase::BeginPlay()
{
	Super::BeginPlay();
	
}


