// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/ListEntires/Widget_ListEntry_Base.h"
#include "Widget_ListEntry_KeyRemap.generated.h"

class UListDataObject_KeyRemap;
class UFrontendCommonButtonBase;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class COMMONFRONT_API UWidget_ListEntry_KeyRemap : public UWidget_ListEntry_Base
{
	GENERATED_BODY()

protected:
	virtual void OnOwningListItemObjectSet(UListDataObject_Base* InOwningListDataObject) override;
	virtual void OnOwningDependencyDataObjectModified(UListDataObject_Base* OwningModifiedDependencyData, EOptionsListDataModifyReason ModifyReason) override;

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UFrontendCommonButtonBase> CommonButton_RemapKey;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UFrontendCommonButtonBase> CommonButton_ResetKeyBinding;

	UPROPERTY(Transient)
	TObjectPtr<UListDataObject_KeyRemap> CachedOwningKeyRemapDataObject;

	
};
