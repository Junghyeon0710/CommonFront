// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"

void UListDataObject_Collection::AddChildListData(UListDataObject_Base* InChildListData)
{
	InChildListData->InitDataObject();

	InChildListData->SetParentData(this);
	
	ChildListDataArray.Add(InChildListData);
}

TArray<UListDataObject_Base*> UListDataObject_Collection::GetAllChildeListData() const
{
	return ChildListDataArray;
}

bool UListDataObject_Collection::HasAnyChildeListData() const
{
	return ChildListDataArray.IsEmpty() == false;
}
