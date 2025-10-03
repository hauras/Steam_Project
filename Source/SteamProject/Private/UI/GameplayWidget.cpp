

#include "UI/GameplayWidget.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "UI/ValueGauge.h"
#include "Ability/SAttributeSet.h"

void UGameplayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwningPlayerPawn());
	if (AbilitySystemComponent)
	{
		HealthBar->SetAttribute(AbilitySystemComponent, USAttributeSet::GetHealthAttribute(), USAttributeSet::GetMaxHealthAttribute());
		ManaBar->SetAttribute(AbilitySystemComponent, USAttributeSet::GetManaAttribute(), USAttributeSet::GetMaxManaAttribute());

	}

}
