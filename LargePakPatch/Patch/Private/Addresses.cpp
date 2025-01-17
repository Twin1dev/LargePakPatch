#include "../Public/Addresses.h"

#include <Windows.h>

#include "../Public/Finder.h"

#include <iostream>

bool Addresses::Init()
{
	Addresses::RequestExit = Finder::FindRequestExit();
	if (!Addresses::RequestExit) return false;

	Addresses::UnsafeEnvironment = Finder::FindUnsafeEnvironment();
	
	if (!Addresses::UnsafeEnvironment) return false;

	return true;
}
