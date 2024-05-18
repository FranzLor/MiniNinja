#pragma once

#include <raylib.h>


enum Direction {
	//directions based on ninja tile set columns
	RIGHT = 0,
	DOWN = 1,
	UP = 2,
	LEFT = 3
};

class BaseCharacter {
protected:
	Texture2D texture;
	Vector2 screenPosition;
	Vector2 worldPosition;
	Vector2 worldLastPosFrame;
	Vector2 movementDirection;

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
	Direction direction;
	bool isMoving;

public:
	BaseCharacter();
	~BaseCharacter() = default;

	inline Vector2 GetWorldPos() const { return worldPosition; }

	void StopMovement();
	Rectangle GetCollisionRect();

	virtual void Movement(float deltaTime);

};

