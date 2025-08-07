// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/DataObjects/ListDataObject_Value.h"
#include "ListDataObject_String.generated.h"

/**
 * 
 */
UCLASS()
class COMMONFRONT_API UListDataObject_String : public UListDataObject_Value
{
	GENERATED_BODY()
public:
	void AddDynamicOptions(const FString& InStringValue, const FText& InDisplayText);
	void AdvanceToNextOption();
	void BackToPreviousOption();
	void OnRotatorInitiatedValueChange(const FText& InNewSelectedText);
	
protected:
	virtual void OnDataObjectInitialized() override;
	virtual bool CanResetBackToDefaultValue() const override;
	virtual bool TryResetBackToDefaultValue() override;

	bool TrySetDisplayTextFromStringValue(const FString& InStringValue);
	
	FString CurrentStringValue;
	FText CurrentDisplayText;
	
	TArray<FString> AvailableOptionsStringArray;
	TArray<FText> AvailableOptionsTextArray;

public:
	FORCEINLINE const TArray<FText>& GetAvailableOptionsTextArray() const { return AvailableOptionsTextArray; }
	FORCEINLINE FText GetCurrentDisplayText() const { return CurrentDisplayText; }
};

UCLASS()
class COMMONFRONT_API UListDataObject_StringBool : public UListDataObject_String
{
	GENERATED_BODY()

public:
	void OverrideTrueDisplayText(const FText& InNewTrueDisplayText);
	void OverrideFalseDisplayText(const FText& InNewFalseDisplayText);
	void SetTrueAsDefaultValue();
	void SetFalseAsDefaultValue();

protected:
	virtual void OnDataObjectInitialized() override;
	
private:
	void TryInitBoolValues();
	
	const FString TrueString = TEXT("true");
	const FString FalseString = TEXT("false");
};

