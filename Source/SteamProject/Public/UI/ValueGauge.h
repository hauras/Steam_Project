
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttributeSet.h"
#include "GameplayEffectTypes.h"
#include "ValueGauge.generated.h"

class UAbilitySystemComponent;
class UTextBlock;
class UProgressBar;

/**
 * 
 */
UCLASS()
class STEAMPROJECT_API UValueGauge : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	void SetValue(float Value, float NewMaxValue);

	void SetAttribute(UAbilitySystemComponent* AS, const FGameplayAttribute& Attribute, const FGameplayAttribute& MaxAttribute);

private:

	void ValueChanged(const FOnAttributeChangeData& Data);
	void MaxValueChanged(const FOnAttributeChangeData& Data);

	float CachedValue;
	float CachedMaxValue;
	
	UPROPERTY(EditAnywhere, Category = "Visual")
	FLinearColor ValueColor;
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	TObjectPtr<UTextBlock> ValueText;


	
};
