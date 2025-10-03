

#include "UI/WidgetController/SWidgetController.h"

void USWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void USWidgetController::BroadcastInitialValues()
{
}

void USWidgetController::BindCallbacksToDependencies()
{
}
