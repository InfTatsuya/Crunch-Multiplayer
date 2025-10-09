// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayWidget.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "ValueGauge.h"
#include "GAS/Crunch_AttributeSet.h"

void UGameplayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	OwnerAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwningPlayerPawn());
	if(OwnerAbilitySystemComponent)
	{
		HealthBar->SetAndBoundToGameplayAttribute(OwnerAbilitySystemComponent, UCrunch_AttributeSet::GetHealthAttribute(), UCrunch_AttributeSet::GetMaxHealthAttribute());
		ManaBar->SetAndBoundToGameplayAttribute(OwnerAbilitySystemComponent, UCrunch_AttributeSet::GetManaAttribute(), UCrunch_AttributeSet::GetMaxManaAttribute());
	}
	
	
}
