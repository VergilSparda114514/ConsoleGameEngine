#pragma once

#include <random>
#include <chrono>

#include "Singleton.h"
#include "Utils.h"
#include "glm/glm.hpp"

class Random
{
public:
	Random();

	static int Int(int min, int max);
	static int Range(int minInclusive, int maxExclusive);
	static float Float(float min, float max);
	static float Value();
	static glm::vec2 Vec2(float min, float max);
	static glm::vec2 Vec2(glm::vec2 min, glm::vec2 max);
private:
	static thread_local std::mt19937 m_Rng;
};