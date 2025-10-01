

#include "Character/CharacterBase.h"
#include "Ability/SAbilitySystemComponent.h"
#include "Ability/SAttributeSet.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	AbilitySystemComponent = CreateDefaultSubobject<USAbilitySystemComponent>("Ability System Component");
	AttributeSet = CreateDefaultSubobject<USAttributeSet>("Attribute Set");
}

void ACharacterBase::ServerSideInit()
{
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
	AbilitySystemComponent->ApplyInitialEffects();
}

void ACharacterBase::ClientSideInit()
{
	AbilitySystemComponent->InitAbilityActorInfo(this,this);

}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
