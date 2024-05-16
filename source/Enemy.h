#pragma once
#include <raylib.h>


enum EnemyDirection {
	//directions based on ninja tile set columns
	ENEMY_RIGHT = 0,
	ENEMY_DOWN = 1,
	ENEMY_UP = 2,
	ENEMY_LEFT = 3
};


class Enemy {
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
	EnemyDirection enemyDirection;
	bool isMoving;

public:
	Enemy(Vector2 pos, Texture2D texture);
	~Enemy();

	inline Vector2 GetWorldPos() const { return worldPosition; }

	void HandleInput(float deltaTime);
	void StopMovement();
	Rectangle GetCollisionRect();


};

