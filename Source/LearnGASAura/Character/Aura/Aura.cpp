#include "Aura.h"

#include "ShaderPrintParameters.h"

AAura::AAura()
{
    PrimaryActorTick.bCanEverTick = false;

    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
    const ConstructorHelpers::FObjectFinder<USkeletalMesh> AuraMesh(TEXT("/Game/Assets/Characters/Aura/SKM_Aura.SKM_Aura"));
    if (USkeletalMesh* AuraMeshPtr = AuraMesh.Object; IsValid(AuraMeshPtr))
    {
        GetMesh()->SetSkeletalMesh(AuraMeshPtr);
    }
    
    const ConstructorHelpers::FObjectFinder<USkeletalMesh> WeaponMesh(TEXT("/Game/Assets/Characters/Aura/Staff/SKM_Staff.SKM_Staff"));
    if (USkeletalMesh* WeaponMeshMeshPtr = WeaponMesh.Object; IsValid(WeaponMeshMeshPtr))
    {
        Weapon->SetSkeletalMesh(WeaponMeshMeshPtr);
    }
}

void AAura::BeginPlay()
{
    Super::BeginPlay();
}