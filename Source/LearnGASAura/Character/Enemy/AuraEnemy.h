#pragma once

#include "CoreMinimal.h"
#include "LearnGASAura/Character/AuraCharacterBase.h"
#include "LearnGASAura/Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class LEARNGASAURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
    GENERATED_BODY()

public:
    AAuraEnemy();

protected:
    virtual void BeginPlay() override;

public:
    virtual void HighlightActor() override;
    virtual void UnHighlightActor() override;

    UPROPERTY(BlueprintReadOnly)
    bool bHighlighted{};
};