#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include "Character.h"


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

	Character ninja(windowWidth, windowHeight);

	SetTargetFPS(60);
	//MAIN LOOP
	while (!WindowShouldClose()) {
		//INIT RENDER
		BeginDrawing();
		ClearBackground(BLACK);

		//UPDATE
		mapPosition = Vector2Scale(ninja.GetWorldPos(), -1.0f);
		const float mapScale = 4.0f;

		//RENDER
		//map
		DrawTextureEx(map, mapPosition, 0.0f, mapScale, WHITE);

		//map boundary
		if (ninja.GetWorldPos().x < 0.0f ||
			ninja.GetWorldPos().y < 0.0f ||
			ninja.GetWorldPos().x + windowWidth > map.width * mapScale ||
			ninja.GetWorldPos().y + windowHeight > map.height * mapScale) {

			ninja.StopMovement();
		}

		ninja.HandleInput(GetFrameTime());

		EndDrawing();
	}

	//CLEANUP
	UnloadImage(MiniNinjaIcon);
	CloseWindow();

	return 0;
}