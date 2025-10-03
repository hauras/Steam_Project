
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CharacterBase.generated.h"

class UWidgetComponent;
class USAbilitySystemComponent;
class UAttributeSet;
UCLASS()
class STEAMPROJECT_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();
	void ServerSideInit();
	void ClientSideInit();
	bool IsLocallyControlled() const;
	
	virtual void PossessedBy(AController* NewController) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() { return AttributeSet; }
	
private:

	UPROPERTY(VisibleDefaultsOnly, Category = "Abilities")
	TObjectPtr<USAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(VisibleDefaultsOnly, Category = "UI")
	TObjectPtr<UWidgetComponent> WidgetComponent;

	void ConfigureStatusWidget();

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	float StateGaugeVisibility = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	float StateGaugeVisibilityRange = 100000.f;
	
	FTimerHandle TimerHandle;

	void UpdateGaugeVisibility();
protected:
	virtual void BeginPlay() override;

	

};
