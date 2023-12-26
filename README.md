# FF_HTTP_Advanced

## GOAL
Our goal is implementing non-blocking and Async HTTP servers to Unreal Engine 5 and running them on FRunnableThread to make high performance (both Unreal project and HTTP server) services with 3D capabilities.<br />
We integrated these libraries

- Oatpp (swagger - zLib - openssl plugins included)
- Sogou Workflow
- Ithewei LibHv
- Machine Zone IXWebSocket

## NOTES
Workflow gives "_DllMainCRTStartup" error if we try to integrate it as "External Module". So, you can see it in Source/FF_HTTP_Advanced/ThirdParty/Workflow.

We integrated multiple libraries because we wanted to give freedom to other developers when they want to improve plugin with their library choice.

Each library has their unique FRunnableThread class which named like "HTTP_Thread_LibraryName" and there is one blueprint exposed actor which has an enumeration to allow you to select which library you want to use.


## ROADMAP
Right now plugin doesn't have server implementations. We will implement them in time.

## WON'T HAVE THESE
We won't integrate any database libraries to this plugin. Because we believe that accessing databases or any other datasources is NOT HTTP server's job.
We will intentionally broadcast requests as a multicast delegate from FRunnableThread. (It's execution chain will come from FRunnableThread. For this reason, be cautious when about if you need specifically Game/Render or Audio Thread).
So, you can implement your data access method and give a response with blueprints. (In our use case, we store our datas in a TMap and send that data.)
