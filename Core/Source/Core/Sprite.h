#pragma once

#include "Application.h"
#include "Behaviour.h"
#include "Color.h"

class Sprite : public Behaviour
{
public:
	Sprite() = default;
	~Sprite() = default;

	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;

	void UpdateCollision();
	void CalculateCollision();

	void Init(const std::vector<std::string_view>& data);
	void Init(const std::vector<std::string_view>& data, const std::vector<WORD>& colours);

	void SetOffset(glm::vec2 offset) { m_Offset = offset; }
	void SetCollisionMode(bool collisionMode) { m_CalculateCollision = collisionMode; }

	void SetData(const std::vector<std::string>& data) { m_Data = data; }
	void SetColor(size_t index, WORD color) { m_Colors[index] = color; }
private:
	bool m_CalculateCollision = false;

	std::shared_ptr<Scene> m_Scene = nullptr;

	glm::vec2 m_Offset{ 0, 0 };
	glm::vec2 m_PreviousPosition{ 0, 0 };

	std::vector<std::string> m_Data;
	std::vector<WORD> m_Colors;
};