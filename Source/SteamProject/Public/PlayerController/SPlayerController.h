
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class APlayerCharacter;
/**
 * 
 */
UCLASS()
class STEAMPROJECT_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void OnPossess(APawn* InPawn) override;

	void AcknowledgePossession(class APawn* P) override;
private:

	UPROPERTY()
	TObjectPtr<APlayerCharacter> PlayerCharacter;
};
