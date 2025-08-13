// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FrontendLoadingScreenSettings.generated.h"

/**
 * 
 */
UCLASS(config = Engine, DefaultConfig)
class COMMONFRONT_API UFrontendLoadingScreenSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	TSubclassOf<UUserWidget> GetLoadingScreenWidgetClassChecked() const;
	
	UPROPERTY(Config, EditAnywhere, Category = "Loading Screent Settings")
	TSoftClassPtr<UUserWidget> SoftLoadingScreenWidgetClass;

	UPROPERTY(Config, EditAnywhere, Category = "Loading Screent Settings")
	float HoldLoadingScreenExtrasSeconds = 3.f;

	UPROPERTY(Config, EditAnywhere, Category = "Loading Screent Settings")
	bool bShouldLoadingScreenInEditor = false;
};
