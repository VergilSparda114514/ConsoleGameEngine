#include "Input.h"

KeyState Input::GetKeyState(int keyCode)
{
	if (GetAsyncKeyState(keyCode) & 0x8000)
	{
		switch (m_KeyStates[keyCode])
		{
		case KeyState::Down:
			m_KeyStates[keyCode] = KeyState::Pressed;
			break;
		case KeyState::Pressed:
			break;
		default:
			m_KeyStates[keyCode] = KeyState::Down;
			break;
		}
	}

	else
	{
		switch (m_KeyStates[keyCode])
		{
		case KeyState::Pressed:
			m_KeyStates[keyCode] = KeyState::Up;
			break;
		default:
			m_KeyStates[keyCode] = KeyState::Idle;
			break;
		}
	}

	return m_KeyStates[keyCode];
}

bool Input::GetKey(int keyCode)
{
	return GetKeyState(keyCode) != KeyState::Idle;
}

bool Input::GetKeyDown(int keyCode)
{
	return GetKeyState(keyCode) == KeyState::Down;
}

bool Input::GetKeyPressed(int keyCode)
{
	return GetKeyState(keyCode) == KeyState::Pressed;
}

bool Input::GetKeyUp(int keyCode)
{
	return GetKeyState(keyCode) == KeyState::Up;
}

float Input::GetAxis(int positive, int negative)
{
	return GetKey(positive) - GetKey(negative);
}

glm::vec2 Input::GetVec2(int up, int down, int left, int right)
{
	glm::vec2 vec{ GetAxis(right, left), GetAxis(down, up) };
	return glm::normalize(vec);
}