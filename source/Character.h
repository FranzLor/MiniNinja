#pragma once

#include <raylib.h>

#include "BaseCharacter.h"


class Character: public BaseCharacter {
private:


public:
	Character(int windowWidth, int windowHeight);
	~Character() = default;

	virtual void Movement(float deltaTime) override;

};

