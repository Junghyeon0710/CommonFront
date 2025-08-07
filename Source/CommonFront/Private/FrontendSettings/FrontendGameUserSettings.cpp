// Fill out your copyright notice in the Description page of Project Settings.


#include "FrontendSettings/FrontendGameUserSettings.h"

UFrontendGameUserSettings::UFrontendGameUserSettings()
	: OverallVolume(1.f)
	, MusicVolume(1.f)
	, SoundFXVolume(1.f)
		
{
}

UFrontendGameUserSettings* UFrontendGameUserSettings::Get()
{
	if (GEngine)
	{
		return CastChecked<UFrontendGameUserSettings>(GEngine->GetGameUserSettings());
	}

	return nullptr;
}

void UFrontendGameUserSettings::SetOverallVolume(float InNewVolume)
{
	OverallVolume = InNewVolume;

	// 여기서 로직 처리 해야됨
	// 	전체 볼륨 설정에 대한 힌트
	// 실제 사운드 자산, 사운드 큐 또는 메타 사운드에 따라 전체 볼륨, 음악 볼륨 또는 사운드 FX 볼륨을 제어하는 프로세스가 약간 다릅니다.
	//
	//
	//
	// 여기서는 사운드 큐를 예로 들어 보겠습니다.
	//
	//
	//
	// 결국, 우리는 .에서 SetSoundMixClassOverride 명명 된 함수를 호출해야 할 것입니다 .PushSoundMixModifierUGameplayStatics
	//
	//
	//
	// 가장 먼저 해야 할 일은 사운드 클래스와 기본 사운드 믹스를 참조하는 소프트 클래스 포인터를 여러 개 만드는 것입니다. 이 변수들을 .에 저장할 수 있습니다 FrontendDeveloperSettings. 다음과 같이 하면 됩니다.
	//
	// UPROPERTY ( Config , EditAnywhere , Category = "Audio" , meta = ( AllowedClasses = "/Script/Engine.SoundClass" ))       
	// FSoftObjectPath MasterSoundClass ; 
	//  
	// UPROPERTY ( Config , EditAnywhere , Category = "Audio" , meta = ( AllowedClasses = "/Script/Engine.SoundClass" ))       
	// FSoftObjectPath MusicSoundClass ; 
	//  
	// UPROPERTY ( Config , EditAnywhere , Category = "Audio" , meta = ( AllowedClasses = "/Script/Engine.SoundClass" ))       
	// FSoftObjectPath SoundFXSoundClass ; 
	//  
	// UPROPERTY ( Config , EditAnywhere , Category = "Audio" , meta = ( AllowedClasses = "/Script/Engine.SoundMix" ))       
	// FSoftObjectPath 기본 사운드 믹스 ; 
	//
	//
	// 그런 다음 이러한 변수를 만든 후 프로젝트 설정에서 해당 변수에 값을 지정해야 합니다. 
	//
	//
	//
	//
	// 마스터 사운드 클래스는 제가 만든 것입니다. 마스터 사운드 클래스에 영향을 받는 자식 사운드 클래스를 정의해야 합니다. 다음과 같습니다.
	//
	//
	// 여러분이 보고 있는 음악과 SFX 사운드 클래스는 엔진에서 나온 것입니다.
	//
	//
	//
	// 유효한 값을 할당했으면 게임에서 사용되는 사운드 큐에 유효한 사운드 클래스를 지정해야 합니다. 음악이라면 Music 클래스, Sound FX라면 SFX 클래스가 지정되어야 합니다.
	//
	//
	//
	//
	// FrontendGameUserSettings마지막으로, 볼륨의 값이 변경될 때마다 setter 함수에서 다음과 같은 작업을 수행할 수 있습니다.
	//
	// void UFrontendGameUserSettings :: SetOverallVolume ( float InVolume )  
	// {	
	// 	UWorld * InAudioWorld = nullptr ;   
	// 	const UFrontendDeveloperSettings * FrontendDeveloperSettings = GetDefault < UFrontendDeveloperSettings >();    
	//  
	// 	if ( GEngine ) 
	// 	{
	// 		InAudioWorld = GEngine -> GetCurrentPlayWorld ();  
	// 	}
	//  
	// 	if (! InAudioWorld || ! FrontendDeveloperSettings )   
	// 	{
	// 		반품 ;
	// 	}
	//  
	// 	USoundClass * MasterSoundClass = nullptr ;   
	// 	if ( UObject * LoadedObject = FrontendDeveloperSettings -> MasterSoundClass .TryLoad () )    
	// 	{
	// 		MasterSoundClass = CastChecked < USoundClass >( LoadedObject );  
	// 	}
	//  
	// 	USoundMix * DefaultSoundMix = nullptr ;   
	// 	if ( UObject * LoadedObject = FrontendDeveloperSettings -> DefaultSoundMix .TryLoad () )    
	// 	{
	// 		DefaultSoundMix = CastChecked < USoundMix >( LoadedObject );  
	// 	}
	//  
	// 	전체 볼륨 = 내부 볼륨 ;  
	//  
	// 	UGameplayStatics :: SetSoundMixClassOverride (
	// 		InAudioWorld ,
	// 		기본 사운드 믹스 ,
	// 		마스터사운드클래스 ,
	// 		전체 볼륨 ,
	// 		1.f ,
	// 		0.2f
	// 	);
	//  
	//         UGameplayStatics :: PushSoundMixModifier ( InAudioWorld , DefaultSoundMix ); 
	// }
	//
	//
	// 위의 모든 과정을 거치면 이제 볼륨을 전역적으로 제어할 수 있게 됩니다.
}

void UFrontendGameUserSettings::SetMusicVolume(float InMusicVolume)
{
	MusicVolume = InMusicVolume;
}

void UFrontendGameUserSettings::SetSoundFXVolume(float InSoundFXVolume)
{
	SoundFXVolume = InSoundFXVolume;
}
