

#include "Ability/SGameplayTags.h"

#include "GameplayTagsManager.h"

FSGameplayTags FSGameplayTags::GameplayTags;

void FSGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Ability_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Ability.Attack"), FString("공격"));
}
