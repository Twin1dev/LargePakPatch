#include <Windows.h>

#include "Addresses.h"
#include "Hooks.h"

DWORD WINAPI MainThread(LPVOID)
{
    if (!Addresses::Init())
    {
        MessageBoxA(0, "Addresses::Init()", "LargePakPatch", MB_OK | MB_ICONERROR);
        exit(1);
    }

    if (!Hooks::Create())
    {
        MessageBoxA(0, "Hooks::Create()", "LargePakPatch", MB_OK | MB_ICONERROR);
        exit(1);
    }
    
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, MainThread, 0, 0, 0);
        break;
    }

    return TRUE;
}

