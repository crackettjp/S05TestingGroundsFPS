// Copyright (c) Parallel Thinking Ltd 2016

#include "S05TestingGroundsFPS.h"
#include "Gun.h"
#include "BallProjectile.h"
#include "Animation/AnimInstance.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SetRootComponent(SkeletalMesh);
	SkeletalMesh->bCastDynamicShadow = false;
	SkeletalMesh->CastShadow = false;

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	MuzzleLocation->SetupAttachment(SkeletalMesh);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGun::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		const FRotator SpawnRotation = MuzzleLocation->GetComponentRotation();
		const FVector SpawnLocation = MuzzleLocation->GetComponentLocation();

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			// spawn the projectile at the muzzle
			World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

