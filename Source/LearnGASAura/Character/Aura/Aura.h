// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LearnGASAura/Character/AuraCharacterBase.h"
#include "Aura.generated.h"

UCLASS()
class LEARNGASAURA_API AAura : public AAuraCharacterBase
{
    GENERATED_BODY()

public:
    AAura();

protected:
    virtual void BeginPlay() override;
};