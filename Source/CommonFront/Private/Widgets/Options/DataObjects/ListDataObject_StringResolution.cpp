// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataObjects/ListDataObject_StringResolution.h"

#include "CommonFront/FrontendDebugHelper.h"
#include "FrontendSettings/FrontendGameUserSettings.h"
#include "Kismet/KismetSystemLibrary.h"

void UListDataObject_StringResolution::InitResolutionValues()
{
	TArray<FIntPoint> AvailableResolutions;
	
	UKismetSystemLibrary::GetSupportedFullscreenResolutions(AvailableResolutions);

	AvailableResolutions.Sort([](const FIntPoint& A, const FIntPoint& B)
	{
		return A.SizeSquared() < B.SizeSquared();
	});

	for (const FIntPoint& Resolution : AvailableResolutions)
	{
		AddDynamicOptions(ResToValueString(Resolution), ResToDisplayText(Resolution));
	}

	MaximumAllowedResolution = ResToValueString(AvailableResolutions.Last());

	SetDefaultValueFromString(MaximumAllowedResolution);
}

void UListDataObject_StringResolution::OnDataObjectInitialized()
{
	Super::OnDataObjectInitialized();

	if (!TrySetDisplayTextFromStringValue(CurrentStringValue))
	{
		CurrentDisplayText = ResToDisplayText(UFrontendGameUserSettings::Get()->GetScreenResolution());
	}
}

FString UListDataObject_StringResolution::ResToValueString(const FIntPoint& InResolution) const
{
	return FString::Printf(TEXT("(X=%i,Y=%i)"), InResolution.X, InResolution.Y);
}

FText UListDataObject_StringResolution::ResToDisplayText(const FIntPoint& InResolution) const
{
	const FString DisplayString = FString::Printf(TEXT("%i x %i"), InResolution.X, InResolution.Y);

	return FText::FromString(DisplayString);
}
