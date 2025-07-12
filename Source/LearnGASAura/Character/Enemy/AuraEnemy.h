#pragma once

#include "CoreMinimal.h"
#include "LearnGASAura/Character/AuraCharacterBase.h"
#include "AuraEnemy.generated.h"

UCLASS()
class LEARNGASAURA_API AAuraEnemy : public AAuraCharacterBase
{
    GENERATED_BODY()

public:
    AAuraEnemy();

protected:
    virtual void BeginPlay() override;
    
};