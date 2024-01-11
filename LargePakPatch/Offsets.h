#pragma once

#include "Memcury.h"

namespace Offsets
{
	// Search RequestExit, last xref usually, f5, if the sub has postquitmessage in it, then you have the right one.
	unsigned __int64 RequestExit = 0x1E6CC40;

	// Search UnsafeEnvironment_Title, there should only be one xref, f5, you have it.
	unsigned __int64 UnsafeEnvironment = 0x163E3D0;
}