#pragma once

#define CREATEHOOK(Address, Hook, Og) \
MH_CreateHook((void*)(Address), Hook, (void**)(Og)); \
MH_EnableHook((void*)(Address));

__int64 __fastcall UnsafeEnvironmentHook(__int64* a1, char a2, __int64 a3, char a4)
{
    return 0;
}

void __fastcall RequestExit(unsigned __int8 a1)
{

}
