// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/ListEntires/Widget_ListEntry_Scalar.h"

void UWidget_ListEntry_Scalar::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	
}

void UWidget_ListEntry_Scalar::OnOwningListItemObjectSet(UListDataObject_Base* InOwningListDataObject)
{
	Super::OnOwningListItemObjectSet(InOwningListDataObject);
}

void UWidget_ListEntry_Scalar::OnOwningListDataObjectModified(UListDataObject_Base* OwningModifiedData, EOptionsListDataModifyReason ModifyReason)
{
	Super::OnOwningListDataObjectModified(OwningModifiedData, ModifyReason);
}
