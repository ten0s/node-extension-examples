#include <napi.h>
#include "functionexample.h"
#include "classexample.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    functionexample::Init(env, exports);
    ClassExample::Init(env, exports);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
