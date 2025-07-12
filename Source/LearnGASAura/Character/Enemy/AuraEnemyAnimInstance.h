// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AuraEnemyAnimInstance.generated.h"

class AAuraEnemy;

UCLASS()
class LEARNGASAURA_API UAuraEnemyAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
    UPROPERTY()
    TObjectPtr<AAuraEnemy> Owner{};

    UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    float GroundSpeed{};

};