#pragma once

using namespace Utility;

class Triangle : public GameObject
{
public:
	float speed = 1.0f;

	Triangle(Vector2f position = Vector2f(0.0f, 0.0f), float rotation = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f), Color color = Color(1));
	void update();
};

