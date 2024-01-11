#include "Addresses.h"

#include <Windows.h>

#include "Offsets.h"

bool Addresses::Init()
{
	Addresses::ModuleBase = *(unsigned __int64*)(__readgsqword(0x60) + 0x10);
	if (!Addresses::ModuleBase) return false;

	Addresses::RequestExit = Offsets::RequestExit;
	if (!Addresses::RequestExit) return false;

	Addresses::UnsafeEnvironment = Offsets::UnsafeEnvironment;
	if (!Addresses::UnsafeEnvironment) return false;

	return true;
}
