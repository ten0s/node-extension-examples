#include "functionexample.h"

std::string functionexample::hello() {
    return "Hello World";
}

int functionexample::add(int a, int b) {
    return a + b;
}

Napi::String functionexample::HelloWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::String ret = Napi::String::New(env, functionexample::hello());
    return ret;
}

Napi::Number functionexample::AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    int sum = functionexample::add(first.Int32Value(), second.Int32Value());
    Napi::Number ret = Napi::Number::New(env, sum);
    return ret;
}

Napi::Object functionexample::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("hello", Napi::Function::New(env, functionexample::HelloWrapped));
    exports.Set("add", Napi::Function::New(env, functionexample::AddWrapped));
    return exports;
}
