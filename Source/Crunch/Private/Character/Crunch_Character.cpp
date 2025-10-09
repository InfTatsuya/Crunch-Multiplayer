// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Crunch_Character.h"

#include "GAS/Crunch_AbilitySystemComponent.h"
#include "GAS/Crunch_AttributeSet.h"

// Sets default values
ACrunch_Character::ACrunch_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CrunchAbilitySystemComp = CreateDefaultSubobject<UCrunch_AbilitySystemComponent>(TEXT("Ability System Component"));
	CrunchAttributeSet = CreateDefaultSubobject<UCrunch_AttributeSet>(TEXT("Attribute Set"));
}

void ACrunch_Character::ServerSideInit()
{
	CrunchAbilitySystemComp->InitAbilityActorInfo(this, this);
	CrunchAbilitySystemComp->ApplyInitialGameplayEffects();
}

void ACrunch_Character::ClientSideInit()
{
	CrunchAbilitySystemComp->InitAbilityActorInfo(this, this);
}

// Called when the game starts or when spawned
void ACrunch_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrunch_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACrunch_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACrunch_Character::GetAbilitySystemComponent() const
{
	return CrunchAbilitySystemComp;
}

