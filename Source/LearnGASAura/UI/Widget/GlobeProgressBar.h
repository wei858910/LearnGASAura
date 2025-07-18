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

    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UImage> Image_Background{};

    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UProgressBar> GlobeProgressBar{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float BoxWidth{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float BoxHeight{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSlateBrush BackgroundBrush{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSlateBrush ProgressBarBackgroundImage{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSlateBrush ProgressBarFillImage{};

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float GlobePadding{10.0f};

    void UpdateBackgroundBrush();
    void SetGlobeImage() const;
    virtual void NativePreConstruct() override;

protected:
    void UpdateBoxSize() const;
};