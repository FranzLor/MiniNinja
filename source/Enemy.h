#pragma once
#include <raylib.h>

#include "BaseCharacter.h"


class Enemy: public BaseCharacter {
private:

public:
	Enemy(Vector2 pos, Texture2D texture);
	~Enemy() = default;

	void HandleInput(float deltaTime);

};

