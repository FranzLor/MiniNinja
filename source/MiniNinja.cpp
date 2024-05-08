#include <iostream>
#include <raylib.h>
#include <raymath.h>



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

		Vector2 direction = { 0.0f, 0.0f };

		//UPDATE
		//WASD movement
		if (IsKeyDown(KEY_W)) {
			direction.y -= 1.0f;
		}
		if (IsKeyDown(KEY_D)) {
			direction.x += 1.0f;

		}
		if (IsKeyDown(KEY_S)) {
			direction.y += 1.0f;

		}
		if (IsKeyDown(KEY_A)) {
			direction.x -= 1.0f;

		}

		if (Vector2Length(direction) != 0.0f) {
			mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(direction), speed));
		}

		//RENDER
		//map
		const float mapScale = 4.0f;
		DrawTextureEx(map, mapPosition, 0.0f, mapScale, WHITE);

		//ninja
		Rectangle playerSrc = {
				0.0f,
				0.0f,
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
	CloseWindow();

	return 0;
}