// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayerState.h"

#include "LearnGASAura/AbilitySystem/AuraAbilitySystemComponent.h"

AAuraPlayerState::AAuraPlayerState()
{
    // 设置网络更新频率为 100.0 赫兹，这意味着该 Actor 的网络状态每秒会更新 100 次。
    // 较高的更新频率可以让网络上的其他客户端更及时地获取该 Actor 的状态变化，
    // 但同时也会增加网络带宽的使用。
    SetNetUpdateFrequency(100.0f);

    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    // 设置能力系统组件的游戏玩法效果复制模式为混合模式（Mixed）。
    // 在混合模式下，服务器会复制完整的游戏玩法效果（Gameplay Effect）给拥有该 Actor 的客户端，
    // 而对于其他客户端，服务器仅复制游戏玩法效果的预测性快照，这样可以在保证游戏体验的同时，
    // 有效减少网络带宽的占用。
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    AttributeSet = CreateDefaultSubobject<UAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

UAttributeSet* AAuraPlayerState::GetAttributeSet() const
{
    return AttributeSet;
}