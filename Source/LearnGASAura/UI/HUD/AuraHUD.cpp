// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "LearnGASAura/UI/Widget/AuraUserWidget.h"

void AAuraHUD::BeginPlay()
{
    Super::BeginPlay();

    if(OverlayWidgetClass)
    {
        if(UUserWidget* Widget = CreateWidget(GetWorld(), OverlayWidgetClass))
        {
            Widget->AddToViewport();
        }
    }
}