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
	Super::BeginPlay();

	FString Out_Code;
	if (!this->HTTP_Server_Start(Out_Code))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Out_Code);
	}
}

// Called when the game ends or when destroyed.
void AHTTP_Server_LHV::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	this->HTTP_Server_Stop();
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_LHV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHTTP_Server_LHV::HTTP_Server_Start(FString& Out_Code)
{
#if (LHV_HANDLER_TYPE == 0)

	auto Callback_Router_Handler = [this](HttpRequest* Request, HttpResponse* Response)->int
		{
			UHttpConnectionLhv* LibHvConnection = NewObject<UHttpConnectionLhv>();
			LibHvConnection->Request = Request;
			LibHvConnection->Response = Response;
			LibHvConnection->RequestTime = FDateTime::Now();

			this->Parent_Actor->Delegate_HTTP_LibHv_Request.Broadcast(LibHvConnection);
			this->Parent_Actor->OnHttpAdvMessage(LibHvConnection);

			LibHvConnection->Future.Wait();
			int StatusCode = LibHvConnection->Future.Get();

			return StatusCode;
		};

#elif (LHV_HANDLER_TYPE == 1)

	auto Callback_Router_Handler = [this](const HttpRequestPtr& Request, const HttpResponseWriterPtr& Response)
		{
			UHttpConnectionLhv* LibHvConnection = NewObject<UHttpConnectionLhv>();
			LibHvConnection->RequestPtr = Request;
			LibHvConnection->ResponsePtr = Response;
			LibHvConnection->RequestTime = FDateTime::Now();

			this->Delegate_HTTP_LibHv_Request.Broadcast(LibHvConnection);
			this->OnHttpAdvMessage(LibHvConnection);
		};

#elif (LHV_HANDLER_TYPE == 2)

	auto Callback_Router_Handler = [this](const HttpContextPtr& Context)->int
		{
			UHttpConnectionLhv* LibHvConnection = NewObject<UHttpConnectionLhv>();
			LibHvConnection->Context = &Context;
			LibHvConnection->RequestTime = FDateTime::Now();

			this->Delegate_HTTP_LibHv_Request.Broadcast(LibHvConnection);
			this->OnHttpAdvMessage(LibHvConnection);

			LibHvConnection->Future.Wait();
			int StatusCode = LibHvConnection->Future.Get();

			return StatusCode;
		};

#endif

	auto Callback_Router_Error = [this](const HttpContextPtr& Context)->int
		{
			return Context->sendFile(TCHAR_TO_UTF8(*this->Server_Path_404));
		};

	try
	{
		this->HTTP_LVH_Router.AllowCORS();
		this->HTTP_LVH_Router.errorHandler = Callback_Router_Error;
		this->HTTP_LVH_Router.Static("/", TCHAR_TO_UTF8(*this->Server_Path_Root));							// Static Site

		this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*this->API_URI), Callback_Router_Handler);					// Non-Querry APIs without "/" at end.
		this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*(this->API_URI + "/")), Callback_Router_Handler);			// Non-Querry APIs with "/" at end.
		this->HTTP_LVH_Router.Any(TCHAR_TO_UTF8(*(this->API_URI + "/*")), Callback_Router_Handler);			// APIs with Querries.

		this->HTTP_LVH_Server.service = &this->HTTP_LVH_Router;
		this->HTTP_LVH_Server.port = this->Port_HTTP;

		this->HTTP_LVH_Server.setThreadNum(this->ThreadsNum);
		this->HTTP_LVH_Server.start();
	}
	
	catch (const std::exception& Exception)
	{
		const FString ExceptionString = Exception.what();
		Out_Code = ExceptionString;
		return false;
	}

	this->Delegate_HTTP_LibHv_Start.Broadcast();
	this->OnLibHvStart();
	
	return true;
}

void AHTTP_Server_LHV::HTTP_Server_Stop()
{
	this->HTTP_LVH_Server.stop();
	//hv::async::cleanup();

	this->Delegate_HTTP_LibHv_Stop.Broadcast();
	this->OnLibHvStart();
}