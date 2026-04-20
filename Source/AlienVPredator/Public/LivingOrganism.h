// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LivingOrganism.generated.h"

UCLASS()
class ALIENVPREDATOR_API ALivingOrganism : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALivingOrganism();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
