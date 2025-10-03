

#include "UI/ValueGauge.h"

#include "Ability/SAttributeSet.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h" 
#include "AbilitySystemComponent.h"

void UValueGauge::NativePreConstruct()
{
	Super::NativePreConstruct();
	ProgressBar->SetFillColorAndOpacity(ValueColor);
}

void UValueGauge::SetValue(float Value, float NewMaxValue)
{
	CachedValue = Value;
	CachedMaxValue = NewMaxValue;
	
	if (NewMaxValue == 0)
	{
		return;
	}

	float NewPercent = Value / NewMaxValue;
	ProgressBar->SetPercent(NewPercent);

	FNumberFormattingOptions FormattingOptions = FNumberFormattingOptions().SetMaximumFractionalDigits(0);

	ValueText->SetText(
		FText::Format(
			FTextFormat::FromString("{0}/{1}"),
			FText::AsNumber(Value, &FormattingOptions),
			FText::AsNumber(NewMaxValue, &FormattingOptions)
		)
	); 
}

void UValueGauge::SetAttribute(UAbilitySystemComponent* AS, const FGameplayAttribute& Attribute,
	const FGameplayAttribute& MaxAttribute)
{
	if (AS)
	{
		bool bFound;
		float Value = AS->GetGameplayAttributeValue(Attribute, bFound);
		float MaxValue = AS->GetGameplayAttributeValue(MaxAttribute, bFound);
		if (bFound)
		{
			SetValue(Value, MaxValue);
		}
		AS->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &UValueGauge::ValueChanged);
		AS->GetGameplayAttributeValueChangeDelegate(MaxAttribute).AddUObject(this, &UValueGauge::MaxValueChanged);

	}
}

void UValueGauge::ValueChanged(const FOnAttributeChangeData& Data)
{
	SetValue(Data.NewValue, CachedMaxValue);
}

void UValueGauge::MaxValueChanged(const FOnAttributeChangeData& Data)
{
	SetValue(CachedMaxValue, Data.NewValue);

}

