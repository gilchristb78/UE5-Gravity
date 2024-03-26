// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterMovement.h"

// Sets default values for this component's properties
UMyCharacterMovement::UMyCharacterMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UMyCharacterMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyCharacterMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ComputeVelocity(DeltaTime);

	ComputerPosition(DeltaTime);
	// ...
}

void UMyCharacterMovement::AddForwardMovement(float val)
{
	Acceleration.Y = val * 100;
}

void UMyCharacterMovement::AddRightMovement(float val)
{
	Acceleration.X = val * 100;
}

void UMyCharacterMovement::AddUpMovement(float val)
{
	Acceleration.Z = val * 100;
}

void UMyCharacterMovement::ComputerPosition(float DeltaTime)
{
	if (Velocity != FVector::ZeroVector)
	{
		AActor* OwningActor = GetOwner();
		FVector Location = OwningActor->GetActorLocation();

		Location += (Velocity.X * DeltaTime * OwningActor->GetActorRightVector());
		OwningActor->SetActorLocation(Location);
		if (IsOverlapping(OwningActor))
		{
			Location -= (Velocity.X * DeltaTime * OwningActor->GetActorRightVector());
			Velocity.X = 0;
		}

		Location += (Velocity.Y * DeltaTime * OwningActor->GetActorForwardVector());
		OwningActor->SetActorLocation(Location);
		if (IsOverlapping(OwningActor))
		{
			Location -= (Velocity.Y * DeltaTime * OwningActor->GetActorForwardVector());
			Velocity.Y = 0;
		}
			

		Location += (Velocity.Z * DeltaTime * OwningActor->GetActorUpVector());
		OwningActor->SetActorLocation(Location);
		if (IsOverlapping(OwningActor))
		{
			Location -= (Velocity.Z * DeltaTime * OwningActor->GetActorUpVector());
			Velocity.Z = 0;
		}
		OwningActor->SetActorLocation(Location);
	}
}

void UMyCharacterMovement::ComputeVelocity(float DeltaTime)
{
	if (Acceleration != FVector::ZeroVector)
	{
		//Player Inputs
		Velocity += Acceleration * DeltaTime;
	}
	else
	{
		Velocity *= .9f;
	}

	if (GetGravity() != FVector::ZeroVector)
		Velocity.Z -= 10000 * DeltaTime;

	//will be replaced once mass and friction are added (likely)
	Velocity.X = FMath::Clamp(Velocity.X, -MaxSpeed, MaxSpeed);
	Velocity.Y = FMath::Clamp(Velocity.Y, -MaxSpeed, MaxSpeed);
	Velocity.Z = FMath::Clamp(Velocity.Z, -MaxSpeed, MaxSpeed);
}

FVector UMyCharacterMovement::GetGravity()
{
	AActor* OwningActor = GetOwner();

	TArray<AActor*> OverlappingGravities;
	OwningActor->GetOverlappingActors(OverlappingGravities, AGravityBase::StaticClass());

	if (OverlappingGravities.Num() > 0)
	{
		AGravityBase* GravityActor = Cast<AGravityBase>(OverlappingGravities[0]);

		FVector GravityDirection = GravityActor->GetGravityDirection(OwningActor->GetActorLocation());
		FRotator rotation = FRotationMatrix::MakeFromZX(GravityDirection * -1.0f, OwningActor->GetActorForwardVector()).Rotator();
		OwningActor->SetActorRotation(rotation);

		return GravityDirection;
	}

	return FVector::ZeroVector;
}

bool UMyCharacterMovement::IsOverlapping(AActor* Actor)
{
	TArray<AActor*> OverlappingActors;
	Actor->GetOverlappingActors(OverlappingActors);
	

	for (AActor* OverlappingActor : OverlappingActors)
	{
		if (!OverlappingActor->IsA(AGravityBase::StaticClass()))
		{
			return true;
		}
			
	}

	return false;
}

