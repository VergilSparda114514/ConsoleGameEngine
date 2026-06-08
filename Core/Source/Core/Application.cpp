#include "Application.h"

Application::Application(std::string_view applicationName)
{
	std::string command = "title ";
	command += applicationName;
	system(command.c_str());
}

void Application::Run()
{
	while (m_IsRunning)
	{
		if (m_ActiveScene)
		{
			m_ActiveScene->Update();
			m_ActiveScene->LateUpdate();

			m_Renderer.Render(*m_ActiveScene);
		}
	}
}

void Application::Quit()
{
	m_IsRunning = false;
}

void Application::AddScene(std::shared_ptr<Scene> scene)
{
	m_Scenes.emplace_back(scene);
}

void Application::SetActiveScene(int index)
{
	m_ActiveScene = m_Scenes[index];
	m_ActiveScene->Start();
}