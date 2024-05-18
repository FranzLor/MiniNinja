#pragma once
#include <raylib.h>

#include "BaseCharacter.h"
#include "Character.h"

class Enemy: public BaseCharacter {
private:
	Character* target;

public:
	Enemy(Vector2 pos, Texture2D texture);
	~Enemy() = default;

	virtual void Movement(float deltaTime) override;

	void setTarget(Character* character);
};

