#include "AuraEnemy.h"

#include "Components/CapsuleComponent.h"
#include "LearnGASAura/AbilitySystem/AuraAbilitySystemComponent.h"
#include "LearnGASAura/AbilitySystem/AuraAttributeSet.h"

constexpr float GCustomDepthRed = 250.f;

AAuraEnemy::AAuraEnemy()
{
    PrimaryActorTick.bCanEverTick = false;
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    // 设置能力系统组件的游戏玩法效果复制模式为最小化模式（Minimal）。
    // 在最小化模式下，服务器仅会复制必要的游戏玩法效果信息到客户端，
    // 主要复制游戏玩法效果的持续时间、堆栈数量等基本信息，而不会复制详细的预测信息，
    // 这样能显著减少网络带宽的使用，但可能会使客户端的游戏玩法效果表现与服务器略有延迟或差异。
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

    AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>(TEXT("AttributeSet"));
}

void AAuraEnemy::BeginPlay()
{
    Super::BeginPlay();

    AbilitySystemComponent->InitAbilityActorInfo(this, this);
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