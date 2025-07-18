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
    UWidgetLayoutLibrary::SlotAsOverlaySlot(GlobeProgressBar.Get())->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
    UWidgetLayoutLibrary::SlotAsOverlaySlot(GlobeProgressBar.Get())->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);

    GlobeProgressBar.Get()->SetFillColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));

    FProgressBarStyle ProgressBarStyle{ GlobeProgressBar.Get()->GetWidgetStyle() };
    ProgressBarStyle.SetBackgroundImage(ProgressBarBackgroundImage);
    ProgressBarStyle.SetFillImage(ProgressBarFillImage);

    GlobeProgressBar.Get()->SetWidgetStyle(ProgressBarStyle);
    GlobeProgressBar.Get()->SetPercent(0.5f);
    GlobeProgressBar.Get()->SetBarFillStyle(EProgressBarFillStyle::Mask);
    GlobeProgressBar.Get()->SetBarFillType(EProgressBarFillType::BottomToTop);

}

void UGlobeProgressBar::UpdateGlassImage()
{
    if (UMaterialInstance* InMaterial = LoadObject<UMaterialInstance>(nullptr, TEXT("/Game/Assets/UI/Globes/MI_EmptyGlobe.MI_EmptyGlobe")))
    {
        GlassBrush.SetResourceObject(InMaterial);
        Image_Glass.Get()->SetBrush(GlassBrush);
        UWidgetLayoutLibrary::SlotAsOverlaySlot(Image_Glass.Get())->SetPadding(FMargin(GlassPadding));
        UWidgetLayoutLibrary::SlotAsOverlaySlot(Image_Glass.Get())->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
        UWidgetLayoutLibrary::SlotAsOverlaySlot(Image_Glass.Get())->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
    }
}

void UGlobeProgressBar::NativePreConstruct()
{
    Super::NativePreConstruct();

    UpdateBoxSize();
    UpdateBackgroundBrush();
    SetGlobeImage();
    UpdateGlassImage();
}

void UGlobeProgressBar::UpdateBoxSize() const
{
    if (SizeBox_Root)
    {
        SizeBox_Root.Get()->SetWidthOverride(BoxWidth);
        SizeBox_Root.Get()->SetHeightOverride(BoxHeight);
    }
}