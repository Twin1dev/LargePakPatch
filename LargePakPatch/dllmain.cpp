#pragma comment(lib,"minhook/minhook.lib")
#include "minhook/MinHook.h"

#include <iostream>

#include <Windows.h>
#include <vector>

#include "Memory.h"
#include "Hooks.h"

// Will Be Updated/Universal at a later date.

#define CONSOLE


DWORD WINAPI Main(LPVOID)
{
#ifdef CONSOLE
    AllocConsole();
    FILE* fptr;
    freopen_s(&fptr, "CONOUT$", "w+", stdout);

    std::cout << "Using LargePakPatch by Twin1dev.\n";
#endif
    MH_Initialize();

    Addresses::Init();

    static auto Base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

    CREATEHOOK(Base + 0x163E3D0, UnsafeEnvironmentHook, nullptr);
    CREATEHOOK(Base + 0x1E6CC40, RequestExit, nullptr);
    
    return 0;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, Main, 0, 0, 0);
    }
    return TRUE;
}

