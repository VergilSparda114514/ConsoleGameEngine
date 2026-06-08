#pragma once

#include "Windows.h"

#include <map>

#include "Singleton.h"
#include "glm/glm.hpp"

enum class KeyState
{
	Idle,
	Down,
	Pressed,
	Up,
};

class Input
{
public:
	static KeyState GetKeyState(int keyCode);
	static bool GetKey(int keyCode);
	static bool GetKeyDown(int keyCode);
	static bool GetKeyPressed(int keyCode);
	static bool GetKeyUp(int keyCode);
	static float GetAxis(int positive, int negative);
	static glm::vec2 GetVec2(int up, int down, int left, int right);
private:
	static std::map<int, KeyState> m_KeyStates;
};