// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class LEARNGASAURA_API AAuraPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    AAuraPlayerState();

protected:
    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{};

    UPROPERTY()
    TObjectPtr<UAttributeSet> AttributeSet{};
};
