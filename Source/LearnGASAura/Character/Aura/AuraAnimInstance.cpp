// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAnimInstance.h"

#include "Aura.h"
#include "GameFramework/PawnMovementComponent.h"

void UAuraAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    Owner = Cast<AAura>(TryGetPawnOwner());
}

void UAuraAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    
    if (IsValid(Owner))
    {
        FVector VelocityVector = Owner->GetMovementComponent()->Velocity;
        VelocityVector.Z = 0.0f;
        GroundSpeed = VelocityVector.Size();
        if(GroundSpeed > 3.0f)
        {
            bShouldMove = true;
        }
        else
        {
            bShouldMove = false;
        }
    }
}