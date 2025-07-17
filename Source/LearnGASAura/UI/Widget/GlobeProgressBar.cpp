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
    FProgressBarStyle ProgressBarStyle{ProgressBar.Get()->GetWidgetStyle()};
    ProgressBarStyle.SetBackgroundImage(ProgressBarBackgroundImage);
    ProgressBarStyle.SetFillImage(ProgressBarFillImage);
    
    ProgressBar.Get()->SetWidgetStyle(ProgressBarStyle);
    ProgressBar.Get()->SetPercent(0.5f);
    ProgressBar.Get()->SetBarFillStyle(EProgressBarFillStyle::Mask);
    ProgressBar.Get()->SetBarFillType(EProgressBarFillType::BottomToTop);
}

void UGlobeProgressBar::NativePreConstruct()
{
    Super::NativePreConstruct();

    UpdateBoxSize();
    UpdateBackgroundBrush();
    SetGlobeImage();
    UWidgetLayoutLibrary::SlotAsOverlaySlot(ProgressBar.Get())->SetPadding(FMargin(GlobePadding));
}

void UGlobeProgressBar::UpdateBoxSize() const
{
    if (SizeBox_Root)
    {
        SizeBox_Root.Get()->SetWidthOverride(BoxWidth);
        SizeBox_Root.Get()->SetHeightOverride(BoxHeight);
    }
}