#pragma once

#include <memory>

#include "Transform.h"
#include "Input.h"
#include "Math.h"
#include "Random.h"
#include "Time.h"
#include "Debug.h"

class GameObject;

class Behaviour
{
public:
	Behaviour() = default;
	virtual ~Behaviour() = default;

	virtual void Start() {};
	virtual void Update() {};
	virtual void LateUpdate() {};
public:
	std::shared_ptr<GameObject> gameObject;
	std::shared_ptr<Transform> transform;
protected:
	void InitTime();
protected:
	Timer time;
};