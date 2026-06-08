#include "Random.h"

Random::Random()
{
	m_Rng.seed(std::random_device{}());
}

int Random::Int(int min, int max)
{
	std::uniform_int_distribution dist(min, max);
	return dist(m_Rng);
}

int Random::Range(int minInclusive, int maxExclusive)
{
	return Int(minInclusive, maxExclusive - 1);
}

float Random::Float(float min, float max)
{
	std::uniform_real_distribution dist(min, max);
	return dist(m_Rng);
}

float Random::Value()
{
	return Float(0, 1);
}

glm::vec2 Random::Vec2(float min, float max)
{
	float x = Float(min, max);
	float y = Float(min, max);
	return { x, y };
}

glm::vec2 Random::Vec2(glm::vec2 min, glm::vec2 max)
{
	float x = Float(min.x, max.x);
	float y = Float(min.y, max.y);
	return { x, y };
}