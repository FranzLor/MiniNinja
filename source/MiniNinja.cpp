#include <iostream>
#include <raylib.h>


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

	SetTargetFPS(60);

	//MAIN LOOP
	while (!WindowShouldClose()) {
		//INIT RENDER
		BeginDrawing();
		ClearBackground(BLACK);

		mapPosition = { 0.0f, 0.0f };
		const float mapScale = 4.0f;
		DrawTextureEx(map, mapPosition, 0.0f, mapScale, WHITE);

		EndDrawing();
	}

	//CLEANUP
	UnloadImage(MiniNinjaIcon);
	CloseWindow();

	return 0;
}