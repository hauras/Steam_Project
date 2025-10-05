

#include "Ability/GA_Attack.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
UGA_Attack::UGA_Attack()
{

}

void UGA_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                 const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (!K2_CommitAbility())
	{
		K2_EndAbility();
		return;
	}

	if (HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		UAbilityTask_PlayMontageAndWait* PlayAttackMontage = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, NAME_None, AttackMontage);
		PlayAttackMontage->OnBlendOut.AddDynamic(this, &UGA_Attack::K2_EndAbility);
		PlayAttackMontage->OnCancelled.AddDynamic(this, &UGA_Attack::K2_EndAbility);
		PlayAttackMontage->OnCompleted.AddDynamic(this, &UGA_Attack::K2_EndAbility);
		PlayAttackMontage->OnInterrupted.AddDynamic(this, &UGA_Attack::K2_EndAbility);
		PlayAttackMontage->ReadyForActivation();
	}
}
