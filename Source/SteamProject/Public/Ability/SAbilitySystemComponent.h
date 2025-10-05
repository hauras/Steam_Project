
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Ability/SGameplayAbilityTypes.h"
#include "SAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class STEAMPROJECT_API USAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void ApplyInitialEffects();
	void GiveInitAbility();
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> InitialGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TMap<ESAbilityInputID ,TSubclassOf<UGameplayAbility>> BaseAbilities; // 기본 공격
	
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TMap<ESAbilityInputID,TSubclassOf<UGameplayAbility>> Abilities; // 스킬

	


};
