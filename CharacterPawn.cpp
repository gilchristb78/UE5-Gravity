// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPawn.h"
#include "GravityBox.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACharacterPawn::ACharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Character = CreateDefaultSubobject<USkeletalMeshComponent>("Character");
	Character->SetupAttachment(RootComponent);
	Character->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	//Camera
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
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
		NewLocation += (velocity.X * DeltaTime * GetActorRightVector() * 30);
		NewLocation += (velocity.Y * DeltaTime * GetActorForwardVector() * 30);
		NewLocation += (velocity.Z * DeltaTime * GetActorUpVector() * 30);
		SetActorLocation(NewLocation);
	}

}

void ACharacterPawn::MoveXAxis(float AxisValue)
{
	velocity.X = AxisValue * 100.0f;
}

void ACharacterPawn::MoveYAxis(float AxisValue)
{
	velocity.Y = AxisValue * 100.0f;
}

void ACharacterPawn::MoveZAxis(float AxisValue)
{
	velocity.Z = AxisValue * 100.0f;
}

// Called to bind functionality to input
void ACharacterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

