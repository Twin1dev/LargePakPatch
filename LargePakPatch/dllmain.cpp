#include "Includes.h"
#include <iostream>

// Will Be Updated/Universal at a later date.

#define CREATEHOOK(Address, Hook, Og) \
MH_CreateHook((void*)(Address), Hook, (void**)(Og)); \
MH_EnableHook((void*)(Address));

static __forceinline uintptr_t BaseAddress()
{
    return reinterpret_cast<uintptr_t>(GetModuleHandle(0));
}

__int64 (*sub_7FF6025DE3D0OG)(__int64* a1, unsigned __int8 a2, __int64 a3, char a4);

__int64 __fastcall sub_7FF6F91707B0(__int64* a1, char a2, __int64 a3, char a4)
{

    return 0; 
}

void __fastcall RequestExit(char a1)
{
  
}

DWORD WINAPI Main(LPVOID)
{
    MH_Initialize();

    CREATEHOOK(BaseAddress() + 0x163E3D0, sub_7FF6F91707B0, nullptr);
    CREATEHOOK(BaseAddress() + 0x1E6CC40, RequestExit, nullptr);
    
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

