#pragma once

#include <string>

namespace Debug
{
	template<typename... Args>
	static void Log(const char format[], Args... args)
	{
		printf(format, args...);
	}
}