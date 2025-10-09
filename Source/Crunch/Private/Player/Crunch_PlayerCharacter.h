// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Crunch_Character.h"
#include "Crunch_PlayerCharacter.generated.h"

struct FInputActionValue;
class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class ACrunch_PlayerCharacter : public ACrunch_Character
{
	GENERATED_BODY()

public:

	ACrunch_PlayerCharacter();
	
	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(VisibleAnywhere, Category = "View")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "View")
	TObjectPtr<UCameraComponent> ViewCam;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> GameplayInputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Move Config")
	float MoveSpeed = 1.f;

	void HandlingLookInput(const FInputActionValue& InputValue);
	void HandlingMoveInput(const FInputActionValue& InputValue);

	FVector GetLookRightVector() const;
	FVector GetLookForwardVector() const;
	FVector GetForwardMoveVector() const;
	
	
};
