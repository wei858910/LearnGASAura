// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraEnemyAnimInstance.h"

#include "AuraEnemy.h"
#include "GameFramework/PawnMovementComponent.h"

void UAuraEnemyAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    Owner = Cast<AAuraEnemy>(TryGetPawnOwner());

}

void UAuraEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    if (IsValid(Owner))
    {
        FVector VelocityVector = Owner->GetMovementComponent()->Velocity;
        VelocityVector.Z = 0.0f;
        GroundSpeed = VelocityVector.Size();
    }
}