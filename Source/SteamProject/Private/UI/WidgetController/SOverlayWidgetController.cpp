

#include "UI/WidgetController/SOverlayWidgetController.h"

#include "Ability/SAttributeSet.h"
/*
void USOverlayWidgetController::BroadcastInitialValues()
{
	const USAttributeSet* AS = CastChecked<USAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AS->GetHealth());
	OnMaxHealthChanged.Broadcast(AS->GetMaxHealth());
	OnManaChanged.Broadcast(AS->GetMana());
	OnMaxManaChanged.Broadcast(AS->GetMaxMana());}

void USOverlayWidgetController::BindCallbacksToDependencies()
{
	Super::BindCallbacksToDependencies();

	const USAttributeSet* AS = CastChecked<USAttributeSet>(AttributeSet);

	// 1. AbilitySystemComponent의 'Health' 어트리뷰트 변경 델리게이트를 가져옵니다.
	// 2. AddLambda를 사용해, 값이 바뀔 때마다 실행될 코드를 등록(바인딩)합니다.
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			// 3. GAS로부터 값이 바뀌었다는 신호를 받으면, 우리의 델리게이트로 UI에 다시 방송합니다.
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);
	
	// 나머지 어트리뷰트들도 똑같이 구독 신청을 합니다.
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
	);
}*/
