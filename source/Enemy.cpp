#include "Enemy.h"

#include <raymath.h>


Enemy::Enemy(Vector2 pos, Texture2D texture)
	: BaseCharacter(),
	target() {

	texture = LoadTexture("assets/enemy.png");

	worldPosition = pos;
	this->texture = texture;

	width = texture.width / maxFrames;
	height = texture.height;

	speed = 3.5f;
}



void Enemy::Movement(float deltaTime) {
	//store current pos to compare later
	worldLastPosFrame = worldPosition;

	//follows player as target
	Vector2 toTarget = Vector2Subtract(target->GetScreenPos(), screenPosition);
	toTarget = Vector2Normalize(toTarget);
	toTarget = Vector2Scale(toTarget, speed);
	worldPosition = Vector2Add(worldPosition, toTarget);

	//update screen pos relative to target's pos
	screenPosition = Vector2Subtract(worldPosition, target->GetWorldPos());

	//directional movement
	if (fabs(toTarget.x) > fabs(toTarget.y)) {
		//horizontal movement
		if (toTarget.x > 0) {
			direction = LEFT;
		}
		//invert direction based on sprite sheet
		else {
			direction = UP;
		}
	}
	else {
		//vertical movement
		if (toTarget.y > 0) {
			direction = RIGHT;
		}
		//invert direction based on sprite sheet
		else {
			direction = DOWN;
		}
	}

	isMoving = Vector2Length(toTarget) > 0.0f;

	//animations
	if (isMoving) {
		runningTime += deltaTime;
		if (runningTime >= updateTime) {
			frame = (frame + 1) % maxFrames;
			runningTime = 0.0f;
		}
	} else {
		frame = 0;
	}

	Rectangle characterSrc = {
		static_cast<float>(frameWidth * static_cast<int>(direction)),
		static_cast<float>(frame * frameHeight),
		static_cast<float>(frameWidth),
		static_cast<float>(frameHeight)
	};
	Rectangle characterDst = {
		screenPosition.x,
		screenPosition.y,
		frameWidth * scale,
		frameHeight * scale
	};
	Vector2 characterOrg = { 0.0f, 0.0f };

	DrawTexturePro(texture, characterSrc, characterDst, characterOrg, 0.0f, WHITE);
}

void Enemy::setTarget(Character* character) {
	target = character;
}