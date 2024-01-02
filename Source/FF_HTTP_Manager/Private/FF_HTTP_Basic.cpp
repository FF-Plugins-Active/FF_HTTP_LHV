// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_Basic.h"

#ifdef _WIN64
#include "HttpPath.h"
#include "HttpServerModule.h"
#include "HttpServerRequest.h"
#include "HttpServerResponse.h"
#endif

// Sets default values
AHTTP_Server_Basic::AHTTP_Server_Basic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHTTP_Server_Basic::BeginPlay()
{
#ifdef _WIN64
    this->HttpServer_Basic_Start();
#endif
	Super::BeginPlay();
}

void AHTTP_Server_Basic::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#ifdef _WIN64
    this->HttpServer_Basic_Stop();
#endif
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_Basic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

EHttpServerRequestVerbs AHTTP_Server_Basic::BpRequestToUeRequest(EHttpRequestTypes BP_Request)
{
    switch (BP_Request)
    {
    case EHttpRequestTypes::None:
        return EHttpServerRequestVerbs::VERB_NONE;
    case EHttpRequestTypes::GET:
        return EHttpServerRequestVerbs::VERB_GET;
    case EHttpRequestTypes::POST:
        return EHttpServerRequestVerbs::VERB_POST;
    case EHttpRequestTypes::PUT:
        return EHttpServerRequestVerbs::VERB_PUT;
    case EHttpRequestTypes::DEL:
        return EHttpServerRequestVerbs::VERB_DELETE;
    case EHttpRequestTypes::OPTIONS:
        return EHttpServerRequestVerbs::VERB_OPTIONS;
    case EHttpRequestTypes::PATCH:
        return EHttpServerRequestVerbs::VERB_PATCH;
    default:
        return EHttpServerRequestVerbs::VERB_NONE;
    }
}

void AHTTP_Server_Basic::HttpServer_Basic_Start()
{
#ifdef _WIN64
    auto Callback_Parse_Request = [](const FHttpServerRequest& Request)->FHttpServerMessage
        {
            FHttpServerMessage ExposedRequest;
            ExposedRequest.PeerAddress = Request.PeerAddress.IsValid() ? Request.PeerAddress.Get()->ToString(true) : "";
            ExposedRequest.Body = Request.Body;
            ExposedRequest.RelativePath = Request.RelativePath.GetPath();
            ExposedRequest.Query = Request.QueryParams;
            ExposedRequest.Path_Params = Request.PathParams;

            TMap<FString, FStringArrayStruct> Headers;

            TArray<FString> RequestHeaderKeys;
            Request.Headers.GetKeys(RequestHeaderKeys);
            for (int32 Index_Header_Keys = 0; Index_Header_Keys < RequestHeaderKeys.Num(); Index_Header_Keys++)
            {
                FStringArrayStruct KeyElements;
                KeyElements.Array_String = *Request.Headers.Find(RequestHeaderKeys[Index_Header_Keys]);

                Headers.Add(RequestHeaderKeys[Index_Header_Keys], KeyElements);
            }

            ExposedRequest.Headers = Headers;

            return ExposedRequest;
        };

    FHttpServerModule& httpServerModule = FHttpServerModule::Get();
    this->httpRouter = httpServerModule.GetHttpRouter(this->Port);

    TArray<FString> Route_Paths;
    this->Routes.GenerateKeyArray(Route_Paths);

    for (int32 Index_Paths = 0; Index_Paths < Route_Paths.Num(); Index_Paths++)
    {
        FHttpRouteHandle Each_Route_Handle = this->httpRouter->BindRoute(FHttpPath("/" + Route_Paths[Index_Paths]), this->BpRequestToUeRequest(*Routes.Find(Route_Paths[Index_Paths])), [this, Callback_Parse_Request](const FHttpServerRequest& Request, const FHttpResultCallback& Response)
            {
                UHttpServerBasicResponse* ResponseObject = NewObject<UHttpServerBasicResponse>();
                ResponseObject->Response_Callback = Response;

                this->DelegateHttpMessageBasic.Broadcast(ResponseObject, Callback_Parse_Request(Request));
                return true;
            }
        );

        this->Array_Route_Handles.Add(Each_Route_Handle);
    }

    httpServerModule.StartAllListeners();

    UE_LOG(LogTemp, Display, TEXT("HTTP Server Basic -> Started."))
#endif
}

void AHTTP_Server_Basic::HttpServer_Basic_Stop()
{
#ifdef _WIN64
    FHttpServerModule& httpServerModule = FHttpServerModule::Get();
    httpServerModule.StopAllListeners();

    for (int32 Index_Routes = 0; Index_Routes < this->Array_Route_Handles.Num(); Index_Routes++)
    {
        this->httpRouter->UnbindRoute(this->Array_Route_Handles[Index_Routes]);
    }

    this->Array_Route_Handles.Empty();
    this->httpRouter = nullptr;

    UE_LOG(LogTemp, Display, TEXT("HTTP Server Basic -> Closed."));

    return;
#endif
}