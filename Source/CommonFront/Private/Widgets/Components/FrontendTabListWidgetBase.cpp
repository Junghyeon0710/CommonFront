// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Components/FrontendTabListWidgetBase.h"

#include "Editor/WidgetCompilerLog.h"
#include "Widgets/Components/FrontendCommonButtonBase.h"

#if WITH_EDITOR
void UFrontendTabListWidgetBase::RequestRegisterTab(const FName& InTabId, const FText& InTabDisplayName)
{
}

void UFrontendTabListWidgetBase::ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (!TabButtonEntryWidgetClass)
	{
		CompileLog.Error(FText::FromString(TEXT("The variable TabButtonEntryWidgetClass has no valid entry specified.") + GetClass()->GetName() +
			TEXT(" needs a valid entry widget class to function properly"))); 
	}
}
#endif
