// Fill out your copyright notice in the Description page of Project Settings.


#include "AAuraGameModeBase.h"

#include "LearnGASAura/Player/AuraPlayerController.h"

AAAuraGameModeBase::AAAuraGameModeBase()
{
    if (const ConstructorHelpers::FClassFinder<AAuraPlayerController> AuraPlayerControllerClass(TEXT("/Game/Player/BP_AuraPlayerController.BP_AuraPlayerController_C")); IsValid(AuraPlayerControllerClass.Class))
    {
        PlayerControllerClass = AuraPlayerControllerClass.Class;
    }
}