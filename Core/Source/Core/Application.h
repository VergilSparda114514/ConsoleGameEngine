#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Renderer.h"

class Application
{
public:
	Application() = default;
	Application(std::string_view applicationName);
	~Application() = default;

	void Run();
	void Quit();

	void AddScene(std::shared_ptr<Scene> scene);
	void SetActiveScene(int index);

	std::shared_ptr<Scene> GetActiveScene() { return m_ActiveScene; }
private:
	bool m_IsRunning = true;

	Renderer m_Renderer;

	std::vector<std::shared_ptr<Scene>> m_Scenes;
	std::shared_ptr<Scene> m_ActiveScene;
};