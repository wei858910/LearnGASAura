#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
    GENERATED_BODY()

    FWidgetControllerParams() {}

    FWidgetControllerParams(UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet, APlayerController* InPlayerController, APlayerState* InPlayerState)
        : PlayerController(InPlayerController)
        , PlayerState(InPlayerState)
        , AbilitySystemComponent(InAbilitySystemComponent)
        , AttributeSet(InAttributeSet) {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<APlayerController> PlayerController{};

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<APlayerState> PlayerState{};

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{};

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UAttributeSet> AttributeSet{};
};

UCLASS()
class LEARNGASAURA_API UAuraWidgetController : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void SetWidgetControllerParams(const FWidgetControllerParams& InWidgetControllerParams);

protected:
    UPROPERTY(BlueprintReadOnly, Category="WidgetController")
    TObjectPtr<APlayerController> PlayerController{};

    UPROPERTY(BlueprintReadOnly, Category="WidgetController")
    TObjectPtr<APlayerState> PlayerState{};

    UPROPERTY(BlueprintReadOnly, Category="WidgetController")
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{};

    UPROPERTY(BlueprintReadOnly, Category="WidgetController")
    TObjectPtr<UAttributeSet> AttributeSet{};

};