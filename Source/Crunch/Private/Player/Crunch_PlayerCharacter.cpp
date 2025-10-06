// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Crunch_PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ACrunch_PlayerCharacter::ACrunch_PlayerCharacter()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->bUsePawnControlRotation = true;
	
	ViewCam = CreateDefaultSubobject<UCameraComponent>(TEXT("View Cam"));
	ViewCam->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	bUseControllerRotationYaw = false;
}

void ACrunch_PlayerCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();

	if(APlayerController* OwningPlayerController = GetController<APlayerController>())
	{
		UEnhancedInputLocalPlayerSubsystem* InputSubSystem = OwningPlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		if(InputSubSystem && GameplayInputMappingContext)
		{
			InputSubSystem->RemoveMappingContext(GameplayInputMappingContext);
			InputSubSystem->AddMappingContext(GameplayInputMappingContext, 0);
		}
	}
}

void ACrunch_PlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EnhancedInputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if(JumpInputAction->IsValidLowLevel())
		{
			EnhancedInputComp->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ACrunch_PlayerCharacter::Jump);
		}

		if(LookInputAction->IsValidLowLevel())
		{
			EnhancedInputComp->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &ThisClass::HandlingLookInput);
		}
	}
}

void ACrunch_PlayerCharacter::HandlingLookInput(const FInputActionValue& InputValue)
{
	FVector2D InputVal = InputValue.Get<FVector2D>();

	AddControllerPitchInput(InputVal.Y);
	AddControllerYawInput(InputVal.X);
}
