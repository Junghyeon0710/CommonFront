#pragma once
#include "CoreMinimal.h"
#include "FrontendStructTypes.generated.h"


USTRUCT(BlueprintType)
struct FOptionsDataEditConditionDescriptor
{
	GENERATED_BODY()

public:
	void SetEditConditionFunc(TFunction<bool()> InEditConditionFunc)
	{
		EditConditionFunc = InEditConditionFunc;
	}

	bool IsValid() const
	{
		return EditConditionFunc != nullptr;
	}

	bool IsEditConditionMet() const
	{
		if (IsValid())
		{
			return EditConditionFunc();
		}
		return true;
	}

	FString GetDisabledRichReason() const
	{
		return DisabledRichReason;
	}
	void SetDisabledRichReason(FString InDisabledRichReason)
	{
		DisabledRichReason = InDisabledRichReason;
	}

	bool HasForcedStringValue() const
	{
		return DisabledForcedStringValue.IsSet();
	}
	FString GetDisabledForcedStringValue() const
	{
		return DisabledForcedStringValue.GetValue();
	}
	void SetDisabledForcedStringValue(const FString& InDisabledForcedStringValue)
	{
		DisabledForcedStringValue = InDisabledForcedStringValue;
	}
	
private:
	TFunction<bool()> EditConditionFunc;
	FString DisabledRichReason;
	TOptional<FString> DisabledForcedStringValue;
	
};