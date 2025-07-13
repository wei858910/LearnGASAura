#include "AuraEnemy.h"

#include "Components/CapsuleComponent.h"
#include "LearnGASAura/AbilitySystem/AuraAbilitySystemComponent.h"


constexpr float GCustomDepthRed = 250.f;

AAuraEnemy::AAuraEnemy()
{
    PrimaryActorTick.bCanEverTick = false;
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);

    AttributeSet = CreateDefaultSubobject<UAttributeSet>(TEXT("AttributeSet"));
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