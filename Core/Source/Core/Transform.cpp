#include "Transform.h"

void Transform::Translate(glm::vec2 translation)
{
	Position += translation;
}

void Transform::Rotate(float rotation)
{
	Rotation += rotation;
}

const glm::vec2 Transform::GetPointAfterRotation(glm::vec2 vec) const
{
	glm::vec2 result(0.0f);
	
	float sin = glm::sin(Rotation);
	float cos = glm::cos(Rotation);

	result.x = vec.x * cos - vec.y * sin;
	result.y = vec.x * sin + vec.y * cos;

	return result;
}