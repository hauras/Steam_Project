
#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SGameplayAbility.generated.h"

class UAnimInstance;
/**
 * 
 */
UCLASS()
class STEAMPROJECT_API USGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UAnimInstance* GetOwnerAnimInstance() const;
};
