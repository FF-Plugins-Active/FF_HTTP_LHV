// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_LHV_Server.h"

// Sets default values
AHTTP_Server_LHV::AHTTP_Server_LHV()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned.
void AHTTP_Server_LHV::BeginPlay()
{
#ifdef _WIN64
	this->HTTP_Server_Start();
#endif
	
	Super::BeginPlay();
}

// Called when the game ends or when destroyed.
void AHTTP_Server_LHV::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#ifdef _WIN64
	this->HTTP_Server_Stop();
#endif

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_LHV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHTTP_Server_LHV::HTTP_Server_Start()
{
#ifdef _WIN64
	
	if (this->Server_Name.IsEmpty())
	{
		return false;
	}

	this->Thread_LibHv = new FHTTP_Thread_LibHv(this);

	return (this->Thread_LibHv) ? true : false;

#else

	return false;

#endif
}

void AHTTP_Server_LHV::HTTP_Server_Stop()
{
#ifdef _WIN64
	
	if (this->Thread_LibHv)
	{
		delete this->Thread_LibHv;
		this->Thread_LibHv = nullptr;
	}

	return;

#else
	return;
#endif
}

bool AHTTP_Server_LHV::HTTP_Server_Toggle(bool bIsPause)
{
#ifdef _WIN64
	if (!this->Thread_LibHv)
	{
		return false;
	}

	return this->Thread_LibHv->Toggle(bIsPause);
#else
	return false;
#endif
}