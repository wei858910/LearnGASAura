// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LEARNGASAURA_API AAuraPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AAuraPlayerController();

protected:
    virtual void BeginPlay() override;

    void Move(const struct FInputActionValue& InputActionValue);
    virtual void SetupInputComponent() override;

private:
    UPROPERTY(EditAnywhere, Category="Input")
    TObjectPtr<class UInputMappingContext> AuraContext{};

    UPROPERTY(EditAnywhere, Category="Input")
    TObjectPtr<class UInputAction> MoveAction{};
};