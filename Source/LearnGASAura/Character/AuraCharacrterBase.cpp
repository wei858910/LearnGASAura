#include "AuraCharacterBase.h"


AAuraCharacterBase::AAuraCharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;

    GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
    Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
    Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
    return AttributeSet;
}

void AAuraCharacterBase::BeginPlay()
{
    Super::BeginPlay();
}