// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/ListEntires/Widget_ListEntry_Base.h"

#include "CommonTextBlock.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"

void UWidget_ListEntry_Base::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	OnOwningListItemObjectSet(CastChecked<UListDataObject_Base>(ListItemObject));
}

void UWidget_ListEntry_Base::OnOwningListItemObjectSet(UListDataObject_Base* InOwningListDataObject)
{
	if (CommonText_SettingDisplayName)
	{
		CommonText_SettingDisplayName->SetText(InOwningListDataObject->GetDataDisplayName());
	}
}
