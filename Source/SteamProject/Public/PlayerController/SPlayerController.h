
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UGameplayWidget;
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

	void SpawnGameplayWidget();
	
	UPROPERTY()
	TObjectPtr<APlayerCharacter> PlayerCharacter;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UGameplayWidget> GameplayWidgetClass;

	UPROPERTY()
	TObjectPtr<UGameplayWidget> GameplayWidget;

	
};
