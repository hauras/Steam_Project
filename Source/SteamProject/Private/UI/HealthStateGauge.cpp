

#include "UI/HealthStateGauge.h"
#include "AbilitySystemComponent.h"
#include "UI/ValueGauge.h"
#include "Ability/SAttributeSet.h"

void UHealthStateGauge::ConfigureASC(class UAbilitySystemComponent* AS)
{
	if (AS)
	{
		HealthBar->SetAttribute(AS, USAttributeSet::GetHealthAttribute(), USAttributeSet::GetMaxHealthAttribute());
		ManaBar->SetAttribute(AS, USAttributeSet::GetManaAttribute(), USAttributeSet::GetMaxManaAttribute());

	}
}
