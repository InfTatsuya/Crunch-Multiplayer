// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Crunch_Character.generated.h"

class UCrunch_AttributeSet;
class UCrunch_AbilitySystemComponent;

UCLASS()
class ACrunch_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACrunch_Character();

	void ServerSideInit();
	void ClientSideInit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/*********************************************************/
	/*					Gameplay Ability					*/
	/*********************************************************/
public:

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Ability System")
	TObjectPtr<UCrunch_AbilitySystemComponent> CrunchAbilitySystemComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCrunch_AttributeSet> CrunchAttributeSet;
};
