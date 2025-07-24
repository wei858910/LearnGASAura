// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "LearnGASAura/UI/Widget/AuraUserWidget.h"
#include "LearnGASAura/UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
    if (OverlayWidgetController == nullptr)
    {
        OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
        if (OverlayWidgetController)
        {
            OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);
        }
    }

    return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet, APlayerController* InPlayerController, APlayerState* InPlayerState)
{
    if (UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass))
    {
        OverlayWidget = Cast<UAuraUserWidget>(Widget);
        if (OverlayWidget)
        {
            const FWidgetControllerParams WidgetControllerParams(InAbilitySystemComponent, InAttributeSet, InPlayerController, InPlayerState);
            UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
            OverlayWidget->SetWidgetController(WidgetController);
            OverlayWidget->AddToViewport();
        }
    }
}

void AAuraHUD::BeginPlay()
{
    Super::BeginPlay();

    if (OverlayWidgetClass)
    {
        if (UUserWidget* Widget = CreateWidget(GetWorld(), OverlayWidgetClass))
        {
            Widget->AddToViewport();
        }
    }
}