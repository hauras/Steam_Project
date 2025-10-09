

#include "Ability/GA_Attack.h"

#include "AbilitySystemComponent.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"
#include "Abilities/Tasks/AbilityTask_WaitInputPress.h"
#include "GameplayTagsManager.h"

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

		UAbilityTask_WaitGameplayEvent* WaitAttackEventTask = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, GetAttackEventTag(), nullptr, false, false);
		WaitAttackEventTask->EventReceived.AddDynamic(this, &UGA_Attack::AttackEventReceived);
		WaitAttackEventTask->ReadyForActivation();
	}

	SetupWaitAttackInputPress();
}

FGameplayTag UGA_Attack::GetAttackEventTag()
{
	return FGameplayTag::RequestGameplayTag("Event");
}

FGameplayTag UGA_Attack::GetAttackEventEndTag()
{
	return FGameplayTag::RequestGameplayTag("Event.End");
}

void UGA_Attack::SetupWaitAttackInputPress()
{
	UAbilityTask_WaitInputPress* WaitInputPress = UAbilityTask_WaitInputPress::WaitInputPress(this);
	WaitInputPress->OnPress.AddDynamic(this, &UGA_Attack::HandleInputPress);
	WaitInputPress->ReadyForActivation();
}

void UGA_Attack::HandleInputPress(float TimeWaited)
{
	SetupWaitAttackInputPress();
	TryCommitAttack();
}

void UGA_Attack::TryCommitAttack()
{
	
	if (NextAttackName == NAME_None)
	{
		return;
	}

	UAnimInstance* OwnerAnim = GetOwnerAnimInstance();
	if (!OwnerAnim)
	{
		return;
	}
	OwnerAnim->Montage_SetNextSection(OwnerAnim->Montage_GetCurrentSection(AttackMontage), NextAttackName, AttackMontage);
}

void UGA_Attack::AttackEventReceived(FGameplayEventData Data)
{
	FGameplayTag EventTag = Data.EventTag;
	
	if (EventTag == GetAttackEventEndTag())
	{
		//  "End" 태그가 맞으면, NextAttackName을 비우고 함수를 종료합니다.
		NextAttackName = NAME_None;
		return;
	}
    
	// "End" 태그가 아니라면, "Event" 부모 태그를 가졌는지 확인합니다.
	if(EventTag.MatchesTag(GetAttackEventTag()))
	{
		TArray<FName> TagNames;
		UGameplayTagsManager::Get().SplitGameplayTagFName(EventTag, TagNames);
		if (TagNames.Num() > 0)
		{
			// "Event.Attack2" -> "Attack2"를 추출하여 저장합니다.
			NextAttackName = TagNames.Last();
		}
	}
}
