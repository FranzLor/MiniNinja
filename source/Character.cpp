#include "Character.h"

#include <raylib.h>
#include <raymath.h>


Character::Character(int windowWidth, int windowHeight) {

	width = texture.width / maxFrames;
	height = texture.height;

	screenPosition = {
		(windowWidth - frameWidth * scale) / 2,
		(windowHeight - frameHeight * scale) / 2
	};
}


void Character::Movement(float deltaTime) {
	//update position and animation
	BaseCharacter::Movement(deltaTime);
	if (!GetAlive()) {
		return;
	}

	movementDirection = { 0.0f, 0.0f };
	isMoving = false;

	//player movement
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
		movementDirection.y -= 1.0f;
		direction = UP;
		isMoving = true;

	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
		movementDirection.x += 1.0f;
		direction = RIGHT;
		isMoving = true;

	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
		movementDirection.y += 1.0f;
		direction = DOWN;
		isMoving = true;

	}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
		movementDirection.x -= 1.0f;
		direction = LEFT;
		isMoving = true;

	}

	//handle attacking
	if (IsKeyPressed(KEY_SPACE)) {
		Attack();
	}


}
