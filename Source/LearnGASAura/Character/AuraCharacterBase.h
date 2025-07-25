﻿#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class LEARNGASAURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AAuraCharacterBase();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

    UAttributeSet* GetAttributeSet() const;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category= "Combat")
    TObjectPtr<USkeletalMeshComponent> Weapon{};

    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{};

    UPROPERTY()
    TObjectPtr<UAttributeSet> AttributeSet{};

};