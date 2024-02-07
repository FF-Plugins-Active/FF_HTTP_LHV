// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_Advance.h"

// Sets default values
AHTTP_Server_Advance::AHTTP_Server_Advance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHTTP_Server_Advance::BeginPlay()
{
#ifdef _WIN64
	this->HTTP_Server_Start();
#endif
	
	Super::BeginPlay();
}

void AHTTP_Server_Advance::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#ifdef _WIN64
	this->HTTP_Server_Stop();
#endif

	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_Advance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHTTP_Server_Advance::HTTP_Server_Start()
{
#ifdef _WIN64
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

#else

	return false;

#endif
}

void AHTTP_Server_Advance::HTTP_Server_Stop()
{
#ifdef _WIN64
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

#else

#endif
}

void AHTTP_Server_Advance::HTTP_Server_Toggle(bool bPause)
{

}