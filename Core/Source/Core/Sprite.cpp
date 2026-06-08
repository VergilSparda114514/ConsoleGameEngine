#include "Sprite.h"

void Sprite::Start()
{
	Behaviour::Start();
	m_Scene = Singleton<Application>::Get().GetActiveScene();
	m_PreviousPosition = transform->Position;
}

void Sprite::Update()
{
	if (m_CalculateCollision) UpdateCollision();

	glm::ivec2 anchor = transform->Position + m_Offset;

	for (size_t y = 0; y < m_Data.size(); y++)
	{
		size_t width = m_Data[y].size();

		for (size_t x = 0; x < width; x++)
		{
			if (m_Data[y][x] == ' ') continue;

			glm::ivec2 position = anchor + glm::ivec2(x, y);

			m_Scene->SetData(position, ' ', Color::Black);
		}
	}
}

void Sprite::LateUpdate()
{
	if(m_CalculateCollision) CalculateCollision();

	glm::ivec2 anchor = transform->Position + m_Offset;

	size_t color = 0;

	for (size_t y = 0; y < m_Data.size(); y++)
	{
		for (size_t x = 0; x < m_Data[y].size(); x++)
		{
			if (m_Data[y][x] == ' ') continue;

			glm::ivec2 position = anchor + glm::ivec2(x, y);

			m_Scene->SetData(position, m_Data[y][x], m_Colors[color++]);
		}
	}

	m_PreviousPosition = transform->Position;
}

void Sprite::UpdateCollision()
{
	glm::ivec2 anchor = transform->Position + m_Offset;

	for (size_t y = 0; y < m_Data.size(); y++)
	{
		for (size_t x = 0; x < m_Data[y].size(); x++)
		{
			if (m_Data[y][x] == ' ') continue;

			glm::ivec2 position = anchor + glm::ivec2(x, y);
			m_Scene->SetCollision(position, gameObject->GetIndex());
		}
	}
}

void Sprite::CalculateCollision()
{
	glm::ivec2 anchor = transform->Position + m_Offset;

	for (size_t y = 0; y < m_Data.size(); y++)
	{
		for (size_t x = 0; x < m_Data[y].size(); x++)
		{
			if (m_Data[y][x] == ' ') continue;

			glm::ivec2 position = anchor + glm::ivec2(x, y);

			int collisionIndex = m_Scene->GetCollision(position);

			if (collisionIndex > -1 && collisionIndex != gameObject->GetIndex())
			{
				transform->Position = m_PreviousPosition;
			}
		}
	}
}

void Sprite::Init(const std::vector<std::string_view>& data)
{
	m_Data.reserve(data.size());

	for (const auto& i : data)
	{
		m_Data.emplace_back(i);
	}
}

void Sprite::Init(const std::vector<std::string_view>& data, const std::vector<WORD>& colours)
{
	m_Data.reserve(data.size());

	for (const auto& i : data)
	{
		m_Data.emplace_back(i);
	}

	m_Colors = colours;
}