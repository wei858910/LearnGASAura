// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LearnGASAura/Character/AuraCharacterBase.h"
#include "Aura.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class LEARNGASAURA_API AAura : public AAuraCharacterBase
{
    GENERATED_BODY()

public:
    AAura();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Aura")
    TObjectPtr<USpringArmComponent> SpringArm;

    UPROPERTY(EditAnywhere, Category = "Aura")
    TObjectPtr<UCameraComponent> Camera;
};