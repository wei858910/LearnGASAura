#include "AuraEnemy.h"


constexpr float GCustomDepthRed = 250.f;

AAuraEnemy::AAuraEnemy()
{
    PrimaryActorTick.bCanEverTick = false;
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void AAuraEnemy::BeginPlay()
{
    Super::BeginPlay();

}

void AAuraEnemy::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
    GetMesh()->SetCustomDepthStencilValue(GCustomDepthRed);
    Weapon->SetRenderCustomDepth(true);
    Weapon->SetCustomDepthStencilValue(GCustomDepthRed);
}

void AAuraEnemy::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
    Weapon->SetRenderCustomDepth(false);
}