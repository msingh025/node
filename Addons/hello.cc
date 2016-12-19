#include <node.h>
#include <v8.h>
#include <iostream>
using namespace v8;
using namespace std;
void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  Local<Value> v = args[0];
  Local<String>s = Local<String>::Cast(v);
  args.GetReturnValue().Set(s);
}
void Method2(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  Local <Object> obj = Object::New(isolate);
  //Local <string> s = "menaish";

  /*set the custom string and return it; */
  //Local<Value> argv[1] = { String::NewFromUtf8(isolate, "hello world") };

  /* this is type casting  *********/
  //Local<String>s = Local<String>::Cast(v);
  // cout <<"method two is called"<<endl;

  /* set the object value and return it *****************/
  //static const uint16_t chars[] = { '4', '2', 0 };

  char *x,y[10]="hemmlo";
  x = y;

  /*utf 8 string creating *******************/
  // definition of  NewFromUtf8 methodl
  // static Local< String > 	NewFromUtf8 (Isolate *isolate, const char *data, NewStringType type=kNormalString, int length=-1)

  Local<String> utf8 = String::NewFromUtf8(isolate, x);



  /*utf 16 string creating *******************/
  static const uint16_t chars[] = { '4', '2', 0 };
  v8::Local<v8::String> utf16 = v8::String::NewFromTwoByte(isolate, chars);

/********************** double data type return value ***************/

 double dbValue = 12.03;
 Local< Number> dNumber = Number::New(isolate, dbValue);

 /********************** Integer data type return value ***************/
  int32_t value_32 = 23;
  Local<Integer> dint23Value = Integer::New(isolate, value_32);

  /********************** Boolean data type return value ***************/
    bool valueB = true;
    Local<Boolean> valueBool = Boolean::New(isolate, valueB);

 obj->Set(String::NewFromUtf8(isolate, "msg"),String::NewFromUtf8(isolate, "manish singh"));
 obj->Set(String::NewFromUtf8(isolate, "id"),String::NewFromUtf8(isolate, "1"));
 obj->Set(String::NewFromUtf8(isolate, "utf8"),utf8);
 obj->Set(String::NewFromUtf8(isolate, "utf16"),utf16);
 obj->Set(String::NewFromUtf8(isolate, "number_double"),dNumber);
 obj->Set(String::NewFromUtf8(isolate, "int23singned"),dint23Value);
 obj->Set(String::NewFromUtf8(isolate, "valueBool"),valueBool);
 args.GetReturnValue().Set(obj);
}

/*void Init(Handle<Object> exports) {

      NODE_SET_METHOD(exports, "kemo", Method);
      NODE_SET_METHOD(exports, "lemo", Method);
}*/
void Boot(Handle<Object> exports) {

      NODE_SET_METHOD(exports, "kemo", Method); // kemo and lemo is alias name for javascript calling we can create  multiple calling method
      NODE_SET_METHOD(exports, "lemo", Method2);
}

NODE_MODULE(demo, Boot)  //  NODE_MODULE this first execution point=> NODE_MODULE(module_name, Initialize)
                       // Initialize is the method name.  module_name=> would be module name
