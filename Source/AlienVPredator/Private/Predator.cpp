// Copyright Rohit VFS 2023-2024


#include "Predator.h"

#include "Alien.h"
#include "PredatorProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void APredator::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APredator::TakeLivingDamage_Implementation()
{
	IDamageInterface::TakeLivingDamage_Implementation();
	GetWorldTimerManager().ClearTimer(PredatorActionHandle);
	Destroy();
}

void APredator::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(
		PredatorActionHandle,[this]()
		{
			Target.IsValid() ? TryShootAtTarget() : FindAlien();
		}, 
		ActionInterval,
		true);
}

void APredator::Shoot()
{
	if (!ProjectileToShoot) return;
	UWorld* World = GetWorld();
	if (!World) return;
	
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	SpawnInfo.Owner = this;
	APredatorProjectile* MyProjectileToSpawn = World->SpawnActor<APredatorProjectile>(ProjectileToShoot, GetActorLocation() + GetActorForwardVector() * 100, GetActorForwardVector().Rotation(), SpawnInfo);
	if (!MyProjectileToSpawn) return;
	MyProjectileToSpawn->CollisionComponent->IgnoreActorWhenMoving(this, true);
	MyProjectileToSpawn->ProjectileMovement->InitialSpeed = 2000.f;
	MyProjectileToSpawn->ProjectileMovement->MaxSpeed = 2000.f;
}

void APredator::FindAlien()
{
	TArray<AActor*> OutActors;
	
	UKismetSystemLibrary::SphereOverlapActors(
		GetWorld(),
		GetActorLocation(),
		SearchDistance,
		TArray<TEnumAsByte<EObjectTypeQuery>>{ ObjectTypeQuery2},
		AAlien::StaticClass(),
		TArray<AActor*> { this },
		OutActors);
	
	for (AActor* Actor : OutActors)
	{
		if (AAlien* ActorAsAlien = Cast<AAlien>(Actor))
		{
			Target = ActorAsAlien;
			return;
		}
	}
}

void APredator::TryShootAtTarget()
{
	if (!Target.IsValid()) return;
	FVector Direction = (Target->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	FRotator LookAtRotation = Direction.Rotation();
	SetActorRotation(LookAtRotation);
	Shoot();
}

