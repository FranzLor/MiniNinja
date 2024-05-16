#pragma once

#include <raylib.h>

enum PlayerDirection {
	//directions based on ninja tile set columns
	PLAYER_RIGHT = 0,
	PLAYER_DOWN = 1,
	PLAYER_UP = 2,
	PLAYER_LEFT = 3
};


class Character {
private:
	Texture2D texture;
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

	float width;
	float height;

	//player texture looks down first
	PlayerDirection playerDirection;
	bool isMoving;

public:
	Character(int windowWidth, int windowHeight);
	~Character();

	inline Vector2 GetWorldPos() const { return worldPosition; }

	void HandleInput(float deltaTime);
	void StopMovement();
	Rectangle GetCollisionRect();
};

