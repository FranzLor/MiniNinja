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

	float speed = 4.0f;

	SetTargetFPS(60);

	//MAIN LOOP
	while (!WindowShouldClose()) {
		//INIT RENDER
		BeginDrawing();
		ClearBackground(BLACK);

		Vector2 direction = { 0.0f, 0.0f };

		if (IsKeyDown(KEY_W)) {
			direction.x -= 1.0f;
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

		const float mapScale = 4.0f;
		DrawTextureEx(map, mapPosition, 0.0f, mapScale, WHITE);

		EndDrawing();
	}

	//CLEANUP
	UnloadImage(MiniNinjaIcon);
	CloseWindow();

	return 0;
}