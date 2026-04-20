// Copyright Rohit VFS 2023-2024


#include "PredatorProjectile.h"

#include "DamageInterface.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
APredatorProjectile::APredatorProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	
	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	SetRootComponent(CollisionComponent);
	CollisionComponent->SetSphereRadius(20.f);
	CollisionComponent->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void APredatorProjectile::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddUniqueDynamic(this, &APredatorProjectile::OnPredatorProjectileHit);
}

void APredatorProjectile::OnPredatorProjectileHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	if (OtherActor == GetOwner()) return;
	if (OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_TakeLivingDamage(OtherActor);
	}
	Destroy();
}

// Called every frame
void APredatorProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

