
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
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
private:
	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> InitialGameplayEffects;
};
