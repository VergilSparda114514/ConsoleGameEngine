#pragma once

#include "Application.h"
#include "Behaviour.h"

class CharacterController : public Behaviour
{
public:
	CharacterController() = default;
	~CharacterController() = default;

	virtual void Start() override;
	virtual void Update() override;
	void SetSpeed(float speed);
private:
	std::shared_ptr<Scene> m_Scene;

	float m_Speed = 1;
};