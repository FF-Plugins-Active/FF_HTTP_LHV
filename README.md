# FF_HTTP_Advanced

## GOAL
Our goal is implementing non-blocking and Async HTTP servers to Unreal Engine 5 and running them on FRunnableThread to make high performance (both Unreal project and HTTP server) services with 3D capabilities.<br />
We integrated these libraries

- Oatpp (swagger - zLib - openssl plugins included)
- Sogou Workflow
- Ithewei LibHv
- Machine Zone IXWebSocket

## NOTES
Workflow gives "_DllMainCRTStartup" error if we try to integrate it as "External Module". So, you can see it in here. <br />
"Source/FF_HTTP_Advanced/ThirdParty/Workflow"

We integrated multiple libraries because we wanted to give freedom to other developers when they want to improve our plugin with their library choice.

Each library has their unique FRunnableThread class which named like "HTTP_Thread_LibraryName" and there is one blueprint exposed actor which has an enumeration to allow you to select which library you want to use.

## ROADMAP
Right now plugin doesn't have server implementations. We will implement them in time.

## WON'T HAVE THESE
We won't integrate any database libraries to this plugin. Because we believe that accessing databases or any other datasources is NOT HTTP server's job.

We will intentionally broadcast requests as a multicast delegate from FRunnableThread. (It's execution chain will come from FRunnableThread. For this reason, be cautious when about if you need specifically Game/Render or Audio Thread).<br />
So, you can implement your data access method and give a response with blueprints. (In our use case, we store our datas in a TMap and send that data.)

## PLATFORM
We won't have a plan to support other Platforms like Linux, Mac, Android and iOS.

## ENGINE
We support "only" current engine release. We update our plugin "after one month" when there is a new one.
(For example, current engine release at December 2023 is Unreal Engine 5.3.2. We only support this version. When 5.4 released, we will update it after one month and there will be no 5.3 support. If you need it, it is your responsibility to solve breaking changes.)

## SUPPORT
If you need a support about "HTTP Server libraries", post issue on their GitHub repo. We just implement their library to Unreal Engine.
