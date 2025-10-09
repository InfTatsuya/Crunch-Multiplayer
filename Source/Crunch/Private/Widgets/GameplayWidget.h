// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayWidget.generated.h"

class UAbilitySystemComponent;
class UValueGauge;
/**
 * 
 */
UCLASS()
class CRUNCH_API UGameplayWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

private:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UValueGauge> HealthBar;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UValueGauge> ManaBar;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> OwnerAbilitySystemComponent = nullptr;
};
