
JSValueRef jsc_gcd(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argc, const JSValueRef argv[], JSValueRef* exception);

bool jsc_Foo_set(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef value, 
JSValueRef* exception);

JSValueRef jsc_Foo_get(JSContextRef context, JSObjectRef thisObject, JSStringRef propertyName, JSValueRef* exception);

bool globalvars_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* globalvarsclassname);

