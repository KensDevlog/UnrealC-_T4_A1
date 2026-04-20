// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "LivingOrganism.h"
#include "DamageInterface.h"
#include "Predator.generated.h"

class AAlien;
class APredatorProjectile;
/**
 * 
 */
UCLASS()
class ALIENVPREDATOR_API APredator : public ALivingOrganism , public IDamageInterface
{
	GENERATED_BODY()
protected:
	void Tick(float DeltaSeconds) override;

public:
	void TakeLivingDamage_Implementation() override;
	
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<APredatorProjectile> ProjectileToShoot;
	
	UFUNCTION(BlueprintCallable)
	void Shoot();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SearchDistance = 400.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ActionInterval = 1.f;
	
	UFUNCTION(BlueprintCallable)
	void FindAlien();
	
	UFUNCTION(BlueprintCallable)
	void TryShootAtTarget();
	
	UPROPERTY()
	TWeakObjectPtr<AAlien> Target;
	
	FTimerHandle PredatorActionHandle;
};
