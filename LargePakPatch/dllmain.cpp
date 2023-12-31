#include <Windows.h>

#include "Addresses.h"
#include "Hooks.h"

DWORD WINAPI Main(LPVOID)
{
    Addresses::Init();
    Hooks::Create();
    
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, Main, 0, 0, 0);
        break;
    }

    return TRUE;
}

