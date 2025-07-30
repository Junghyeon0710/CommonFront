// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FrontendUISubsystem.generated.h"

class UWidget_ActivatableBase;
class UWidget_PrimaryLayout;

enum class EAsyncPushWidgetState : uint8
{
	OnCreatedBeforePush,
	AfterPush
};
/**
 * 
 */
UCLASS()
class COMMONFRONT_API UFrontendUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static UFrontendUISubsystem* Get(const UObject* WorldContextObject);


	/** USubsystem Interface */
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	/** ~USubsystem Interface */

	UFUNCTION(BlueprintCallable)
	void RegisterCreatedPrimaryLayout(UWidget_PrimaryLayout* InCreateWidget);

	
	void PushSoftWidgetToStackAynsc(const FGameplayTag& InWidgetStack, TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass, TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)> AysncPushStateCallback);
private:
	UPROPERTY(Transient)
	TObjectPtr<UWidget_PrimaryLayout> CreatedPrimaryLayout;
};
