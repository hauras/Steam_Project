
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthStateGauge.generated.h"

class UValueGauge;
/**
 * 
 */
UCLASS()
class STEAMPROJECT_API UHealthStateGauge : public UUserWidget
{
	GENERATED_BODY()
public:
	void ConfigureASC(class UAbilitySystemComponent* AS);
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UValueGauge> HealthBar;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UValueGauge> ManaBar;
};
