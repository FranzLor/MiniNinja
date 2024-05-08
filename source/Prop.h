#pragma once

#include <raylib.h>

class Prop {
private:
	Texture2D texture;
	Vector2 worldPosition;

	float scale;

public:
	Prop(Vector2 propPos, Texture2D propTex);
	~Prop();

	void Render(Vector2 position);
};
