#include "GameObject.h"

void GameObject::Start()
{
	for (auto behaviour : m_Behaviours)
	{
		behaviour->Start();
	}
}

void GameObject::Update()
{
	for (auto behaviour : m_Behaviours)
	{
		behaviour->Update();
	}
}

void GameObject::LateUpdate()
{
	for (auto behaviour : m_Behaviours)
	{
		behaviour->LateUpdate();
	}
}

void GameObject::AddBehaviour(std::shared_ptr<Behaviour> component)
{
	component->gameObject = m_GameObject;
	component->transform = m_Transform;
	m_Behaviours.emplace_back(component);
}

template<class T>
requires std::is_base_of_v<Behaviour, T>
std::shared_ptr<T> GameObject::GetBehaviour()
{
	std::type_info type = typeid(T);
	for (size_t i = 0; i < m_Behaviours.size(); i++)
	{
		if (typeid(*m_Behaviours[i]) == type)
		{
			return m_Behaviours[i];
		}
	}

	return nullptr;
}