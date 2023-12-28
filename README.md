# FF_HTTP_Advanced

## GOAL
Our goal is implementing non-blocking and Async HTTP servers to Unreal Engine 5 and running them on `FRunnableThread` to make high performance (both Unreal project and HTTP server) services with 3D capabilities.

## SUPPORTED FEATURES
We integrated these libraries

- Oatpp (swagger - zLib - openssl plugins included)
- Sogou Workflow
- Ithewei LibHv
- Machine Zone IXWebSocket

Workflow gives `_DllMainCRTStartup` error if we try to integrate it as `External Module`. So, you can see it in here. <br />
`Source/FF_HTTP_Advanced/ThirdParty/Workflow`

We integrated multiple libraries because we wanted to give freedom to other developers when they want to improve our plugin with their library choice.<br />
Each library has their unique `FRunnableThread` class which named like `HTTP_Thread_LibraryName` and there is one blueprint exposed actor which has an enumeration to allow you to select which library you want to use.

## ROADMAP
Right now plugin doesn't have server implementations. We will implement them in time.

## NOT-SUPPORTED FEATURES
We won't integrate any database libraries to this plugin. Because we believe that accessing databases or any other datasources is NOT HTTP server plugin's job.

## BASIC INTRODUCTION
(We will improve this after finishing implementation.)<br />

We will intentionally expose server start, server stop and requests notifications to blueprints from `FRunnableThread` with `multicast delegate broadcast` and/or `blueprint implementable event`.<br />
Execution chain will come from that thread and when you put your mechanics (data access or other stuffs), `that thread` will do necessary calculations. <br />
So, there will be no impact on `Unreal project's` performance but be cautious if you need specific thread (like game, render or audio) for your operations.

## PLATFORM SUPPORT
We won't have a plan to support other platforms like Linux, Mac, Android and iOS. If you need other platforms, build your library and implement it to your fork.

## ENGINE SUPPORT
We support "only" current engine release. We update our plugin "after one month" when there is a new one.
(For example, current engine release at December 2023 is Unreal Engine 5.3.2. We only support this version. When 5.4 released, we will update it after one month and there will be no 5.3 support. If you need it, it is your responsibility to solve breaking changes on your fork.)

## DEVELOPMENT SUPPORT
If you need support about "HTTP Server libraries", post issue on their GitHub repo. We just implement their library to Unreal Engine.
