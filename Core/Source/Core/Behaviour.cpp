#include "Behaviour.h"

void Behaviour::InitTime()
{
	time = Singleton<Timer>::Get();
}