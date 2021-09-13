#include <Windows.h>
#include <memory>
#include <QDebug>
/////////////////////////////////////////////////////////////////////////////////////////////

#define PATH_TO_INJECT_DLL  "D:\\c++ workspace\\simple_injector\\Release\\simple_injector.dll"

/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef C_INJECT_H
#define C_INJECT_H
class c_inject
{
public:
    c_inject();
   int inject_to_csgo();
private:
    HMODULE inject_dll{NULL};//dll which will inject the cheat into the game
    void* inject_function_address{nullptr};//will be non-nullptr after getprocadr();
    bool injected{false};
};
inline std::unique_ptr<c_inject>_inject_(new c_inject());
#endif // C_INJECT_H
