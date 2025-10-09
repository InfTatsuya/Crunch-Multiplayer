// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Crunch_PlayerController.generated.h"

class ACrunch_PlayerCharacter;
/**
 * 
 */
UCLASS()
class ACrunch_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	//only call on client, or host
	virtual void AcknowledgePossession(class APawn* InPawn) override;

protected:

	// only call on server by engine
	virtual void OnPossess(APawn* InPawn) override;

private:

	UPROPERTY()
	TObjectPtr<ACrunch_PlayerCharacter> CachedPlayerCharacter; 
	
};
