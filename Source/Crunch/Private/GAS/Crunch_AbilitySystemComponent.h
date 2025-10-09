// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Crunch_AbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class UCrunch_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:

	void ApplyInitialGameplayEffects();

private:

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effects")
	TArray<TSubclassOf<UGameplayEffect>> InitialGameplayEffects;
};
