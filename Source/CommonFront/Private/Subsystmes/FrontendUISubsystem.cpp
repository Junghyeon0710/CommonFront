// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonFront/Subsystems/FrontendUISubsystem.h"

#include "CommonFront/FrontendDebugHelper.h"
#include "Engine/AssetManager.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widgets/Widget_PrimaryLayout.h"

UFrontendUISubsystem* UFrontendUISubsystem::Get(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);

		return UGameInstance::GetSubsystem<UFrontendUISubsystem>(World->GetGameInstance());
	}

	return nullptr;
}

bool UFrontendUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	//Dedicated Server는 UI가 필요 없는 순수 서버
	if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
	{
		TArray<UClass*> FoundClasses;
		GetDerivedClasses(GetClass(), FoundClasses);

		return FoundClasses.IsEmpty();
	}

	return false;
}

void UFrontendUISubsystem::RegisterCreatedPrimaryLayout(UWidget_PrimaryLayout* InCreateWidget)
{
	check(InCreateWidget)
	
	CreatedPrimaryLayout = InCreateWidget;

	Debug::Print(TEXT("Primary Layout Widget Stored"));
}

void UFrontendUISubsystem::PushSoftWidgetToStackAynsc(const FGameplayTag& InWidgetStack,TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass, TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)>AysncPushStateCallback)
{
	check(!InSoftWidgetClass.IsNull())

	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InSoftWidgetClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda([InSoftWidgetClass, this, InWidgetStack, AysncPushStateCallback]()
			{
				UClass* LoadedWidgetClass = InSoftWidgetClass.Get();
				check(LoadedWidgetClass && CreatedPrimaryLayout);

				UCommonActivatableWidgetContainerBase* FoundWidgetStack = CreatedPrimaryLayout->FindWidgetStackByTag(
					InWidgetStack);

				UWidget_ActivatableBase* CreatedWidget = FoundWidgetStack->AddWidget<UWidget_ActivatableBase>(
					LoadedWidgetClass,
					[AysncPushStateCallback](UWidget_ActivatableBase& CreatedWidgetInstance)
					{
						AysncPushStateCallback(EAsyncPushWidgetState::OnCreatedBeforePush, &CreatedWidgetInstance);
					}
				);

				AysncPushStateCallback(EAsyncPushWidgetState::AfterPush, CreatedWidget);
			}
		)
	);
}
