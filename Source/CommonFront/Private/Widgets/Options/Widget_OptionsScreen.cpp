// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/Widget_OptionsScreen.h"

#include "ICommonInputModule.h"
#include "CommonFront/FrontendDebugHelper.h"
#include "Input/CommonUIInputTypes.h"
#include "Widgets/Components/FrontendTabListWidgetBase.h"
#include "Widgets/Options/OptionsDataRegistry.h"
#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"

void UWidget_OptionsScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!ResetAction.IsNull())
	{
		ResetActionHandle = RegisterUIActionBinding(FBindUIActionArgs(ResetAction, true, FSimpleDelegate::CreateUObject(this, &ThisClass::OnResetBoundActionTriggered)));
	}

	RegisterUIActionBinding(FBindUIActionArgs(ICommonInputModule::GetSettings().GetDefaultBackAction(), true, FSimpleDelegate::CreateUObject(this, &ThisClass::OnBackBoundActionTriggered)));

	TabListWidget_OptionsTabs->OnTabSelected.AddUniqueDynamic(this, &ThisClass::OnOptionsTabSelected);
}

void UWidget_OptionsScreen::NativeOnActivated()
{
	Super::NativeOnActivated();

	for (UListDataObject_Collection* TabCollection : GetOrCreateDataRegistry()->GetRegisteredOptionsTabCollections())
	{
		if (!TabCollection)
		{
			continue;
		}

		const FName TabID = TabCollection->GetDataID();
		if (TabListWidget_OptionsTabs->GetTabButtonBaseByID(TabID) != nullptr)
		{
			continue;
		}

		TabListWidget_OptionsTabs->RequestRegisterTab(TabID, TabCollection->GetDataDisplayName());
	}
}

UOptionsDataRegistry* UWidget_OptionsScreen::GetOrCreateDataRegistry()
{
	if (!CreatedOwningDataRegistry)
	{
		CreatedOwningDataRegistry = NewObject<UOptionsDataRegistry>();
		CreatedOwningDataRegistry->InitOptionsDataRegistry(GetOwningLocalPlayer());
	}

	checkf(CreatedOwningDataRegistry, TEXT("Data registry for options screen is not valid"));

	return CreatedOwningDataRegistry;
}

void UWidget_OptionsScreen::OnResetBoundActionTriggered()
{
	Debug::Print(TEXT("Reset bound action Triggered"));
}

void UWidget_OptionsScreen::OnBackBoundActionTriggered()
{
	DeactivateWidget();
}

void UWidget_OptionsScreen::OnOptionsTabSelected(FName TabID)
{
	Debug::Print(TEXT("OnOptionsTabSelected Tab ID: ") + TabID.ToString());
}
