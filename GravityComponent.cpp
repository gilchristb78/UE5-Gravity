// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityComponent.h"
#include "Math/RotationMatrix.h"


// Sets default values for this component's properties
UGravityComponent::UGravityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGravityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGravityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	AActor* OwningActor = GetOwner();


	TArray<AActor*> OverlappingActors;
	OwningActor->GetOverlappingActors(OverlappingActors, AGravityBase::StaticClass());

	
	if (OverlappingActors.Num() > 0)
	{
		AGravityBase* GravityZone = Cast<AGravityBase>(OverlappingActors[0]);

		if (GravityZone->GetGravityDirection(OwningActor->GetActorLocation()) != GravityDirection)
		{

			GravityDirection = GravityZone->GetGravityDirection(OwningActor->GetActorLocation());

			FRotator rotation = FRotationMatrix::MakeFromZX(GravityDirection * -1.0f, OwningActor->GetActorForwardVector()).Rotator();
			OwningActor->SetActorRotation(rotation);

		}
	}
	else
	{
		GravityDirection = FVector::ZeroVector;
	}

	if (OwningActor)
	{
		FVector location = OwningActor->GetActorLocation();

		location += GravityDirection * 500 * DeltaTime;

		FHitResult OutHit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(OwningActor);

		DrawDebugLine(GetWorld(), OwningActor->GetActorLocation() - GravityDirection, location, FColor::Red);

		GetWorld()->LineTraceSingleByChannel(OutHit, OwningActor->GetActorLocation() - GravityDirection, location, ECC_Visibility, Params);

		if (OutHit.bBlockingHit)
		{
			location = OutHit.Location;
		}

		OwningActor->SetActorLocation(location);
		
	}
}

