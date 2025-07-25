﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class IEnemyInterface;
/**
 * 
 */
UCLASS()
class LEARNGASAURA_API AAuraPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AAuraPlayerController();
    virtual void PlayerTick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

private:
    UPROPERTY(EditAnywhere, Category="Input")
    TObjectPtr<class UInputMappingContext> AuraContext{};

    UPROPERTY(EditAnywhere, Category="Input")
    TObjectPtr<class UInputAction> MoveAction{};

    void Move(const struct FInputActionValue& InputActionValue);

    void CursorTrace();

    IEnemyInterface* LastActor{};
    IEnemyInterface* ThisActor{};
};