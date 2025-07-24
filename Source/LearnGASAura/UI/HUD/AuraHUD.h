// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UOverlayWidgetController;
class UAuraUserWidget;
class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class LEARNGASAURA_API AAuraHUD : public AHUD
{
    GENERATED_BODY()

public:
    UPROPERTY()
    TObjectPtr<UAuraUserWidget> OverlayWidget{};

    UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams);

    void InitOverlay(UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet, APlayerController* InPlayerController, APlayerState* InPlayerState);

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UAuraUserWidget> OverlayWidgetClass{};

    UPROPERTY()
    TObjectPtr<UOverlayWidgetController> OverlayWidgetController{};

    UPROPERTY(EditAnywhere)
    TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass{};
};