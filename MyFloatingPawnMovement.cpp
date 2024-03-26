// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFloatingPawnMovement.h"

UMyFloatingPawnMovement::UMyFloatingPawnMovement()
{

}

void UMyFloatingPawnMovement::AddGravity(float DeltaTime)
{
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

	if (OwningActor && GravityDirection != FVector::ZeroVector)
	{
		FHitResult OutHit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(OwningActor);

		FVector Location = OwningActor->GetActorLocation();
		UCapsuleComponent* capsule = OwningActor->GetComponentByClass<UCapsuleComponent>();

		if (capsule)
		{
			Location -= OwningActor->GetActorUpVector() * capsule->GetScaledCapsuleHalfHeight();
		}

		GetWorld()->LineTraceSingleByChannel(OutHit, Location, Location + GravityDirection * 10, ECC_Visibility, Params);

		if (!OutHit.bBlockingHit) //only add gravity if we arent on the ground
			AddInputVector(GravityDirection);
	}
}

void UMyFloatingPawnMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AddGravity(DeltaTime);
}
