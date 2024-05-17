#include "Enemy.h"

#include <raymath.h>


Enemy::Enemy(Vector2 pos, Texture2D texture) {

	texture = LoadTexture("assets/enemy.png");

	worldPosition = pos;
	this->texture = texture;

	width = texture.width / maxFrames;
	height = texture.height;

	speed = 3.5f;

}



void Enemy::Movement(float deltaTime) {
	//follows player as target
	Vector2 toTarget = Vector2Subtract(target->GetScreenPos(), screenPosition);
	toTarget = Vector2Normalize(toTarget);
	toTarget = Vector2Scale(toTarget, speed);
	worldPosition = Vector2Add(worldPosition, toTarget);

	screenPosition = Vector2Subtract(worldPosition, target->GetWorldPos());
	BaseCharacter::Movement(deltaTime);
}

void Enemy::setTarget(Character* character) {
	target = character;
}