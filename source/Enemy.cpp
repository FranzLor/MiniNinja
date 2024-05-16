#include "Enemy.h"

#include <raymath.h>


Enemy::Enemy(Vector2 pos, Texture2D texture) {

	texture = LoadTexture("assets/enemy.png");

	worldPosition = pos;
	this->texture = texture;


	width = texture.width / maxFrames;
	height = texture.height;

}



void Enemy::Movement(float deltaTime) {

	BaseCharacter::Movement(deltaTime);
}

