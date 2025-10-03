
#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/SWidgetController.h"
#include "SOverlayWidgetController.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float);

/**
 * 
 */
UCLASS()
class STEAMPROJECT_API USOverlayWidgetController : public USWidgetController
{
	GENERATED_BODY()
public:

	/*virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	FOnAttributeChangedSignature OnHealthChanged;
	FOnAttributeChangedSignature OnMaxHealthChanged;
	FOnAttributeChangedSignature OnManaChanged;
	FOnAttributeChangedSignature OnMaxManaChanged;*/
};
