// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_Basic.h"

#include "HttpPath.h"
#include "HttpServerModule.h"
#include "HttpServerRequest.h"
#include "HttpServerResponse.h"

// Sets default values
AHTTP_Server_Basic::AHTTP_Server_Basic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHTTP_Server_Basic::BeginPlay()
{
    this->HttpServer_Basic_Start();
	Super::BeginPlay();
}

void AHTTP_Server_Basic::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    this->HttpServer_Basic_Stop();
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AHTTP_Server_Basic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHTTP_Server_Basic::HttpServer_Basic_Start()
{
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

    FHttpRouteHandle Route_Get = this->httpRouter->BindRoute(FHttpPath("/get"), EHttpServerRequestVerbs::VERB_GET, [this, Callback_Parse_Request](const FHttpServerRequest& Request, const FHttpResultCallback& Response)
        {
            UHttpServerBasicResponse* ResponseObject = NewObject<UHttpServerBasicResponse>();
            ResponseObject->Response = Response;

            this->DelegateHttpMessageBasic.Broadcast(ResponseObject, Callback_Parse_Request(Request));
            return true;
        }
    );
    this->Array_Routes.Add(Route_Get);

    FHttpRouteHandle Route_Post = this->httpRouter->BindRoute(FHttpPath("/post"), EHttpServerRequestVerbs::VERB_POST, [this, Callback_Parse_Request](const FHttpServerRequest& Request, const FHttpResultCallback& Response)
        {
            UHttpServerBasicResponse* ResponseObject = NewObject<UHttpServerBasicResponse>();
            ResponseObject->Response = Response;

            this->DelegateHttpMessageBasic.Broadcast(ResponseObject, Callback_Parse_Request(Request));
            return true;
        }
    );
    this->Array_Routes.Add(Route_Post);

    FHttpRouteHandle Route_Put = this->httpRouter->BindRoute(FHttpPath("/put"), EHttpServerRequestVerbs::VERB_PUT, [this, Callback_Parse_Request](const FHttpServerRequest& Request, const FHttpResultCallback& Response)
        {
            UHttpServerBasicResponse* ResponseObject = NewObject<UHttpServerBasicResponse>();
            ResponseObject->Response = Response;

            this->DelegateHttpMessageBasic.Broadcast(ResponseObject, Callback_Parse_Request(Request));
            return true;
        }
    );
    this->Array_Routes.Add(Route_Put);

    FHttpRouteHandle Route_Delete = this->httpRouter->BindRoute(FHttpPath("/delete"), EHttpServerRequestVerbs::VERB_DELETE, [this, Callback_Parse_Request](const FHttpServerRequest& Request, const FHttpResultCallback& Response)
        {
            UHttpServerBasicResponse* ResponseObject = NewObject<UHttpServerBasicResponse>();
            ResponseObject->Response = Response;

            this->DelegateHttpMessageBasic.Broadcast(ResponseObject, Callback_Parse_Request(Request));
            return true;
        }
    );
    this->Array_Routes.Add(Route_Delete);

    FHttpRouteHandle Route_Patch = this->httpRouter->BindRoute(FHttpPath("/patch"), EHttpServerRequestVerbs::VERB_PATCH, [this, Callback_Parse_Request](const FHttpServerRequest& Request, const FHttpResultCallback& Response)
        {
            UHttpServerBasicResponse* ResponseObject = NewObject<UHttpServerBasicResponse>();
            ResponseObject->Response = Response;

            this->DelegateHttpMessageBasic.Broadcast(ResponseObject, Callback_Parse_Request(Request));
            return true;
        }
    );
    this->Array_Routes.Add(Route_Patch);

    FHttpRouteHandle Route_Options = this->httpRouter->BindRoute(FHttpPath("/options"), EHttpServerRequestVerbs::VERB_OPTIONS, [this, Callback_Parse_Request](const FHttpServerRequest& Request, const FHttpResultCallback& Response)
        {
            UHttpServerBasicResponse* ResponseObject = NewObject<UHttpServerBasicResponse>();
            ResponseObject->Response = Response;

            this->DelegateHttpMessageBasic.Broadcast(ResponseObject, Callback_Parse_Request(Request));
            return true;
        }
    );
    this->Array_Routes.Add(Route_Options);

    httpServerModule.StartAllListeners();

    UE_LOG(LogTemp, Display, TEXT("HTTP Server Basic -> Started."))
}

bool AHTTP_Server_Basic::HttpServer_Basic_Stop()
{
    FHttpServerModule& httpServerModule = FHttpServerModule::Get();
    httpServerModule.StopAllListeners();

    for (int32 Index_Routes = 0; Index_Routes < this->Array_Routes.Num(); Index_Routes++)
    {
        this->httpRouter->UnbindRoute(this->Array_Routes[Index_Routes]);
    }

    this->Array_Routes.Empty();
    this->httpRouter = nullptr;

    UE_LOG(LogTemp, Display, TEXT("HTTP Server Basic -> Closed."));

    return true;
}