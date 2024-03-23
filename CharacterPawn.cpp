// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPawn.h"
#include "GravityBox.h"


// Sets default values
ACharacterPawn::ACharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Character = CreateDefaultSubobject<USkeletalMeshComponent>("Character");
	Character->SetupAttachment(RootComponent);
	Character->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>("CollisionCapsule");
	CollisionCapsule->SetupAttachment(RootComponent);

	//Camera
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(Character);
	OurCamera->SetRelativeLocation(FVector(0.0f, -275.0f, 150.0f));
	OurCamera->SetRelativeRotation(FRotator(-15.0f, 90.0f, 0.0f));

}

// Called when the game starts or when spawned
void ACharacterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (velocity != FVector::ZeroVector)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation += (velocity.X * DeltaTime * GetActorRightVector() * 10);
		NewLocation += (velocity.Y * DeltaTime * GetActorForwardVector() * 10);
		NewLocation += (velocity.Z * DeltaTime * GetActorUpVector() * 10); //split up so we can check

		FHitResult OutHit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		float checkHeight = CollisionCapsule->GetScaledCapsuleHalfHeight() / 8;

		DrawDebugLine(GetWorld(), NewLocation + GetActorUpVector() * checkHeight, NewLocation - GetActorUpVector() * checkHeight, FColor::Red);

		GetWorld()->LineTraceSingleByChannel(OutHit, NewLocation + GetActorUpVector() * checkHeight, NewLocation - GetActorUpVector() * checkHeight, ECC_Visibility, Params);

		if (OutHit.bBlockingHit)
		{
			DrawDebugSphere(GetWorld(), OutHit.Location, 5, 5, FColor::Green);
			NewLocation = OutHit.Location;
		}
		SetActorLocation(NewLocation);

	}

	if (rotVelocity != FVector::ZeroVector)
	{
		FRotator NewRotation = FRotator::ZeroRotator;
		NewRotation.Yaw += rotVelocity.X * DeltaTime;
		AddActorLocalRotation(NewRotation);

		NewRotation = OurCamera->GetRelativeRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + (rotVelocity.Y * DeltaTime), -60.0f, 60.0f);
		OurCamera->SetRelativeRotation(NewRotation);

		NewRotation = FRotator::ZeroRotator;
		NewRotation.Roll = rotVelocity.Z * DeltaTime;
		AddActorLocalRotation(NewRotation);

	}
}

void ACharacterPawn::MoveXAxis(float val)
{
	velocity.X = val * 100.0f;
}

void ACharacterPawn::MoveYAxis(float val)
{
	
	velocity.Y = val * 100.0f;
}

void ACharacterPawn::MoveZAxis(float val)
{
	if (val >= 0.0f)
		velocity.Z = val * 100.0f;
}

void ACharacterPawn::LookXAxis(float val)
{
	rotVelocity.X = val * 90;
}

void ACharacterPawn::LookYAxis(float val)
{
	rotVelocity.Y = val * 90;
}

void ACharacterPawn::LookZAxis(float val)
{
	rotVelocity.Z = val * 90;
}

// Called to bind functionality to input
void ACharacterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

