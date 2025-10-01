

#include "PlayerController/SPlayerController.h"
#include "Character/PlayerCharacter.h"

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
	}
}
