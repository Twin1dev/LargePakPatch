#pragma once

#include "Memcury.h"

namespace Offsets
{
	// 4.23 Sigs, you would have to find your own, again. im making it universal.

	// Search RequestExit, last xref usually, f5, if the sub has postquitmessage in it, then you have the right one.
	unsigned __int64 RequestExit = Memcury::Scanner::FindPattern("E8 ? ? ? ? F6 46 38 0F").Get();

	// Search UnsafeEnvironment_Title, there should only be one xref, f5, you have it.
	unsigned __int64 UnsafeEnvironment = Memcury::Scanner::FindPattern("0F 84 ? ? ? ? 4C 8D 0D ? ? ? ? 48 89 BC 24 ? ? ? ?").Get();
}