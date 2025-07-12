// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "LearnGASAura/Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
    bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);

    CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
    Super::BeginPlay();

    check(AuraContext);

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(AuraContext, 0);
    }

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
    // 从输入动作值中获取二维向量，该向量代表输入的轴向信息（通常是移动方向）
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
    // 获取玩家控制器的当前控制旋转
    const FRotator Rotation = GetControlRotation();
    // 提取旋转中的偏航角（Yaw），并创建一个仅包含偏航角的旋转对象
    const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
    // 根据仅包含偏航角的旋转对象创建旋转矩阵，并获取其 X 轴方向作为向前的单位向量
    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    // 根据仅包含偏航角的旋转对象创建旋转矩阵，并获取其 Y 轴方向作为向右的单位向量
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    // 尝试获取当前控制器所控制的 Pawn 对象
    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        // 向受控 Pawn 添加向前的移动输入，移动量由输入轴向向量的 Y 分量决定
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
        // 向受控 Pawn 添加向右的移动输入，移动量由输入轴向向量的 X 分量决定
        ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
    }
}

void AAuraPlayerController::CursorTrace()
{
    FHitResult CursorHit{};
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    if (CursorHit.bBlockingHit)
    {
        LastActor = ThisActor;
        ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
        if (LastActor == nullptr)
        {
            if (ThisActor != LastActor)
            {
                ThisActor->HighlightActor();
            }
        }
        else
        {
            if (ThisActor == nullptr)
            {
                LastActor->UnHighlightActor();
            }
            else
            {
                if (ThisActor != LastActor)
                {
                    LastActor->UnHighlightActor();
                    ThisActor->HighlightActor();
                }
            }
        }

    }
}

void AAuraPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        if (IsValid(MoveAction))
        {
            EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
        }
    }
}