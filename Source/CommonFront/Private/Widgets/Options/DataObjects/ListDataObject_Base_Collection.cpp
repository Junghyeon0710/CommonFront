// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataObjects/ListDataObject_Base_Collection.h"

void UListDataObject_Base_Collection::AddChildListData(UListDataObject_Base* InChildListData)
{
	InChildListData->InitDataObject();

	InChildListData->SetParentData(this);
	
	ChildListDataArray.Add(InChildListData);
}

TArray<UListDataObject_Base*> UListDataObject_Base_Collection::GetAllChildeListData() const
{
	return ChildListDataArray;
}

bool UListDataObject_Base_Collection::HasAnyChildeListData() const
{
	return ChildListDataArray.IsEmpty() == false;
}
