#pragma once

#include "glm/glm.hpp"
#include "Math.h"

class Transform
{
public:
	Transform() = default;
	Transform(glm::vec2 position) : Position(position) {}
	~Transform() = default;

	void Translate(glm::vec2 translation);
	void Rotate(float rotation);

	const glm::vec2 GetPointAfterRotation(glm::vec2 vec) const;
public:
	glm::vec2 Position{ 0, 0 };
	float Rotation = 0;
};