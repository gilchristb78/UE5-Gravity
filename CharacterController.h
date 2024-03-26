// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterPawn.h"
#include "GameFramework/PlayerController.h"
#include "CharacterController.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERSTUFF_API ACharacterController : public APlayerController
{
	GENERATED_BODY()
	

public:

	ACharacterController();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	void CallMoveRight(float val);

	void CallMoveForward(float val);

	void CallJump(float val);
	void CallJump();

	void CallLookRight(float val);

	void CallLookUp(float val);

	void CallLeanRight(float val);
};
