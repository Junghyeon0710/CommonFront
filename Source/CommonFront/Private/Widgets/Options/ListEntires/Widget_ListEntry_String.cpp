// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/ListEntires/Widget_ListEntry_String.h"

#include "Widgets/Components/FrontendCommonRotator.h"
#include "Widgets/Options/DataObjects/ListDataObject_String.h"

void UWidget_ListEntry_String::OnOwningListItemObjectSet(UListDataObject_Base* InOwningListDataObject)
{
	Super::OnOwningListItemObjectSet(InOwningListDataObject);

	CachedOwningStringDataObject = CastChecked<UListDataObject_String>(InOwningListDataObject);

	
	CommonRotator_AvailableOptions->PopulateTextLabels(CachedOwningStringDataObject->GetAvailableOptionsTextArray());
	CommonRotator_AvailableOptions->SetSelectedOptionByText(CachedOwningStringDataObject->GetCurrentDisplayText());
}
