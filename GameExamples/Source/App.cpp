#include "Core/Core.h"

int main()
{
	_declspec(dllimport) void Core::PrintHelloWorld();
	Core::PrintHelloWorld();
}