#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHttpServers : uint8
{
	Server_Oatpp			UMETA(DisplayName = "Oatpp"),
	Server_Workflow			UMETA(DisplayName = "Workflow"),
	Server_IxWebSocket		UMETA(DisplayName = "IxWebSokcet"),
	Server_MG				UMETA(DisplayName = "MG"),
	Server_LibWebSocket		UMETA(DisplayName = "LibWebSocket"),
};
ENUM_CLASS_FLAGS(EHttpServers)

UENUM(BlueprintType)
enum class EHttpRequestTypes : uint8
{
	None		UMETA(DisplayName = "None"),
	GET			UMETA(DisplayName = "Get"),
	POST		UMETA(DisplayName = "Post"),
	PUT			UMETA(DisplayName = "Put"),
	DEL			UMETA(DisplayName = "Delete"),
	OPTIONS		UMETA(DisplayName = "Options"),
	PATCH		UMETA(DisplayName = "Patch"),
};
ENUM_CLASS_FLAGS(EHttpRequestTypes)

UENUM(BlueprintType)
enum class EHttpContentTypes : uint8
{
	None	UMETA(DisplayName = "None"),
	PDF		UMETA(DisplayName = "application/pdf"),
	JSON	UMETA(DisplayName = "application/json"),
	TEXT	UMETA(DisplayName = "text/plain"),
	HTML	UMETA(DisplayName = "text/html"),
};
ENUM_CLASS_FLAGS(EHttpContentTypes)

UENUM(BlueprintType)
enum class EHttpResponseCodesBp : uint8
{
	Unknown				UMETA(DisplayName = "Unknown",			ToolTip = "Status code not set yet"),
	Continue			UMETA(DisplayName = "Continue",			ToolTip = "the request can be continued."),
	SwitchProtocol		UMETA(DisplayName = "SwitchProtocol",	ToolTip = "the server has switched protocols in an upgrade header."),
	Ok					UMETA(DisplayName = "Ok",				ToolTip = "the request completed successfully."),
	Created				UMETA(DisplayName = "Created",			ToolTip = "the request has been fulfilled and resulted in the creation of a new resource."), 
	Accepted			UMETA(DisplayName = "Accepted",			ToolTip = "the request has been accepted for processing, but the processing has not been completed."),
	Partial				UMETA(DisplayName = "Partial",			ToolTip = "the returned meta information in the entity-header is not the definitive set available from the origin server."),
	NoContent			UMETA(DisplayName = "NoContent",		ToolTip = "the server has fulfilled the request, but there is no new information to send back."),
	ResetContent		UMETA(DisplayName = "ResetContent",		ToolTip = "the request has been completed, and the client program should reset the document view that caused the request to be sent to allow the user to easily initiate another input action."), 
	PartialContent		UMETA(DisplayName = "PartialContent",	ToolTip = "the server has fulfilled the partial get request for the resource."),
	Ambiguous			UMETA(DisplayName = "Ambiguous",		ToolTip = "the server couldn't decide what to return."),
	Moved 				UMETA(DisplayName = "Moved",			ToolTip = "the requested resource has been assigned to a new permanent uri (uniform resource identifier), and any future references to this resource should be done using one of the returned uris."),
	Redirect			UMETA(DisplayName = "Redirect",			ToolTip = "the requested resource resides temporarily under a different uri (uniform resource identifier)."),
	RedirectMethod		UMETA(DisplayName = "RedirectMethod",	ToolTip = "the response to the request can be found under a different uri (uniform resource identifier) and should be retrieved using a get http verb on that resource."),
	NotModified			UMETA(DisplayName = "NotModified",		ToolTip = "the requested resource has not been modified."),
	UseProxy			UMETA(DisplayName = "UseProxy",			ToolTip = "the requested resource must be accessed through the proxy given by the location field."),
	RedirectKeepVerb	UMETA(DisplayName = "RedirectKeepVerb", ToolTip = "the redirected request keeps the same http verb. http/1.1 behavior."),
	BadRequest			UMETA(DisplayName = "BadRequest",		ToolTip = "the request could not be processed by the server due to invalid syntax."),
	Denied				UMETA(DisplayName = "Denied",			ToolTip = "the requested resource requires user authentication."),
	PaymentReq			UMETA(DisplayName = "PaymentReq",		ToolTip = "not currently implemented in the http protocol."),
	Forbidden			UMETA(DisplayName = "Forbidden",		ToolTip = "the server understood the request, but is refusing to fulfill it."),
	NotFound			UMETA(DisplayName = "NotFound",			ToolTip = "the server has not found anything matching the requested uri (uniform resource identifier)."),
	BadMethod			UMETA(DisplayName = "BadMethod",		ToolTip = "the http verb used is not allowed."),
	NoneAcceptable		UMETA(DisplayName = "NoneAcceptable",	ToolTip = "no responses acceptable to the client were found."),
	ProxyAuthReq		UMETA(DisplayName = "ProxyAuthReq",		ToolTip = "proxy authentication required."),
	RequestTimeout		UMETA(DisplayName = "RequestTimeout",	ToolTip = "the server timed out waiting for the request."),
	Conflict			UMETA(DisplayName = "Conflict",			ToolTip = "the request could not be completed due to a conflict with the current state of the resource. the user should resubmit with more information."),
	Gone				UMETA(DisplayName = "Gone",				ToolTip = "the requested resource is no longer available at the server, and no forwarding address is known."),
	LengthRequired		UMETA(DisplayName = "LengthRequired",	ToolTip = "the server refuses to accept the request without a defined content length."),
	PrecondFailed		UMETA(DisplayName = "PrecondFailed",	ToolTip = "the precondition given in one or more of the request header fields evaluated to false when it was tested on the server."),
	RequestTooLarge		UMETA(DisplayName = "RequestTooLarge",	ToolTip = "the server is refusing to process a request because the request entity is larger than the server is willing or able to process."),
	UriTooLong			UMETA(DisplayName = "UriTooLong",		ToolTip = "the server is refusing to service the request because the request uri (uniform resource identifier) is longer than the server is willing to interpret."),
	UnsupportedMedia	UMETA(DisplayName = "UnsupportedMedia", ToolTip = "the server is refusing to service the request because the entity of the request is in a format not supported by the requested resource for the requested method."),
	TooManyRequests		UMETA(DisplayName = "TooManyRequests",	ToolTip = "too many requests, the server is throttling"),
	RetryWith			UMETA(DisplayName = "RetryWith",		ToolTip = "the request should be retried after doing the appropriate action."),
	ServerError			UMETA(DisplayName = "ServerError",		ToolTip = "the server encountered an unexpected condition that prevented it from fulfilling the request."),
	NotSupported		UMETA(DisplayName = "NotSupported",		ToolTip = "the server does not support the functionality required to fulfill the request."),
	BadGateway			UMETA(DisplayName = "BadGateway",		ToolTip = "the server, while acting as a gateway or proxy, received an invalid response from the upstream server it accessed in attempting to fulfill the request."),
	ServiceUnavail		UMETA(DisplayName = "ServiceUnavail",	ToolTip = "the service is temporarily overloaded."),
	GatewayTimeout		UMETA(DisplayName = "GatewayTimeout",	ToolTip = "the request was timed out waiting for a gateway."),
	VersionNotSup		UMETA(DisplayName = "VersionNotSup",	ToolTip = "the server does not support, or refuses to support, the http protocol version that was used in the request message.")
};
ENUM_CLASS_FLAGS(EHttpResponseCodesBp)

UENUM(BlueprintType)
enum class EMailServers : uint8
{
	Gmail		UMETA(DisplayName = "Gmail"),
	Outlook		UMETA(DisplayName = "Outlook"),
	Office365	UMETA(DisplayName = "Office 365")
};
ENUM_CLASS_FLAGS(EMailServers)

UENUM(BlueprintType)
enum class EMailSecurity : uint8
{
	NoSecurity	UMETA(DisplayName = "No Security"),
	TLS			UMETA(DisplayName = "TLS"),
	StartTLS	UMETA(DisplayName = "Start TLS")
};
ENUM_CLASS_FLAGS(EMailSecurity)