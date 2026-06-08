#include "Scene.h"

void Scene::InitColors()
{
	for (int i = 0; i < 3600; i++)
	{
		m_Colours[i] = Color::White;
		m_CollisionMap[i] = -1;
	}
}

void Scene::Start()
{
	for (const auto& gameObject : m_GameObjects)
	{
		gameObject->Start();
	}
}

void Scene::Update()
{
	for (const auto& gameObject : m_GameObjects)
	{
		gameObject->Update();
	}
}

void Scene::LateUpdate()
{
	for (const auto& gameObject : m_GameObjects)
	{
		gameObject->LateUpdate();
	}

	ResetCollisionMap();
}

void Scene::SetData(glm::ivec2 position, char character, WORD color)
{
	m_Data[position.y][position.x] = character;
	m_Colours[position.x + position.y * m_Width] = color;
}

void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject)
{
	gameObject->m_GameObject = gameObject;
	m_GameObjects.emplace_back(gameObject);
	gameObject->SetIndex(m_GameObjects.size());
}

void Scene::ResetCollisionMap()
{
	for (size_t y = 0; y < m_Height; y++)
	{
		for (size_t x = 0; x < m_Width; x++)
		{
			m_CollisionMap[x + y * m_Width] = (m_Data[y][x] != ' ') - 1;
		}
	}
}