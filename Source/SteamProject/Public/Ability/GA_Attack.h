
#pragma once

#include "CoreMinimal.h"
#include "Ability/SGameplayAbility.h"
#include "GA_Attack.generated.h"

/**
 * 
 */
UCLASS()
class STEAMPROJECT_API UGA_Attack : public USGameplayAbility
{
	GENERATED_BODY()
public:
	UGA_Attack();
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	static FGameplayTag GetAttackEventTag();
	static FGameplayTag GetAttackEventEndTag();
	
private:
	void SetupWaitAttackInputPress();

	UFUNCTION()
	void HandleInputPress(float TimeWaited);

	void TryCommitAttack();
	
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	TObjectPtr<UAnimMontage> AttackMontage;

	UFUNCTION()
	void AttackEventReceived(FGameplayEventData Data);

	FName NextAttackName;
};
