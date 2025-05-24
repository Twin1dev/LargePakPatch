#include "../Public/Finder.h"

#include "../../Vendor/Memcury.h"

#include <iostream>

uint64_t Finder::FindRequestExit()
{
	auto StringRef = Memcury::Scanner::FindStringRef(L"Memory pools allocations failed, exiting...\n");

	if (StringRef.IsValid())
		return StringRef.ScanFor({ Memcury::ASM::CALL }, true, 1).RelativeOffset(1).Get();
	
	return 0;
}

uint64_t Finder::FindUnsafeEnvironment()
{
	auto StringRef = Memcury::Scanner::FindStringRef(L"UnsafeEnvironment_Title");

	if (StringRef.IsValid())
	{
		for (int i = 0; i < 2048; i++)
		{
			uint8_t* ptr = (uint8_t*)(StringRef.Get() - i);

			// Tested on 9.10 (mov r11, rsp)
			if (ptr[0] == 0x4C && ptr[1] == 0x8B && ptr[2] == 0xDC)
				return StringRef.Get() - i;

			// Older builds? tested on 7.10 (push rbp)
			if (*(uint16_t*)(StringRef.Get() - i) == 0x5540)
				return StringRef.Get() - i;
		}
	}

	return 0;
}

uint64_t Finder::FindUnsafeEnvironmentAlt() {
	return Memcury::Scanner::FindPattern("E8 ? ? ? ? 48 8B 4D ? 48 85 C9 74 ? E8 ? ? ? ? 48 8B 4D ? 48 85 C9 74 ? E8 ? ? ? ? 4C 8B 7C 24 ? 4C 8B B4 24").RelativeOffset(1).Get();
}