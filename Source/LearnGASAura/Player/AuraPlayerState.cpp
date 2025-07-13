// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
    // 设置网络更新频率为 100.0 赫兹，这意味着该 Actor 的网络状态每秒会更新 100 次。
    // 较高的更新频率可以让网络上的其他客户端更及时地获取该 Actor 的状态变化，
    // 但同时也会增加网络带宽的使用。
    SetNetUpdateFrequency(100.0f); 
}