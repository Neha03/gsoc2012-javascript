#include <JavaScriptCore/JavaScript.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

#include "examplejsc.h"
extern int    gcd(int x, int y);
extern double Foo;


JSValueRef jsc_gcd(JSContextRef context, JSObjectRef function, JSObjectRef globalobj, size_t argc, const JSValueRef argv[], JSValueRef* exception)
{
  cout<<"jsc_gcd function called"<<endl;
  int arg1 = (int)JSValueToNumber(context, argv[0], NULL); 
  int arg2 = (int)JSValueToNumber(context, argv[1], NULL); 
  int result = (int)gcd(arg1,arg2);
  JSValueRef jscresult = JSValueMakeNumber(context, result); 
  return jscresult;
}

bool jsc_Foo_set(JSContextRef context, JSObjectRef globalobj, JSStringRef propertyName, JSValueRef value, 
  JSValueRef* exception)
{
  cout<<"jsc_Foo_set function called"<<endl;
  JSValueRef jscresult;
  double arg1 = (double)JSValueToNumber(context, value, NULL); 
  Foo = arg1;
  jscresult = JSValueMakeUndefined(context); 
  return jscresult;
}

JSValueRef jsc_Foo_get(JSContextRef context, JSObjectRef globalobj, JSStringRef propertyName, JSValueRef* exception)
{
  cout<<"jsc_Foo_get function called"<<endl;
  JSValueRef jscresult;
  double result = (double)Foo;
  jscresult = JSValueMakeNumber(context, result); 
  return jscresult;
}

JSStaticValue globalvars_staticValues[] = {
    {"Foo",jsc_Foo_get,jsc_Foo_set, kJSPropertyAttributeNone },
    { 0, 0, 0, 0 }
};

JSClassRef globalvars_createJSClass(JSContextRef context)
{
  	cout<<"globalvars_createJSClass called"<<endl;
	static JSClassRef jsClass = NULL;
	if (!jsClass)
	{
		JSClassDefinition definition	= kJSClassDefinitionEmpty;
		definition.staticValues			= globalvars_staticValues;
		jsClass							= JSClassCreate(&definition);
	}
	return jsClass;
}

bool globalvars_initClass(JSGlobalContextRef& context, JSObjectRef& parentObject, const char* globalvarsclassname)
{
    cout<<"globalvars_initClass called"<<endl;
    JSStringRef jsstring = JSStringCreateWithUTF8CString(globalvarsclassname);
    static JSObjectRef globalvarsclassObject = JSObjectMake(context, globalvars_createJSClass(context), NULL);
    JSObjectSetProperty(
		context,
	    parentObject,
	    jsstring,
	    globalvarsclassObject,
	    kJSPropertyAttributeNone,
	    NULL);
   JSStringRelease(jsstring);
   return true;
} 



