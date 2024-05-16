#include "Enemy.h"

#include <raymath.h>


Enemy::Enemy(Vector2 pos, Texture2D texture) {

	texture = LoadTexture("assets/enemy.png");

	worldPosition = pos;
	this->texture = texture;


	width = texture.width / maxFrames;
	height = texture.height;

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
		static_cast<float>((direction - 1) * frameWidth),
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

