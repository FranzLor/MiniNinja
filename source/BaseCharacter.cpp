#include "BaseCharacter.h"

#include <raymath.h>


BaseCharacter::BaseCharacter()
	: isAlive(true),
	isAttacking(false),
	attackTime(0.0f),
	maxAttackTime(0.5f),
	texture(LoadTexture("assets/ninja_sprite.png")),
	attackTexture(LoadTexture("assets/ninja_attack.png")),
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

void BaseCharacter::Attack() {
    //make sure alive first
    if (!GetAlive()) {
        return;
    }

	isAttacking = true;
	attackTime = 0.0f;
	//reset frame 
	frame = 0;
}


void BaseCharacter::UpdateAnimation(float deltaTime) {
    //check if alive
    if (!GetAlive()) {
        return;
    }

    runningTime += deltaTime;

    //animation row offset
    //default, running animation
    int rowOffset = 0;
    if (isAttacking) {
        //attack animation, first row on separate sprite
        rowOffset = 0;
    }

    //animation frame based on movement or attacking state
    if (isMoving || isAttacking) {
        if (runningTime >= updateTime || isAttacking) {
            frame = (frame + 1) % maxFrames;
            runningTime = 0.0f;

            //attack animation, only show it for 0.15 seconds
            if (isAttacking && attackTime >= 0.15f) {
                isAttacking = false;
            }
        }
    }
    else {
        //reset for idling
        frame = 0;
    }

    //source rectangle based on direction and animation frame
    Rectangle characterSrc = {
        static_cast<float>((direction - 1) * frameWidth),
        static_cast<float>(frame * frameHeight + rowOffset * frameHeight),
        static_cast<float>(frameWidth),
        static_cast<float>(frameHeight)
    };

    //render the character
    Rectangle characterDst = {
        screenPosition.x,
        screenPosition.y,
        frameWidth * scale,
        frameHeight * scale
    };
    Vector2 characterOrg = { 0.0f, 0.0f };

    // Use separate texture based on the animation state
    Texture2D currentTexture = isAttacking ? attackTexture : texture;
    DrawTexturePro(currentTexture, characterSrc, characterDst, characterOrg, 0.0f, WHITE);

    //reset attack state after max attack time
    if (isAttacking) {
        attackTime += deltaTime;
        if (attackTime >= maxAttackTime) {
            isAttacking = false;
        }
    }
}



void BaseCharacter::StopMovement() {
	worldPosition = worldLastPosFrame;
}


Rectangle BaseCharacter::GetCollisionRect() {
	return Rectangle {
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

	//update animation
	UpdateAnimation(deltaTime);
}