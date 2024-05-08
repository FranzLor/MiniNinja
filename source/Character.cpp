#include "Character.h"

#include <raylib.h>
#include <raymath.h>


Character::Character(int windowWidth, int windowHeight)
	: screenPosition({0.0f, 0.0f}),
	worldPosition({0.0f, 0.0f}),
	worldLastPosFrame({0.0f, 0.0f}),
	scale(4.0f),
	speed(5.0f),
	runningTime(0.0f),
	frame(0),
	maxFrames(4),
	updateTime(1.0f / 10.f),
	direction(DOWN),
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
	
}



void Character::StopMovement() {
	
}



