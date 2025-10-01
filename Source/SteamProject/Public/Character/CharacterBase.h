
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CharacterBase.generated.h"

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
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() { return AttributeSet; }
	
private:

	UPROPERTY(VisibleDefaultsOnly, Category = "Abilities")
	TObjectPtr<USAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


};
