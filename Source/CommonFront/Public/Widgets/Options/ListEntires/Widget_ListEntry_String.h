// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/ListEntires/Widget_ListEntry_Base.h"
#include "Widget_ListEntry_String.generated.h"

class UListDataObject_String;
class UFrontendCommonRotator;
class UFrontendCommonButtonBase;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class COMMONFRONT_API UWidget_ListEntry_String : public UWidget_ListEntry_Base
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	
	
	virtual void OnOwningListItemObjectSet(UListDataObject_Base* InOwningListDataObject) override;

private:
	void OnPreviousOptionButtonClicked();
	void OnNextOptionButtonClicked();
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UFrontendCommonButtonBase> CommonButton_PreviousOption;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UFrontendCommonRotator> CommonRotator_AvailableOptions;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UFrontendCommonButtonBase> CommonButton_NextOption;

	UPROPERTY(Transient)
	TObjectPtr<UListDataObject_String> CachedOwningStringDataObject;
};
