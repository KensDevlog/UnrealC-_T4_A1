// Copyright Rohit VFS 2023-2024


#include "DestructibleStructure.h"


// Sets default values
ADestructibleStructure::ADestructibleStructure()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADestructibleStructure::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructibleStructure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



