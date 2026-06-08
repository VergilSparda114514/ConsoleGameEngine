#pragma once

#include <Windows.h>

#include <vector>
#include <array>
#include <memory>
#include <string>
#include <execution>

#include "Color.h"
#include "GameObject.h"

class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	uint32_t GetWidth() const { return m_Width; }
	uint32_t GetHeight() const { return m_Height; }

	const std::array<std::string, 30>& GetData() const { return m_Data; }
	const std::array<WORD, 3600>& GetColours() const { return m_Colours; }

	int GetCollision(glm::vec2 position) const { return m_CollisionMap[position.x + position.y * m_Width]; }
	void SetCollision(glm::vec2 position, int objectIndex) { m_CollisionMap[position.x + position.y * m_Width] = objectIndex; }

	void Start();
	void Update();
	void LateUpdate();

	void SetData(glm::ivec2 position, char character, WORD color);

	void AddGameObject(std::shared_ptr<GameObject> gameObject);
protected:
	void InitColors();
	void ResetCollisionMap();
protected:
	uint32_t m_Width = 0;
	uint32_t m_Height = 0;

	std::array<std::string, 30> m_Data;
	std::array<WORD, 3600> m_Colours;

	std::vector<std::shared_ptr<GameObject>> m_GameObjects;

	std::array<int, 3600> m_CollisionMap;
};