#include "Character.h"

#include <raylib.h>
#include <raymath.h>


Character::Character(int windowWidth, int windowHeight)
	: screenPosition({0.0f, 0.0f}),
	worldPosition({0.0f, 0.0f}),
	worldLastPosFrame({0.0f, 0.0f}),
	speed(5.0f),
	scale(4.0f),
	runningTime(0.0f),
	frame(0),
	maxFrames(4),
	updateTime(1.0f / 10.f),
	playerDirection(DOWN),
	isMoving(false) {


	screenPosition = {
		(windowWidth - frameWidth * scale) / 2,
		(windowHeight - frameHeight * scale) / 2
	};
}


Character::~Character() {
	UnloadTexture(texture);
}


void Character::HandleInput(float deltaTime) {
	Vector2 movementDirection = { 0.0f, 0.0f };
	isMoving = false;

	//player movement
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
		movementDirection.y -= 1.0f;
		playerDirection = UP;
		isMoving = true;

	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
		movementDirection.x += 1.0f;
		playerDirection = RIGHT;
		isMoving = true;

	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
		movementDirection.y += 1.0f;
		playerDirection = DOWN;
		isMoving = true;

	}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
		movementDirection.x -= 1.0f;
		playerDirection = LEFT;
		isMoving = true;

	}

	//player-map movement
	if (Vector2Length(movementDirection) != 0.0f) {
		worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(movementDirection), speed));
	}
	//direction movement animation
	if (isMoving) {
		runningTime += deltaTime;
		if (runningTime >= updateTime) {
			frame = (frame + 1) % maxFrames;
			runningTime = 0.0f;
		}
	}
	//idle (no animation)
	else {
		frame = 0;
	}

	//texture rendering
	Rectangle playerSrc = {
		static_cast<float>((playerDirection - 1) * frameWidth),
		static_cast<float>(frame * frameHeight),
		static_cast<float>(frameWidth),
		static_cast<float>(frameHeight)
	};
	Rectangle playerDst = {
		screenPosition.x,
		screenPosition.y,
		frameWidth * scale,
		frameHeight * scale
	};
	Vector2 playerOrg = { 0.0f, 0.0f };

	DrawTexturePro(texture, playerSrc, playerDst, playerOrg, 0.0f, WHITE);
}



void Character::StopMovement() {
	
}



