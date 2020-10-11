#include <node.h>
#include <iostream>

using namespace v8;
using namespace std;

void HelloWorld(const FunctionCallbackInfo<Value>& args) {
   cout << "Hello, world!" << endl;
}

void AddNumbers(const FunctionCallbackInfo<Value>& args) {
   //Isolate* isolate = args.GetIsolate();
   double value = args[0]->NumberValue();
   int count = args[1]->IntegerValue();

   double result = 0;
   for (int i = 0; i < count; i++) {
       result += value;
   }

   args.GetReturnValue().Set(result);
}

void Initialize(Local<Object> exports) {
   NODE_SET_METHOD(exports, "helloWorld", HelloWorld);
   NODE_SET_METHOD(exports, "addNumbers", AddNumbers);
}

NODE_MODULE(addon, Initialize);
