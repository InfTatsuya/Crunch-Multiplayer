// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Crunch_AbilitySystemComponent.h"

void UCrunch_AbilitySystemComponent::ApplyInitialGameplayEffects()
{
	if(!GetOwner() || !GetOwner()->HasAuthority()) return;
	
	for(const TSubclassOf<UGameplayEffect>& EffectClass : InitialGameplayEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = MakeOutgoingSpec(EffectClass, 1, MakeEffectContext());
		
		ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}
