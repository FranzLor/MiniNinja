#include "BaseCharacter.h"


BaseCharacter::BaseCharacter()
	: texture(LoadTexture("assets/ninja_sprite.png")),
	screenPosition({0.0f, 0.0f}),
	worldPosition({0.0f, 0.0f}),
	worldLastPosFrame({0.0f, 0.0f}),
	speed(5.0f),
	scale(4.0f),
	runningTime(0.0f),
	frame(0),
	maxFrames(4),
	updateTime(1.0f / 10.f),
	width(0.0f),
	height(0.0f),
	direction(DOWN),
	isMoving(false) {

}



void BaseCharacter::StopMovement() {
	worldPosition = worldLastPosFrame;
}



Rectangle BaseCharacter::GetCollisionRect() {
	return Rectangle{
		screenPosition.x,
		screenPosition.y,
		frameWidth * scale,
		frameHeight * scale
	};
}
