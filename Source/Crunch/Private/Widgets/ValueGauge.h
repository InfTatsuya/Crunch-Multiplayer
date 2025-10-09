// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
//#include "GameplayEffectTypes.h"
#include "ValueGauge.generated.h"

struct FGameplayAttribute;
struct FOnAttributeChangeData;
class UAbilitySystemComponent;
class UTextBlock;
class UProgressBar;
/**
 * 
 */
UCLASS()
class CRUNCH_API UValueGauge : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativePreConstruct() override;
	void SetValue(float NewValue, float NewMaxValue);
	void SetAndBoundToGameplayAttribute(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayAttribute& Attribute, const FGameplayAttribute& MaxAttribute);

private:

	void ValueChanged(const FOnAttributeChangeData& AttributeChangeData);
	void MaxValueChanged(const FOnAttributeChangeData& AttributeChangeData);

	float CachedValue;
	float CachedMaxValue;

	UPROPERTY(EditAnywhere, Category = "Visual")
	FLinearColor BarColor;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> ValueText;
};
