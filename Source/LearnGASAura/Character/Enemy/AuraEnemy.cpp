#include "AuraEnemy.h"

#include "Components/CapsuleComponent.h"

AAuraEnemy::AAuraEnemy()
{
    PrimaryActorTick.bCanEverTick = false;    
}

void AAuraEnemy::BeginPlay()
{
    Super::BeginPlay();

}