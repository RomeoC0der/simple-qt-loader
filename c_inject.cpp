#include "c_inject.h"
#define check(x)if(!x){qInfo(std::to_string(GetLastError()).c_str());return;}
typedef int(_cdecl* inject_dll_function)(const char* path);
c_inject::c_inject()
{
    this->inject_dll = LoadLibraryA(PATH_TO_INJECT_DLL);
    check(this->inject_dll);
    this->inject_function_address = (void*)GetProcAddress(this->inject_dll, "inject");
    check(this->inject_function_address);
}

int c_inject::inject_to_csgo()
{
    int result_code = 0;
    if(!this->inject_dll || !this->inject_function_address || this->injected)return -1;
    if( (result_code = reinterpret_cast<inject_dll_function>(this->inject_function_address)("D:\\c++ workspace\\GachiParty\\Debug\\GachiParty.dll")))
    {
        this->injected = true;
    }
    return result_code;
}
