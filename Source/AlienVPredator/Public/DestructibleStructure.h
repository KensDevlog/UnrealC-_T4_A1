// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "DamageInterface.h"
#include "Engine/StaticMeshActor.h"
#include "DestructibleStructure.generated.h"

UCLASS()
class ALIENVPREDATOR_API ADestructibleStructure : public AStaticMeshActor, public IDamageInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADestructibleStructure();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health = 100.0f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
