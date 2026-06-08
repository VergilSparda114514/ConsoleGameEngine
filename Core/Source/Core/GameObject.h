#pragma once

#include <vector>
#include <memory>
#include <typeinfo>

#include "Transform.h"
#include "Behaviour.h"

class Behaviour;

class GameObject
{
public:
	GameObject() : m_Transform(std::make_shared<Transform>()) {}
	GameObject(glm::vec2 position) : m_Transform(std::make_shared<Transform>(position)) {}
	~GameObject() = default;

	void Start();
	void Update();
	void LateUpdate();

	void AddBehaviour(std::shared_ptr<Behaviour> component);
	template<class T>
	requires std::is_base_of_v<Behaviour, T>
	std::shared_ptr<T> GetBehaviour();

	void SetIndex(int index) { m_Index = index; }
	int GetIndex() const { return m_Index; }
public:
	std::shared_ptr<GameObject> m_GameObject;
	std::shared_ptr<Transform> m_Transform;
private:
	int m_Index = -1;

	std::vector<std::shared_ptr<Behaviour>> m_Behaviours;
};