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

    /** 
     * 当此角色（Pawn）被占有（控制）时调用。仅在服务器端（或单机模式下）调用。
     * @param NewController 占有（控制）此角色的控制器
     */
    virtual void PossessedBy(AController* NewController) override;
    virtual void OnRep_PlayerState() override; // 在客户端PlayerState被成功复制后触发

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Aura")
    TObjectPtr<USpringArmComponent> SpringArm;

    UPROPERTY(EditAnywhere, Category = "Aura")
    TObjectPtr<UCameraComponent> Camera;
    
private:
    void InitAbilityActorInfo();
};