#include "GlobeProgressBar.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/Image.h"
#include "Components/OverlaySlot.h"
#include "Components/ProgressBar.h"
#include "Components/SizeBox.h"

void UGlobeProgressBar::UpdateBackgroundBrush()
{
    if (UTexture* InTexture = LoadObject<UTexture>(nullptr, TEXT("/Game/Assets/UI/Rings/GlobeRing/GlobeRing.GlobeRing")))
    {
        BackgroundBrush.SetResourceObject(InTexture);
        Image_Background.Get()->SetBrush(BackgroundBrush);
    }
}

void UGlobeProgressBar::SetGlobeImage() const
{
    UWidgetLayoutLibrary::SlotAsOverlaySlot(GlobeProgressBar.Get())->SetPadding(FMargin(GlobePadding));
    GlobeProgressBar.Get()->SetFillColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
    
    FProgressBarStyle ProgressBarStyle{GlobeProgressBar.Get()->GetWidgetStyle()};
    ProgressBarStyle.SetBackgroundImage(ProgressBarBackgroundImage);
    ProgressBarStyle.SetFillImage(ProgressBarFillImage);
    
    GlobeProgressBar.Get()->SetWidgetStyle(ProgressBarStyle);
    GlobeProgressBar.Get()->SetPercent(0.5f);
    GlobeProgressBar.Get()->SetBarFillStyle(EProgressBarFillStyle::Mask);
    GlobeProgressBar.Get()->SetBarFillType(EProgressBarFillType::BottomToTop);
}

void UGlobeProgressBar::NativePreConstruct()
{
    Super::NativePreConstruct();

    UpdateBoxSize();
    UpdateBackgroundBrush();
    SetGlobeImage();
   
}

void UGlobeProgressBar::UpdateBoxSize() const
{
    if (SizeBox_Root)
    {
        SizeBox_Root.Get()->SetWidthOverride(BoxWidth);
        SizeBox_Root.Get()->SetHeightOverride(BoxHeight);
    }
}