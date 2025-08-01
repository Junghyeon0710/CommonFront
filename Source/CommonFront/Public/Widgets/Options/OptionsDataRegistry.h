// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OptionsDataRegistry.generated.h"

class UListDataObject_Collection;

UCLASS()
class COMMONFRONT_API UOptionsDataRegistry : public UObject
{
	GENERATED_BODY()

public:
	//OptionsDataRegistry가 생성된 직후, 옵션 화면에서 이 함수가 호출됩니다.
	void IniOptionsDataRegistry(ULocalPlayer* InOwningLocalPlayer);

	const TArray<UListDataObject_Collection*>& GetRegisteredOptionsTabCollections() const {return RegisteredOptionsTabCollections; }
private:
	void InitGameplayCollectionTab();
	void InitAudioCollectionTab();
	void InitVideoCollectionTab();
	void InitControlCollectionTab();

	UPROPERTY(Transient)
	TArray<UListDataObject_Collection*> RegisteredOptionsTabCollections;
	
};
