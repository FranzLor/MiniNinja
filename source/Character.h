#pragma once

#include <raylib.h>

enum PlayerDirection {
	//directions based on ninja tile set columns
	RIGHT = 0,
	DOWN = 1,
	UP = 2,
	LEFT = 3
};


class Character {
private:
	Texture2D texture = LoadTexture("assets/ninja_sprite.png");
	Vector2 screenPosition;
	Vector2 worldPosition;
	Vector2 worldLastPosFrame;

	//attributes
	float speed;
	float scale;
	//animation
	int frameWidth = texture.width / 4;
	int frameHeight = texture.height / 7;
	float runningTime;
	int frame;
	const int maxFrames;
	const float updateTime;

	//player texture looks down first
	PlayerDirection direction;
	bool isMoving;

public:
	Character(int windowWidth, int windowHeight);
	~Character();

	inline Vector2 GetWorldPos() const { return worldPosition; }

	void HandleInput(float deltaTime);
	void StopMovement();

};

