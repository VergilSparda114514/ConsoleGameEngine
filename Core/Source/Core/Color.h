#pragma once

#include <Windows.h>

struct Color
{
	static constexpr WORD Black = 0;
	static constexpr WORD Grey = FOREGROUND_INTENSITY;
	static constexpr WORD Red = FOREGROUND_RED;
	static constexpr WORD Yellow = FOREGROUND_RED | FOREGROUND_GREEN;
	static constexpr WORD Green = FOREGROUND_GREEN;
	static constexpr WORD Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE;
	static constexpr WORD Blue = FOREGROUND_BLUE;
	static constexpr WORD Purple = FOREGROUND_BLUE | FOREGROUND_RED;
	static constexpr WORD White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
};