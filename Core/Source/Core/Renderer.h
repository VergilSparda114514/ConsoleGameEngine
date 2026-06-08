#pragma once

#include <Windows.h>

#include <vector>
#include <string>

#include "Scene.h"

class Renderer
{
public:
	Renderer();
	~Renderer() = default;

	void Render(const Scene& data) const;

	const HANDLE& GetHandle() const { return m_ConsoleOutput; }
private:
	void SetData(const std::vector<std::string>& data);
public:
	static constexpr char BlockCharacter = (char)219; // ¨€
private:
	HANDLE m_ConsoleOutput;
};