

#include "Ability/SAbilitySystemComponent.h"

void USAbilitySystemComponent::ApplyInitialEffects()
{
	if (!GetOwner() || !GetOwner()->HasAuthority())
		return;
	
	for (const TSubclassOf<UGameplayEffect>& EffectClass : InitialGameplayEffects)
	{
		FGameplayEffectSpecHandle EffectSpecHandle = MakeOutgoingSpec(EffectClass, 1, MakeEffectContext());
		ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}
