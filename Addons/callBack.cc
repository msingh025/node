#include <node.h>

using namespace v8;

void RunCallback(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local <Object> obj = Object::New(isolate);
  double numDouble= 12.67;
  Local <Number> num = Number::New (isolate,numDouble);
  obj->Set(String::NewFromUtf8(isolate, "msg"),String::NewFromUtf8(isolate, "manish singh"));
  obj->Set(String::NewFromUtf8(isolate, "id"), num);
  Local<Value> argv[argc] = { obj};
  cb->Call(isolate->GetCurrentContext()->Global(), argc, argv);
}

void Init(Handle<Object> exports, Handle<Object> module) {
  NODE_SET_METHOD(module, "exports", RunCallback);
}

NODE_MODULE(addon, Init)
