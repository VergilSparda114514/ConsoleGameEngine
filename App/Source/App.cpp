#include "Core/ConsoleGameEngine.h"
#include "Core/Sprite.h"
#include "Core/CharacterController.h"

int main()
{
	Application& application = Singleton<Application>::Get();
	application.Run();
}