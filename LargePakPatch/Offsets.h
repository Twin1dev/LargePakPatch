#pragma once

#include "Memcury.h"

// REPLACE THE OFFSETS WITH THE VERSIONS PROVIDED! YOU CAN ALSO FIND YOUR OWN.

/*
	Version: 8.51
		RequestExit: 0x1CED030
		UnsafeEnvironment: 0x15144A0
*/

/*
	Version: 9.10
		RequestExit: 0x1E6CC40
		UnsafeEnvironment: 0x163E3D0
*/

namespace Offsets
{
	// Search RequestExit, last xref usually, f5, if the sub has postquitmessage in it, then you have the right one.
	unsigned __int64 RequestExit = 0x1E6CC40;

	// Search UnsafeEnvironment_Title, there should only be one xref, f5, you have it.
	unsigned __int64 UnsafeEnvironment = 0x163E3D0;
}