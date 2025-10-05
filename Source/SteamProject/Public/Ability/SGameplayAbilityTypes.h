
#pragma once

#include "CoreMinimal.h"
#include "SGameplayAbilityTypes.generated.h"

UENUM(BlueprintType)
enum class ESAbilityInputID : uint8
{
	None				UMETA(DisplayName = "None"),
	Attack				UMETA(DisplayName = "Attack"),
	AbilityOne			UMETA(DisplayName = "AbilityOne"),
	AbilityTwo			UMETA(DisplayName = "AbilityTwo"),
	AbilityThree		UMETA(DisplayName = "AbilityThree"),
	AbilityFour			UMETA(DisplayName = "AbilityFour"),
	AbilityFive			UMETA(DisplayName = "AbilityFive"),
	AbilitySix			UMETA(DisplayName = "AbilitySix"),
	Confirm				UMETA(DisplayName = "Confirm"),
	Cancel				UMETA(DisplayName = "Cancel"),
};
/**
 * 
 */
