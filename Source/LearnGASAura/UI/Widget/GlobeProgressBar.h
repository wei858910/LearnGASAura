#pragma once

#include "CoreMinimal.h"
#include "AuraUserWidget.h"
#include "GlobeProgressBar.generated.h"

class UProgressBar;
class UImage;
class USizeBox;
/**
 * 
 */
UCLASS()
class LEARNGASAURA_API UGlobeProgressBar : public UAuraUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(meta=(BindWidget))
    TObjectPtr<USizeBox> SizeBox_Root{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="SizeBox_Root")
    float BoxWidth{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="SizeBox_Root")
    float BoxHeight{};

    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UImage> Image_Background{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Image_Background")
    FSlateBrush BackgroundBrush{};

    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UProgressBar> GlobeProgressBar{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="GlobeProgressBar")
    FSlateBrush ProgressBarBackgroundImage{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="GlobeProgressBar")
    FSlateBrush ProgressBarFillImage{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="GlobeProgressBar")
    float GlobePadding{ 10.0f };

    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UImage> Image_Glass{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Image_Glass")
    float GlassPadding{ 5.0f };

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Image_Glass")
    FSlateBrush GlassBrush{};

public:
    UFUNCTION(BlueprintCallable)
    void UpdateBackgroundBrush();

    UFUNCTION(BlueprintCallable)
    void SetGlobeImage() const;

    UFUNCTION(BlueprintCallable)
    void UpdateGlassImage();

    UFUNCTION(BlueprintCallable)
    virtual void NativePreConstruct() override;

    UFUNCTION(BlueprintCallable)
    void UpdateBoxSize() const;
};