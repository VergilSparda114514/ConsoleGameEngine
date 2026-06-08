#include "Time.h"

Timer::Timer()
{
	Reset();
}

void Timer::Reset()
{
	m_Start = std::chrono::high_resolution_clock::now();
	m_Time = m_PreviousTime = m_DeltaTime = 0;
}

void Timer::Update()
{
	m_Now = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_Now - m_Start);

	m_Time = duration.count() / std::chrono::nanoseconds::period::den;
	m_DeltaTime = m_Time - m_PreviousTime;
	m_PreviousTime = m_Time;
}