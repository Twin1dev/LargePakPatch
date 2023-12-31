#pragma once

static void(*GetEngineVersion)();

namespace Addresses
{
	inline uintptr_t EngineVersion = 0;

	uintptr_t SigScan(const char* signature, bool bRelative = false, uint32_t offset = 0);
	void Init();
}


