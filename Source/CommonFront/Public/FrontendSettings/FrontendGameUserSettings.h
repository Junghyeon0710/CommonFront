// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "FrontendGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class COMMONFRONT_API UFrontendGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UFrontendGameUserSettings();
	
	static UFrontendGameUserSettings* Get();

	UFUNCTION()
	FString GetCurrentGameDifficulty() const { return CurrentGameDifficulty; }

	UFUNCTION()
	void SetCurrentGameDifficulty(const FString& InNewDifficulty) {CurrentGameDifficulty = InNewDifficulty; }

	UFUNCTION()
	float GetOverallVolume() const { return OverallVolume; }

	UFUNCTION()
	void SetOverallVolume(float InNewVolume);

	UFUNCTION()
	float GetMusicVolume() const { return MusicVolume; }

	UFUNCTION()
	void SetMusicVolume(float InMusicVolume);

	UFUNCTION()
	float GetSoundFXVolume() const { return MusicVolume; }

	UFUNCTION()
	void SetSoundFXVolume(float InSoundFXVolume);

	UFUNCTION()
	bool GetAllowBackgroundAudio() const { return bAllowBackgroundAudio; }

	UFUNCTION()
	void SetAllowBackgroundAudio(bool InAllowBackgroundAudio);
private:
	UPROPERTY(Config)
	FString CurrentGameDifficulty;

	UPROPERTY(Config)
	float OverallVolume;

	UPROPERTY(Config)
	float MusicVolume;

	UPROPERTY(Config)
	float SoundFXVolume;

	UPROPERTY(Config)
	bool bAllowBackgroundAudio;
};
