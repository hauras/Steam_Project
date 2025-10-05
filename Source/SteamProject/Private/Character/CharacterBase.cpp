

#include "Character/CharacterBase.h"
#include "Ability/SAbilitySystemComponent.h"
#include "Ability/SAttributeSet.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HealthStateGauge.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	AbilitySystemComponent = CreateDefaultSubobject<USAbilitySystemComponent>("Ability System Component");
	AttributeSet = CreateDefaultSubobject<USAttributeSet>("Attribute Set");

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>("Widget Component");
	WidgetComponent->SetupAttachment(GetRootComponent());
}

void ACharacterBase::ServerSideInit()
{
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
	AbilitySystemComponent->ApplyInitialEffects();
	AbilitySystemComponent->GiveInitAbility();
}

void ACharacterBase::ClientSideInit()
{
	AbilitySystemComponent->InitAbilityActorInfo(this,this);

}

bool ACharacterBase::IsLocallyControlled() const
{
	return GetController() != nullptr && GetController()->IsLocalPlayerController();
}

void ACharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (NewController && !NewController->IsPlayerController())
	{
		ServerSideInit();
	}
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterBase::ConfigureStatusWidget()
{
	if (!WidgetComponent)
	{
		return;
	}
	if (IsLocallyControlled())
	{
		WidgetComponent->SetHiddenInGame(true);
		return;
	}
	UHealthStateGauge* StateGauge = Cast<UHealthStateGauge>(WidgetComponent->GetUserWidgetObject());
	if (StateGauge)
	{
		StateGauge->ConfigureASC(GetAbilitySystemComponent());
		WidgetComponent->SetHiddenInGame(false);
		GetWorldTimerManager().ClearTimer(TimerHandle);
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ACharacterBase::UpdateGaugeVisibility, StateGaugeVisibility, true);
	}
}

void ACharacterBase::UpdateGaugeVisibility()
{
	APawn* LocalPlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (LocalPlayerPawn)
	{
		float DistSquared = FVector::DistSquared(GetActorLocation(), LocalPlayerPawn->GetActorLocation());
		WidgetComponent->SetHiddenInGame(DistSquared > StateGaugeVisibilityRange);
	}
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	ConfigureStatusWidget();
}
