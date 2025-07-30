// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "FrontendDeveloperSettings.generated.h"

class UWidget_ActivatableBase;
/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Frontend UI Settings"))
class COMMONFRONT_API UFrontendDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	// ForceInlineRow : 같은줄에 나타내기 위해 강제로 
	UPROPERTY(config, EditAnywhere, Category = "Widget Reference", meta = (ForceInlineRow, Categories = "Frontend.Widget"))
	TMap<FGameplayTag, TSoftClassPtr<UWidget_ActivatableBase>> FrontendWidgetMap; 
};
