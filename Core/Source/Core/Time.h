#pragma once

#include <chrono>

class Timer
{
public:
	Timer();
	~Timer() = default;

	void Reset();
	void Update();

	const float Time() { Update(); return m_Time; }
	const float DeltaTime() { Update(); return m_DeltaTime; }
private:
	float m_Time = 0;
	float m_PreviousTime = 0;
	float m_DeltaTime = 0;

	std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_Now;
};