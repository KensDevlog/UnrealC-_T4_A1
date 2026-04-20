// Copyright Rohit VFS 2023-2024


#include "LivingOrganism.h"
#include "Engine/Engine.h"

// Sets default values
ALivingOrganism::ALivingOrganism()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALivingOrganism::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALivingOrganism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

