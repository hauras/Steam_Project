
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayWidget.generated.h"

class UAbilitySystemComponent;
class UValueGauge;

/**
 * 
 */
UCLASS()
class STEAMPROJECT_API UGameplayWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;
protected:

private:

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UValueGauge> HealthBar;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UValueGauge> ManaBar;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	
};
