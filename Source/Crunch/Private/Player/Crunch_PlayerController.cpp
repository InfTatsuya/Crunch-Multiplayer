// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Crunch_PlayerController.h"
#include "Crunch_PlayerCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/GameplayWidget.h"

void ACrunch_PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	CachedPlayerCharacter = Cast<ACrunch_PlayerCharacter>(InPawn);
	if(CachedPlayerCharacter)
	{
		CachedPlayerCharacter->ServerSideInit();
	}
}

void ACrunch_PlayerController::AcknowledgePossession(class APawn* InPawn)
{
	Super::AcknowledgePossession(InPawn);

	CachedPlayerCharacter = Cast<ACrunch_PlayerCharacter>(InPawn);
	if(CachedPlayerCharacter)
	{
		CachedPlayerCharacter->ClientSideInit();
		SpawnGameplayWidget();
	}
}

void ACrunch_PlayerController::SpawnGameplayWidget()
{
	if(!IsLocalPlayerController()) return;

	if(GameplayWidgetClass->IsValidLowLevelFast())
	{
		GameplayWidget = CreateWidget<UGameplayWidget>(this, GameplayWidgetClass);
		if(GameplayWidget)
		{
			GameplayWidget->AddToViewport();
		}
	}
}

