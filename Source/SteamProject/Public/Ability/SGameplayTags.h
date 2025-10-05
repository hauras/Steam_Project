#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FSGameplayTags
{
public:
	static const FSGameplayTags& Get() { return GameplayTags;}
	static void InitializeNativeGameplayTags();

	FGameplayTag Ability_Attack;
	
private:
	static FSGameplayTags GameplayTags;
};
