#include "BaseCharacter.h"

#include <raymath.h>


BaseCharacter::BaseCharacter()
	: texture(LoadTexture("assets/ninja_sprite.png")),
	screenPosition({0.0f, 0.0f}),
	worldPosition({0.0f, 0.0f}),
	worldLastPosFrame({0.0f, 0.0f}),
	movementDirection({ 0.0f, 0.0f }),
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


void BaseCharacter::Movement(float deltaTime) {
	worldLastPosFrame = worldPosition;

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
	Rectangle characterSrc = {
		static_cast<float>((direction - 1) * frameWidth),
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