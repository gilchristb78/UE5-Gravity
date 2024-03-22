// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityBox.h"

AGravityBox::AGravityBox()
{

	// Create BoxComponent
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetLineThickness(10.0f);
	RootComponent = CollisionBox;


	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent); // Attach to the root component or another appropriate component
	ArrowComponent->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f)); // Rotate arrow to point downward

}

FVector AGravityBox::GetGravityDirection(FVector ItemLocation)
{
	return GetActorUpVector() * -1;
}
