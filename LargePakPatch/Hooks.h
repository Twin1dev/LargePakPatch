#pragma once

namespace Hooks
{
    void __fastcall RequestExitHk(unsigned __int8 a1);
    __int64 __fastcall UnsafeEnvironmentHk(__int64* a1, char a2, __int64 a3, char a4);

    void Create();
}