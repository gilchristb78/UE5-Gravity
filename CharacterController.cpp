// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"


ACharacterController::ACharacterController()
{
	

}

void ACharacterController::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &ACharacterController::CallMoveRight);
	InputComponent->BindAxis("MoveForward", this, &ACharacterController::CallMoveForward);
	InputComponent->BindAxis("Jump", this, &ACharacterController::CallJump);
	InputComponent->BindAxis("LookRight", this, &ACharacterController::CallLookRight);
	InputComponent->BindAxis("LookUp", this, &ACharacterController::CallLookUp);
	InputComponent->BindAxis("LeanRight", this, &ACharacterController::CallLeanRight);
}

void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterController::CallMoveRight(float val)
{
	if (ACharacterPawn* pawn = Cast<ACharacterPawn>(GetPawn()))
	{
		pawn->MoveXAxis(val);
	}
}

void ACharacterController::CallMoveForward(float val)
{
	if (ACharacterPawn* pawn = Cast<ACharacterPawn>(GetPawn()))
	{
		pawn->MoveYAxis(val);
	}
}

void ACharacterController::CallJump(float val)
{
	if (ACharacterPawn* pawn = Cast<ACharacterPawn>(GetPawn()))
	{
		pawn->MoveZAxis(val);
	}
}

void ACharacterController::CallLookRight(float val)
{
	if (ACharacterPawn* pawn = Cast<ACharacterPawn>(GetPawn()))
	{
		pawn->LookXAxis(val);
	}
}

void ACharacterController::CallLookUp(float val)
{
	if (ACharacterPawn* pawn = Cast<ACharacterPawn>(GetPawn()))
	{
		pawn->LookYAxis(val);
	}
}

void ACharacterController::CallLeanRight(float val)
{
	if (ACharacterPawn* pawn = Cast<ACharacterPawn>(GetPawn()))
	{
		pawn->LookZAxis(val);
	}
}
