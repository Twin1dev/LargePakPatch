#include <Windows.h>

#include "Patch/Public/Addresses.h"
#include "Patch/Public/Hooks.h"

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

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, MainThread, 0, 0, 0);

    return TRUE;
}

