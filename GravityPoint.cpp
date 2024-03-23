// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityPoint.h"

AGravityPoint::AGravityPoint()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	RootComponent = CollisionSphere;

	GravityCenterMesh = CreateDefaultSubobject<UStaticMeshComponent>("GravityCenter");
	GravityCenterMesh->SetupAttachment(RootComponent);

}

FVector AGravityPoint::GetGravityDirection(FVector ItemLocation)
{
	FVector gravityDirection = GetActorLocation() - ItemLocation;
	gravityDirection.Normalize();
	gravityDirection *= ((!InverseGravity) * 2) - 1;
	return gravityDirection;
}
