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

bool Hooks::Create()
{
	if (MH_Initialize() != MH_OK) return false;;

	if (MH_CreateHook((void*)(Addresses::RequestExit), Hooks::RequestExitHk, nullptr) != MH_OK) return false;
	if (MH_CreateHook((void*)(Addresses::UnsafeEnvironment), Hooks::UnsafeEnvironmentHk, nullptr) != MH_OK) return false;

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) return false;

	return true;
}
