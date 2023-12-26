// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_Actor.h"

// Sets default values
AFF_HTTP_Actor::AFF_HTTP_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFF_HTTP_Actor::BeginPlay()
{
	this->HTTP_Server_Start();
	
	Super::BeginPlay();
}

void AFF_HTTP_Actor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	this->HTTP_Server_Stop();
}

// Called every frame
void AFF_HTTP_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AFF_HTTP_Actor::HTTP_Server_Start()
{
	return false;
}

void AFF_HTTP_Actor::HTTP_Server_Stop()
{

}

void AFF_HTTP_Actor::HTTP_Server_Toggle(bool bPause)
{

}