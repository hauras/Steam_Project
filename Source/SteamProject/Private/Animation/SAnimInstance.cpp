

#include "Animation/SAnimInstance.h"
#include "Character/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void USAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation(); 

	OwnerPlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
	if (OwnerPlayerCharacter)
	{
		OwnerMovementComponent = OwnerPlayerCharacter->GetCharacterMovement();
	}
}


void USAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds); 

	if (!OwnerPlayerCharacter || !OwnerMovementComponent)
	{
		return;
	}

	GroundSpeed = OwnerPlayerCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwnerMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
	bIsJumping = OwnerMovementComponent->IsFalling();
}
