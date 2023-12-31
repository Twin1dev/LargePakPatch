#include "Addresses.h"

#include <Windows.h>

#include "Offsets.h"

void Addresses::Init()
{
	Addresses::ModuleBase = *(unsigned __int64*)(__readgsqword(0x60) + 0x10);

	Addresses::RequestExit = ModuleBase + Offsets::RequestExit;
	Addresses::UnsafeEnvironment = ModuleBase + Offsets::UnsafeEnvironment;
}
