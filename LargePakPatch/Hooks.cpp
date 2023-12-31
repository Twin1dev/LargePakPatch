#include "Hooks.h"

#include "minhook/MinHook.h"
#include "Addresses.h"

void __fastcall Hooks::RequestExitHk(unsigned __int8 a1)
{
}

__int64 __fastcall Hooks::UnsafeEnvironmentHk(__int64* a1, char a2, __int64 a3, char a4)
{
	return 0;
}

void Hooks::Create()
{
	MH_Initialize();

	MH_CreateHook((void*)(Addresses::RequestExit), Hooks::RequestExitHk, nullptr);
	MH_CreateHook((void*)(Addresses::UnsafeEnvironment), Hooks::UnsafeEnvironmentHk, nullptr);

	MH_EnableHook(MH_ALL_HOOKS);
}
