#pragma once

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#include "hv/HttpServer.h"
#include "hv/hthread.h"    // import hv_gettid
#include "hv/hasync.h"     // import hv::async
#include "hv/requests.h"   // import requests::async
#endif
THIRD_PARTY_INCLUDES_END