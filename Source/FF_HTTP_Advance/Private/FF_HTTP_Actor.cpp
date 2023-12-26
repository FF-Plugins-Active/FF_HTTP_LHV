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
	if (this->Server_Name.IsEmpty() || this->Server_Name.Len() > 15)
	{
		return false;
	}

	switch (this->ServerLibrary)
	{

	case EHttpServers::Server_IxWebSocket:
		
		this->Thread_IXWeb = new FHTTP_Thread_IXWeb(this);

		if (this->Thread_IXWeb)
		{
			return true;
		}

		else
		{
			return false;
		}

	case EHttpServers::Server_LibHv:
		
		this->Thread_LibHv = new FHTTP_Thread_LibHv(this);
		
		if (this->Thread_LibHv)
		{
			return true;
		}

		else
		{
			return false;
		}

	case EHttpServers::Server_Oatpp:
		
		this->Thread_Oatpp = new FHTTP_Thread_Oatpp(this);
		
		if (this->Thread_Oatpp)
		{
			return true;
		}

		else
		{
			return false;
		}

	case EHttpServers::Server_Workflow:
		
		this->Thread_Workflow = new FHTTP_Thread_Workflow(this);
		
		if (this->Thread_Workflow)
		{
			return true;
		}

		else
		{
			return false;
		}

	default:
		
		this->Thread_Oatpp = new FHTTP_Thread_Oatpp(this);

		if (this->Thread_Oatpp)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	return false;
}

void AFF_HTTP_Actor::HTTP_Server_Stop()
{
	switch (this->ServerLibrary)
	{

	case EHttpServers::Server_IxWebSocket:

		if (this->Thread_IXWeb)
		{
			delete this->Thread_IXWeb;
			return;
		}

		else
		{
			return;
		}

	case EHttpServers::Server_LibHv:

		if (this->Thread_LibHv)
		{
			delete this->Thread_LibHv;
			return;
		}

		else
		{
			return;
		}

	case EHttpServers::Server_Oatpp:

		if (this->Thread_Oatpp)
		{
			delete this->Thread_Oatpp;
			return;
		}

		else
		{
			return;
		}

	case EHttpServers::Server_Workflow:

		if (this->Thread_Workflow)
		{
			delete this->Thread_Workflow;
			return;
		}

		else
		{
			return;
		}

	default:

		if (this->Thread_Oatpp)
		{
			delete this->Thread_Oatpp;
			return;
		}

		else
		{
			return;
		}
	}
}

void AFF_HTTP_Actor::HTTP_Server_Toggle(bool bPause)
{

}