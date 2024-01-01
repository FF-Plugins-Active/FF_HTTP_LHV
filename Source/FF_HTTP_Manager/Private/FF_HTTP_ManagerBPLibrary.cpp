// Copyright Epic Games, Inc. All Rights Reserved.

#include "FF_HTTP_ManagerBPLibrary.h"
#include "FF_HTTP_Manager.h"

// UE Includes.
#include "Misc/App.h"
#include "Misc/FileHelper.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"     // Join string arrays for headers.

// UE HTTP Client Basic.
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

THIRD_PARTY_INCLUDES_START
#include "curl/curl.h"
#include <string>                           // Message Id
#include <iostream>                         // Message Id
#include <random>                           // Message Id
#include <algorithm>                        // Message Id
THIRD_PARTY_INCLUDES_END

UFF_HTTP_ManagerBPLibrary::UFF_HTTP_ManagerBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UFF_HTTP_ManagerBPLibrary::FF_HTTP_Client_Basic_Bytes(FDelegateHttpClient DelegateClient, FString In_Url, TMap<FString, FString> In_Header, TArray<uint8> In_Body, EHttpRequestTypes In_Request_Type, EHttpContentTypes ContentType, bool bAddDefaultHeaders)
{
    if (In_Url.IsEmpty())
    {
        return;
    }

    AsyncTask(ENamedThreads::AnyNormalThreadNormalTask, [DelegateClient, In_Request_Type, In_Url, In_Header, In_Body, ContentType, bAddDefaultHeaders]()
        {
            FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

            switch (In_Request_Type)
            {
            case EHttpRequestTypes::None:
                break;
            case EHttpRequestTypes::GET:
                HttpRequest->SetVerb("GET");
                break;
            case EHttpRequestTypes::POST:
                HttpRequest->SetVerb("POST");
                break;
            case EHttpRequestTypes::PUT:
                HttpRequest->SetVerb("PUT");
                break;
            case EHttpRequestTypes::DEL:
                HttpRequest->SetVerb("Delete");
                break;
            default:
                HttpRequest->SetVerb("GET");
                break;
            }

            switch (ContentType)
            {
            case EHttpContentTypes::None:
                break;

            case EHttpContentTypes::PDF:
                HttpRequest->AppendToHeader("Contenty-Type", "application/pdf");
                break;

            case EHttpContentTypes::JSON:
                HttpRequest->AppendToHeader("Contenty-Type", "application/json");
                break;

            case EHttpContentTypes::TEXT:
                HttpRequest->AppendToHeader("Contenty-Type", "text/plain");
                break;

            default:
                break;
            }

            HttpRequest->SetURL(In_Url);
            HttpRequest->SetContent(In_Body);

            TArray<FString> Header_Keys;
            In_Header.GenerateKeyArray(Header_Keys);
            for (int32 Index_Header = 0; Index_Header < Header_Keys.Num(); Index_Header++)
            {
                FString EachHeader_Name = Header_Keys[Index_Header];
                FString EachHeader_Value = *In_Header.Find(EachHeader_Name);

                HttpRequest->AppendToHeader(EachHeader_Name, EachHeader_Value);
            }

            if (bAddDefaultHeaders)
            {
                HttpRequest->AppendToHeader("Cache-Control", "no-cache");
                HttpRequest->AppendToHeader("Accept", "*/*");
                HttpRequest->AppendToHeader("Accept-Encoding", "gzip, deflate, br");
                HttpRequest->AppendToHeader("Connection", "keep-alive");
            }
            
            HttpRequest->OnProcessRequestComplete().BindLambda([DelegateClient](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
                {
                    AsyncTask(ENamedThreads::GameThread, [DelegateClient, Response, bWasSuccessful]()
                        {
                            FHttpClientResponse ResponseStruct;
                            if (bWasSuccessful)
                            {
                                ResponseStruct.Headers = Response->GetAllHeaders();
                                ResponseStruct.Content = Response->GetContent();
                                ResponseStruct.ContentString = Response->GetContentAsString();
                                ResponseStruct.ContentLenght = Response->GetContentLength();
                                ResponseStruct.ContentType = Response->GetContentType();
                                //ResponseStruct.Url = Response->GetURL().IsEmpty() ? "" : Response->GetURL(); This gives error.
                                ResponseStruct.ResponseCode = Response->GetResponseCode();
                            }

                            DelegateClient.ExecuteIfBound(bWasSuccessful, ResponseStruct);
                        }
                    );
                }
            );

            HttpRequest->ProcessRequest();
        }
    );
}

void UFF_HTTP_ManagerBPLibrary::FF_HTTP_Client_Basic_String(FDelegateHttpClient DelegateClient, FString In_Url, TMap<FString, FString> In_Header, FString In_Body, EHttpRequestTypes In_Request_Type, EHttpContentTypes ContentType, bool bAddDefaultHeaders)
{
    if (In_Url.IsEmpty())
    {
        return;
    }

    AsyncTask(ENamedThreads::AnyNormalThreadNormalTask, [DelegateClient, In_Request_Type, In_Url, In_Header, In_Body, ContentType, bAddDefaultHeaders]()
        {
            FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();

            switch (In_Request_Type)
            {
            case EHttpRequestTypes::None:
                break;
            case EHttpRequestTypes::GET:
                HttpRequest->SetVerb("GET");
                break;
            case EHttpRequestTypes::POST:
                HttpRequest->SetVerb("POST");
                break;
            case EHttpRequestTypes::PUT:
                HttpRequest->SetVerb("PUT");
                break;
            case EHttpRequestTypes::DEL:
                HttpRequest->SetVerb("Delete");
                break;
            default:
                HttpRequest->SetVerb("GET");
                break;
            }

            switch (ContentType)
            {
            case EHttpContentTypes::None:
                break;

            case EHttpContentTypes::PDF:
                HttpRequest->AppendToHeader("Contenty-Type", "application/pdf");
                break;

            case EHttpContentTypes::JSON:
                HttpRequest->AppendToHeader("Contenty-Type", "application/json");
                break;

            case EHttpContentTypes::TEXT:
                HttpRequest->AppendToHeader("Contenty-Type", "text/plain");
                break;

            default:
                break;
            }

            HttpRequest->SetURL(In_Url);
            HttpRequest->SetContentAsString(In_Body);

            TArray<FString> Header_Keys;
            In_Header.GenerateKeyArray(Header_Keys);
            for (int32 Index_Header = 0; Index_Header < Header_Keys.Num(); Index_Header++)
            {
                FString EachHeader_Name = Header_Keys[Index_Header];
                FString EachHeader_Value = *In_Header.Find(EachHeader_Name);

                HttpRequest->AppendToHeader(EachHeader_Name, EachHeader_Value);
            }

            if (bAddDefaultHeaders)
            {
                HttpRequest->AppendToHeader("Cache-Control", "no-cache");
                HttpRequest->AppendToHeader("Accept", "*/*");
                HttpRequest->AppendToHeader("Accept-Encoding", "gzip, deflate, br");
                HttpRequest->AppendToHeader("Connection", "keep-alive");
            }

            HttpRequest->OnProcessRequestComplete().BindLambda([DelegateClient](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
                {
                    AsyncTask(ENamedThreads::GameThread, [DelegateClient, Response, bWasSuccessful]()
                        {
                            FHttpClientResponse ResponseStruct;
                            if (bWasSuccessful)
                            {
                                ResponseStruct.Headers = Response->GetAllHeaders();
                                ResponseStruct.Content = Response->GetContent();
                                ResponseStruct.ContentString = Response->GetContentAsString();
                                ResponseStruct.ContentLenght = Response->GetContentLength();
                                ResponseStruct.ContentType = Response->GetContentType();
                                //ResponseStruct.Url = Response->GetURL().IsEmpty() ? "" : Response->GetURL(); this gives error.
                                ResponseStruct.ResponseCode = Response->GetResponseCode();
                            }

                            DelegateClient.ExecuteIfBound(bWasSuccessful, ResponseStruct);
                        }
                    );
                }
            );

            HttpRequest->ProcessRequest();
        }
    );
}

bool UFF_HTTP_ManagerBPLibrary::HTTP_Server_Response_Lenght(FString& Out_Lenght, FString In_Response)
{
    if (In_Response.IsEmpty())
    {
        return false;
    }

    Out_Lenght = FString::FromInt(FTCHARToUTF8(In_Response.GetCharArray().GetData()).Length());

    return true;
}

void UFF_HTTP_ManagerBPLibrary::LibCurl_Send_Email(FDelegateMailSent DelegateMailSent, TArray<FMailAttachments> Attachments, TArray<FString> To, TArray<FString> Cc, TArray<FString> Bcc, FString Subject, FString Message, FString Sender, FString Password, FString CustomServer, FString In_Cert_Path, EMailServers KnownServers, EMailSecurity CustomServerSecurity)
{
    if (CustomServer.IsEmpty() && In_Cert_Path.IsEmpty())
    {
        DelegateMailSent.ExecuteIfBound(false, "Certificate path is empty.");
        return;
    }

    else if (!CustomServer.IsEmpty() && CustomServerSecurity != EMailSecurity::NoSecurity && In_Cert_Path.IsEmpty())
    {
        DelegateMailSent.ExecuteIfBound(false, "Certificate path is empty.");
        return;
    }

    if (!In_Cert_Path.IsEmpty())
    {
        if (UGameplayStatics::GetPlatformName() == "Windows")
        {
            FPaths::MakeStandardFilename(In_Cert_Path);

            if (!FPaths::FileExists(In_Cert_Path))
            {
                DelegateMailSent.ExecuteIfBound(false, "Certificate couldn't be found.");
                return;
            }

            FPaths::MakePlatformFilename(In_Cert_Path);
        }

        else if (UGameplayStatics::GetPlatformName() == "Android")
        {
            if (!FPaths::FileExists(In_Cert_Path))
            {
                DelegateMailSent.ExecuteIfBound(false, "Certificate couldn't be found.");
                return;
            }
        }
    }

    if (To.Num() == 0)
    {
        DelegateMailSent.ExecuteIfBound(false, "There is no mail recipient to sent.");
        return;
    }

    if (Attachments.Num() > 0)
    {
        int64 Extensions_Size = 0;
        for (int32 Index_Attachments = 0; Index_Attachments < Attachments.Num(); Index_Attachments++)
        {
            Extensions_Size = Extensions_Size + Attachments[Index_Attachments].Base64_Bytes.Num();
        }

        if (Extensions_Size >= (25 * 1024 * 1024))
        {
            DelegateMailSent.ExecuteIfBound(false, ("Attachments are too big.\r\nMax Size = 26214400 Bytes (25 MB).\r\nCurrent Size = " + FString::FromInt(Extensions_Size)));
            return;
        }
    }

    AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [DelegateMailSent, Attachments, To, Cc, Bcc, Subject, Message, Sender, Password, CustomServer, In_Cert_Path, KnownServers, CustomServerSecurity]()
        {
            /*
            *   Initialize CURL Object.
            */

            CURL* Curl = curl_easy_init();
            if (!Curl)
            {
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Curl object couldn't be initialized.");
                    }
                );

                return;
            }

            /*
            *   Server Configurations.
            */

            FString Server;
            if (CustomServer.IsEmpty())
            {
                switch (KnownServers)
                {

                case EMailServers::Gmail:
                    Server = "smtps://smtp.gmail.com:465";
                    curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYPEER, 1L);
                    break;

                case EMailServers::Outlook:
                    Server = "smtp://smtp-mail.outlook.com:587";
                    curl_easy_setopt(Curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
                    break;

                case EMailServers::Office365:
                    Server = "smtp://smtp.office365.com:587";
                    curl_easy_setopt(Curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
                    break;

                default:
                    Server = "smtps://smtp.gmail.com:465";
                    curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYPEER, 1L);
                    break;
                }
            }

            else
            {
                Server = CustomServer;

                switch (CustomServerSecurity)
                {

                case EMailSecurity::NoSecurity:
                    curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYPEER, 0L);
                    curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYHOST, 0L);
                    break;

                case EMailSecurity::TLS:
                    curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYPEER, 1L);
                    break;

                case EMailSecurity::StartTLS:
                    curl_easy_setopt(Curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
                    break;

                default:
                    curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYPEER, 0L);
                    curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYHOST, 0L);
                    break;
                }
            }

            // Initialize CURL Response.
            CURLcode Response = CURLE_OK;

            Response = curl_easy_setopt(Curl, CURLOPT_URL, TCHAR_TO_UTF8(*Server));
            if (Response != CURLE_OK)
            {
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Server couldn't be defined.");
                    }
                );

                return;
            }

            Response = curl_easy_setopt(Curl, CURLOPT_CAINFO, TCHAR_TO_UTF8(*In_Cert_Path));
            if (Response != CURLE_OK)
            {
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Cacert file couldn't be defined.");
                    }
                );

                return;
            }

            /*
            *   Create Recipients List.
            */

            curl_slist* Recipients = NULL;

            TArray<FString> Array_To;
            for (int32 Index_To = 0; Index_To < To.Num(); Index_To++)
            {
                Array_To.Add("<" + To[Index_To] + ">");
                Recipients = curl_slist_append(Recipients, TCHAR_TO_UTF8(*To[Index_To]));
            }

            TArray<FString> Array_Cc;
            if (Cc.Num() != 0)
            {
                for (int32 Index_Cc = 0; Index_Cc < Cc.Num(); Index_Cc++)
                {
                    Array_Cc.Add("<" + Cc[Index_Cc] + ">");
                    Recipients = curl_slist_append(Recipients, TCHAR_TO_UTF8(*Cc[Index_Cc]));
                }
            }

            TArray<FString> Array_Bcc;
            if (Bcc.Num() != 0)
            {
                for (int32 Index_Bcc = 0; Index_Bcc < Bcc.Num(); Index_Bcc++)
                {
                    Array_Bcc.Add("<" + Bcc[Index_Bcc] + ">");
                    Recipients = curl_slist_append(Recipients, TCHAR_TO_UTF8(*Bcc[Index_Bcc]));
                }
            }

            Response = curl_easy_setopt(Curl, CURLOPT_MAIL_RCPT, Recipients);
            if (Response != CURLE_OK)
            {
                curl_slist_free_all(Recipients);
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Recipients couldn't be defined.");
                    }
                );

                return;
            }

            Response = curl_easy_setopt(Curl, CURLOPT_MAIL_RCPT_ALLLOWFAILS, 1L);
            if (Response != CURLE_OK)
            {
                curl_slist_free_all(Recipients);
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Allow recipient fail rule couldn't be defined.");
                    }
                );

                return;
            }

            Response = curl_easy_setopt(Curl, CURLOPT_MAIL_FROM, TCHAR_TO_UTF8(*Sender));
            if (Response != CURLE_OK)
            {
                curl_slist_free_all(Recipients);
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "From value couldn't be defined.");
                    }
                );

                return;
            }

            Response = curl_easy_setopt(Curl, CURLOPT_USERNAME, TCHAR_TO_UTF8(*Sender));
            if (Response != CURLE_OK)
            {
                curl_slist_free_all(Recipients);
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Sender value couldn't be defined.");
                    }
                );

                return;
            }

            Response = curl_easy_setopt(Curl, CURLOPT_PASSWORD, TCHAR_TO_UTF8(*Password));
            if (Response != CURLE_OK)
            {
                curl_slist_free_all(Recipients);
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Password couldn't be defined.");
                    }
                );

                return;
            }

            /*
            *  Header.
            */

            auto Callback_Message_Id = []()->FString
                {
                    const size_t MESSAGE_ID_LEN = 37;

                    tm CurrentTime;
                    time_t TimeClass;
                    time(&TimeClass);

#ifdef _WIN64
                    gmtime_s(&CurrentTime, &TimeClass);

#else
                    gmtime64_r(&TimeClass, &CurrentTime);
#endif

                    std::string ret;
                    ret.resize(MESSAGE_ID_LEN);
                    size_t datelen = std::strftime(&ret[0], MESSAGE_ID_LEN, "%Y%m%d%H%M%S", &CurrentTime);
                    static const std::string alphaNum
                    {
                        "0123456789"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "abcdefghijklmnopqrstuvwxyz"
                    };

                    std::mt19937 gen;
                    std::uniform_int_distribution<> dis(0, alphaNum.length() - 1);
                    std::generate_n(ret.begin() + datelen, MESSAGE_ID_LEN - datelen, [&]() { return alphaNum[dis(gen)]; });
                    return ret.c_str();
                };

            curl_slist* Headers = NULL;
            Headers = curl_slist_append(Headers, TCHAR_TO_UTF8(*("Subject: " + Subject)));
            Headers = curl_slist_append(Headers, TCHAR_TO_UTF8(*("Message-ID: <" + Callback_Message_Id() + "@rfcpedant.example.org>")));
            Headers = curl_slist_append(Headers, TCHAR_TO_UTF8(*("Date: " + FDateTime::Now().ToString())));
            Headers = curl_slist_append(Headers, TCHAR_TO_UTF8(*("To: " + (Array_To.Num() == 1 ? Array_To[0] : UKismetStringLibrary::JoinStringArray(Array_To, ",")))));
            Headers = curl_slist_append(Headers, TCHAR_TO_UTF8(*("Cc: " + (Array_Cc.Num() == 1 ? Array_Cc[0] : UKismetStringLibrary::JoinStringArray(Array_Cc, ",")))));
            Headers = curl_slist_append(Headers, TCHAR_TO_UTF8(*("Bcc: " + (Array_Bcc.Num() == 1 ? Array_Bcc[0] : UKismetStringLibrary::JoinStringArray(Array_Bcc, ",")))));
            Headers = curl_slist_append(Headers, TCHAR_TO_UTF8(*("From: <" + Sender + ">")));
            Response = curl_easy_setopt(Curl, CURLOPT_HTTPHEADER, Headers);

            if (Response != CURLE_OK)
            {
                curl_slist_free_all(Recipients);
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Headers couldn't be defined.");
                    }
                );

                return;
            }

            /*
            *   Attachments.
            */

            curl_mime* Mime_Mail = curl_mime_init(Curl);
            curl_mimepart* Part;

            if (Attachments.Num() > 0)
            {
                for (int32 Index_Attachment = 0; Index_Attachment < Attachments.Num(); Index_Attachment++)
                {
                    Part = curl_mime_addpart(Mime_Mail);
                    curl_mime_data(Part, reinterpret_cast<const char*>(Attachments[Index_Attachment].Base64_Bytes.GetData()), Attachments[Index_Attachment].Base64_Bytes.Num());
                    curl_mime_encoder(Part, "base64");
                    curl_mime_filename(Part, TCHAR_TO_UTF8(*Attachments[Index_Attachment].Attachment_Name));
                    curl_mime_name(Part, "data");
                }
            }

            Part = curl_mime_addpart(Mime_Mail);
            curl_mime_data(Part, TCHAR_TO_UTF8(*Message), CURL_ZERO_TERMINATED);
            curl_slist* slist = curl_slist_append(NULL, "Content-Disposition: inline");
            curl_mime_headers(Part, slist, 1);
            curl_easy_setopt(Curl, CURLOPT_MIMEPOST, Mime_Mail);

            /*
            * Send mail and free memories.
            */

            Response = curl_easy_perform(Curl);
            if (Response != CURLE_OK)
            {
                curl_slist_free_all(Recipients);
                curl_slist_free_all(slist);
                curl_easy_cleanup(Curl);

                AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                    {
                        DelegateMailSent.ExecuteIfBound(false, "Libcurl couldn't perform.");

                    }
                );

                return;
            }

            curl_slist_free_all(Recipients);
            curl_slist_free_all(slist);
            curl_easy_cleanup(Curl);

            AsyncTask(ENamedThreads::GameThread, [DelegateMailSent]()
                {
                    DelegateMailSent.ExecuteIfBound(true, "Mail successfully sent.");
                }
            );
        }
    );
}