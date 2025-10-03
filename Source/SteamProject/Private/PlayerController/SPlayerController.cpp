

#include "PlayerController/SPlayerController.h"
#include "Character/PlayerCharacter.h"
#include "UI/GameplayWidget.h"

void ASPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	PlayerCharacter = Cast<APlayerCharacter>(InPawn);

	if (PlayerCharacter)
	{
		PlayerCharacter->ServerSideInit();
	}
}

void ASPlayerController::AcknowledgePossession(class APawn* P)
{
	Super::AcknowledgePossession(P);

	PlayerCharacter = Cast<APlayerCharacter>(P);

	if (PlayerCharacter)
	{
		PlayerCharacter->ClientSideInit();
		SpawnGameplayWidget();
	}
}

void ASPlayerController::SpawnGameplayWidget()
{
	if (!IsLocalPlayerController())
		return;

	GameplayWidget = CreateWidget<UGameplayWidget>(this, GameplayWidgetClass);
	if (GameplayWidget)
	{
		GameplayWidget->AddToViewport();
	}

	
}
