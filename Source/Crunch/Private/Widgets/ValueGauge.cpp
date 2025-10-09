// Fill out your copyright notice in the Description page of Project Settings.


#include "ValueGauge.h"

#include "AbilitySystemComponent.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UValueGauge::NativePreConstruct()
{
	Super::NativePreConstruct();

	ProgressBar->SetFillColorAndOpacity(BarColor);
}

void UValueGauge::SetValue(float NewValue, float NewMaxValue)
{
	if(NewMaxValue == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("ValueGauge Name: %s with Max Value is zero"), *GetName());
		return;
	}

	CachedValue = NewValue;
	CachedMaxValue = NewMaxValue;

	float NewPercentage = NewValue / NewMaxValue;
	ProgressBar->SetPercent(NewPercentage);

	FNumberFormattingOptions FormattingOptions = FNumberFormattingOptions().SetMaximumFractionalDigits(0);
	ValueText->SetText(
		FText::Format(FTextFormat::FromString("{0}/{1}"), FText::AsNumber(NewValue, &FormattingOptions), FText::AsNumber(NewMaxValue, &FormattingOptions)));
}

void UValueGauge::SetAndBoundToGameplayAttribute(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayAttribute& Attribute, const FGameplayAttribute& MaxAttribute)
{
	if(AbilitySystemComponent)
	{
		bool bFound = false;
		float Value = AbilitySystemComponent->GetGameplayAttributeValue(Attribute, bFound);
		float MaxValue = AbilitySystemComponent->GetGameplayAttributeValue(MaxAttribute, bFound);
		if(bFound)
		{
			SetValue(Value, MaxValue);
		}

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &ThisClass::ValueChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MaxAttribute).AddUObject(this, &ThisClass::MaxValueChanged);
	}
}

void UValueGauge::ValueChanged(const FOnAttributeChangeData& AttributeChangeData)
{
	SetValue(AttributeChangeData.NewValue, CachedMaxValue);
}

void UValueGauge::MaxValueChanged(const FOnAttributeChangeData& AttributeChangeData)
{
	SetValue(CachedValue, AttributeChangeData.NewValue);
}
