// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OptionsDataRegistry.generated.h"

class UListDataObject_Base;
class UListDataObject_Collection;

UCLASS()
class COMMONFRONT_API UOptionsDataRegistry : public UObject
{
	GENERATED_BODY()

public:
	//OptionsDataRegistry가 생성된 직후, 옵션 화면에서 이 함수가 호출됩니다.
	void InitOptionsDataRegistry(ULocalPlayer* InOwningLocalPlayer);

	const TArray<UListDataObject_Collection*>& GetRegisteredOptionsTabCollections() const {return RegisteredOptionsTabCollections; }

	TArray<UListDataObject_Base*> GetListSourceItemsBySelectedTabID(const FName& InSelectedTabID) const;
	
private:
	void FindChildListDataRecursively(UListDataObject_Base* InParentData, TArray<UListDataObject_Base*>& OutFoundChildListData) const;
	
	void InitGameplayCollectionTab();
	void InitAudioCollectionTab();
	void InitVideoCollectionTab();
	void InitControlCollectionTab(ULocalPlayer* InOwningLocalPlayer);

	UPROPERTY(Transient)
	TArray<UListDataObject_Collection*> RegisteredOptionsTabCollections;
	
};
