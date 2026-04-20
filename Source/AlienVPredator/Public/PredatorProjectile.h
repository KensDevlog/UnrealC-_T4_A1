// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PredatorProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class ALIENVPREDATOR_API APredatorProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APredatorProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	UFUNCTION()
	void OnPredatorProjectileHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<USphereComponent> CollisionComponent;
};
