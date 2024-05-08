#include <iostream>
#include <raylib.h>
#include <raymath.h>


enum PlayerDirection {
	//directions based on ninja tile set column
	RIGHT = 0,
	DOWN = 1,
	UP = 2,
	LEFT = 3
};

int main(void) {
	//INIT
	constexpr int windowWidth = 390;
	constexpr int windowHeight = 390;

	//window
	InitWindow(windowWidth, windowHeight, "Mini Ninja");

	//icon
	Image MiniNinjaIcon = LoadImage("assets/MiniNinjaIcon.png");
	SetWindowIcon(MiniNinjaIcon);

	//map
	Texture2D map = LoadTexture("assets/map.png");
	Vector2 mapPosition = { 0.0f, 0.0f };

	//ninja - player
	Texture2D ninja = LoadTexture("assets/ninja_sprite.png");
	//attributes
	float speed = 4.0f;
	float scale = 4.0f;
	//animation
	int frameWidth = ninja.width / 4;
	int frameHeight = ninja.height / 7;

	float updateTime = 1.0f / 10.0f;
	float runningTime = 0.0f;
	int frame = 0;
	int maxFrames = 4;

	bool isMoving = false;
	PlayerDirection playerDirection = DOWN;

	Vector2 ninjaPos = {
		static_cast<float>((windowWidth) - frameWidth * scale) / 2,
		static_cast<float>((windowHeight) - frameHeight * scale) / 2
	};

	SetTargetFPS(60);

	//MAIN LOOP
	while (!WindowShouldClose()) {
		//INIT RENDER
		BeginDrawing();
		ClearBackground(BLACK);

		Vector2 movementDirection = { 0.0f, 0.0f };

		//UPDATE
		//WASD movement
		if (IsKeyDown(KEY_W)) {
			movementDirection.y -= 1.0f;
			playerDirection = UP;
			isMoving = true;

		}
		if (IsKeyDown(KEY_D)) {
			movementDirection.x += 1.0f;
			playerDirection = RIGHT;
			isMoving = true;

		}
		if (IsKeyDown(KEY_S)) {
			movementDirection.y += 1.0f;
			playerDirection = DOWN;
			isMoving = true;

		}
		if (IsKeyDown(KEY_A)) {
			movementDirection.x -= 1.0f;
			playerDirection = LEFT;
			isMoving = true;

		}

		if (Vector2Length(movementDirection) != 0.0f) {
			mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(movementDirection), speed));
		}

		//RENDER
		//map
		const float mapScale = 4.0f;
		DrawTextureEx(map, mapPosition, 0.0f, mapScale, WHITE);


		//ninja
		//moving anim
		if (isMoving) {
			runningTime += GetFrameTime();
			if (runningTime >= updateTime) {
				frame = (frame + 1) % maxFrames;
				runningTime = 0.0f;
			}
		}
		//idle (no anim)
		else {
			frame = 0;
		}

		Rectangle playerSrc = {
			static_cast<float>((playerDirection - 1) * frameWidth),
			static_cast<float>(frame * frameHeight),
			static_cast<float>(frameWidth),
			static_cast<float>(frameHeight)
		};
		Rectangle playerDst = {
			ninjaPos.x,
			ninjaPos.y,
			frameWidth * scale,
			frameHeight * scale
		};
		Vector2 playerOrg = { 0.0f, 0.0f };
		DrawTexturePro(ninja, playerSrc, playerDst, playerOrg, 0.0f, WHITE);

		EndDrawing();
	}

	//CLEANUP
	UnloadImage(MiniNinjaIcon);
	UnloadTexture(ninja);
	CloseWindow();

	return 0;
}