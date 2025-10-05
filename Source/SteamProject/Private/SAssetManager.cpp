

#include "SAssetManager.h"

#include "Ability/SGameplayTags.h"

USAssetManager& USAssetManager::Get()
{
	check(GEngine);

	USAssetManager* SAssetManager = Cast<USAssetManager>(GEngine->AssetManager);
	return *SAssetManager;
}

void USAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FSGameplayTags::InitializeNativeGameplayTags();
}
