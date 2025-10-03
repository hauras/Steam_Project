
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SWidgetController.generated.h"
class UAttributeSet;
class UAbilitySystemComponent;
USTRUCT()
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
	: PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS) {}

	TObjectPtr<APlayerController> PlayerController = nullptr;
	TObjectPtr<APlayerState> PlayerState = nullptr;
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};
/**
 * 
 */
UCLASS()
class STEAMPROJECT_API USWidgetController : public UObject
{
	GENERATED_BODY()
public:

	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);
	
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:
	TObjectPtr<APlayerController> PlayerController;
	TObjectPtr<APlayerState> PlayerState;
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
