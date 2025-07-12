// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AuraAnimInstance.generated.h"

class AAura;
/**
 * 
 */
UCLASS()
class LEARNGASAURA_API UAuraAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
    UPROPERTY()
    TObjectPtr<AAura> Owner{};

    UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    float GroundSpeed{};
};