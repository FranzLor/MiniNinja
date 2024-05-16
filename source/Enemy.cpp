#include "Enemy.h"

#include <raymath.h>


Enemy::Enemy(Vector2 pos, Texture2D texture)
	: texture(texture),
	screenPosition({ 0.0f, 0.0f }),
	worldPosition({ 0.0f, 0.0f }),
	worldLastPosFrame({ 0.0f, 0.0f }),
	speed(5.0f),
	scale(4.0f),
	runningTime(0.0f),
	frame(0),
	maxFrames(4),
	updateTime(1.0f / 10.f),
	width(0.0f),
	height(0.0f),
	enemyDirection(ENEMY_DOWN),
	isMoving(false) {

	width = texture.width / maxFrames;
	height = texture.height;
}


Enemy::~Enemy() {
	UnloadTexture(texture);
}




void Enemy::HandleInput(float deltaTime) {
	worldLastPosFrame = worldPosition;
	Vector2 movementDirection = { 0.0f, 0.0f };
	isMoving = false;


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
		static_cast<float>((enemyDirection - 1) * frameWidth),
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



void Enemy::StopMovement() {
	worldPosition = worldLastPosFrame;
}



Rectangle Enemy::GetCollisionRect() {
	return Rectangle {
		screenPosition.x,
		screenPosition.y,
		frameWidth * scale,
		frameHeight * scale
	};
}
