// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataObjects/ListDataObject_StringResolution.h"

#include "CommonFront/FrontendDebugHelper.h"
#include "Kismet/KismetSystemLibrary.h"

void UListDataObject_StringResolution::InitResolutionValues()
{
	TArray<FIntPoint> AvailableResolutions ;
	
	UKismetSystemLibrary::GetSupportedFullscreenResolutions(AvailableResolutions );

	for (const FIntPoint& Resolution : AvailableResolutions)
	{
		Debug::Print(TEXT("Available Resolutions: ") + Resolution.ToString());
	}
}

void UListDataObject_StringResolution::OnDataObjectInitialized()
{
	Super::OnDataObjectInitialized();

	if (DataDynamicGetter)
	{
		Debug::Print(TEXT("UResolution Value from Dynamic Getter: ") + DataDynamicGetter->GetValueAsString());
	}
}
