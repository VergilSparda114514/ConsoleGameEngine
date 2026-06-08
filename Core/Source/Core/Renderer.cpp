#include "Renderer.h"

Renderer::Renderer()
{
	// Enables the extended ASCII table - Needed for the block character (¨€ - (char)219) to be properly displayed
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	m_ConsoleOutput = CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO cci = { 1, FALSE };
	SetConsoleCursorInfo(m_ConsoleOutput, &cci);
}

void Renderer::Render(const Scene& scene) const
{
	COORD coord = { 0, 0 };
	DWORD bytes = 0;

	for (uint32_t y = 0; y < scene.GetHeight(); y++)
	{
		coord.Y = y;

		WriteConsoleOutputCharacterA(m_ConsoleOutput, scene.GetData()[y].data(), scene.GetWidth(), coord, &bytes);
		WriteConsoleOutputAttribute(m_ConsoleOutput, scene.GetColours().data() + y * scene.GetWidth(), scene.GetWidth(), coord, &bytes);
	}

	SetConsoleActiveScreenBuffer(m_ConsoleOutput);
}