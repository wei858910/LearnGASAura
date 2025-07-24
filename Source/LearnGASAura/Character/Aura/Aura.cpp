#include "Aura.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "LearnGASAura/Player/AuraPlayerController.h"
#include "LearnGASAura/Player/AuraPlayerState.h"
#include "LearnGASAura/UI/HUD/AuraHUD.h"

AAura::AAura()
{
    PrimaryActorTick.bCanEverTick = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;            // 当角色移动时，会自动旋转以面向移动的方向。
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f); // 设置角色的旋转速率，即角色旋转的速度。
    // 启用角色移动约束到平面的功能。设置为 true 时，角色的移动会被限制在一个平面内，
    // 通常用于 2D 游戏或者需要在特定平面上移动的场景，角色将无法在垂直于该平面的方向上移动。
    GetCharacterMovement()->bConstrainToPlane = true;
    // 当角色开始移动时，此属性控制是否立即将角色位置约束到预设平面上。
    // 若设置为 true，角色在开始移动瞬间会自动调整位置，使其严格处于约束平面内，
    // 常用于需要角色精准保持在特定平面移动的场景，如 2D 游戏或特定平面导航的 3D 场景。
    GetCharacterMovement()->bSnapToPlaneAtStart = true;

    bUseControllerRotationPitch = false; // 禁用控制器的俯仰角旋转，即禁用玩家可以通过控制器的俯仰角来控制角色的俯仰角。
    bUseControllerRotationYaw = false;   // 禁用控制器的偏航角旋转，即禁用玩家可以通过控制器的偏航角来控制角色的偏航角。
    bUseControllerRotationRoll = false;  // 禁用控制器的滚转角旋转，即禁用玩家可以通过控制器的滚转角来控制角色的滚转角。

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(GetRootComponent());
    SpringArm->TargetArmLength = 750.0f;
    SpringArm->bUsePawnControlRotation = false;
    SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
    SpringArm->bEnableCameraLag = true; // 启用相机延迟效果，使相机不会立即跟随角色移动，而是有一定的延迟，这样可以营造出更加平滑、自然的相机跟随效果。
    SpringArm->bInheritPitch = false;   // 相机的俯仰角不会跟随角色的俯仰角变化，而是依据相机自身的设置来确定俯仰角度。
    SpringArm->bInheritRoll = false;    // 相机的滚转角不会跟随角色的滚转角变化，而是依据相机自身的设置来确定滚转角度。
    SpringArm->bInheritYaw = false;     // 相机的偏航角不会跟随角色的偏航角变化，而是依据相机自身的设置来确定偏航角度。

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
    Camera->bUsePawnControlRotation = false;

    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
    const ConstructorHelpers::FObjectFinder<USkeletalMesh> AuraMesh(TEXT("/Game/Assets/Characters/Aura/SKM_Aura.SKM_Aura"));
    if (USkeletalMesh* AuraMeshPtr = AuraMesh.Object; IsValid(AuraMeshPtr))
    {
        GetMesh()->SetSkeletalMesh(AuraMeshPtr);
    }
    const ConstructorHelpers::FClassFinder<UAnimInstance> AnimClass(TEXT("/Game/Bluepint/Character/Aura/ABP_Aura.ABP_Aura_C"));
    if (IsValid(AnimClass.Class))
    {
        GetMesh()->SetAnimInstanceClass(AnimClass.Class);
    }

    const ConstructorHelpers::FObjectFinder<USkeletalMesh> WeaponMesh(TEXT("/Game/Assets/Characters/Aura/Staff/SKM_Staff.SKM_Staff"));
    if (USkeletalMesh* WeaponMeshMeshPtr = WeaponMesh.Object; IsValid(WeaponMeshMeshPtr))
    {
        Weapon->SetSkeletalMesh(WeaponMeshMeshPtr);
    }

}

void AAura::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    // Init Ability Actor Info for the Server
    InitAbilityActorInfo();
}

void AAura::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    // Init Ability Actor Info for the Client
    InitAbilityActorInfo();
}

void AAura::BeginPlay()
{
    Super::BeginPlay();
}

void AAura::InitAbilityActorInfo()
{
    if (AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>())
    {
        AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
        AttributeSet = AuraPlayerState->GetAttributeSet();
        AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);

        if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
        {
            if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
            {
                AuraHUD->InitOverlay(AbilitySystemComponent, AttributeSet, AuraPlayerController, AuraPlayerState);
            }
        }
    }
}