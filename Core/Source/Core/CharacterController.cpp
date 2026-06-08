#include "CharacterController.h"

void CharacterController::Start()
{
	InitTime();
	m_Scene = Singleton<Application>::Get().GetActiveScene();
}

void CharacterController::Update()
{
	glm::vec2 moveDirection = Input::GetVec2('W', 'S', 'A', 'D');
	transform->Translate(moveDirection * time.DeltaTime() * m_Speed);
}

void CharacterController::SetSpeed(float speed)
{
	m_Speed = speed;
}