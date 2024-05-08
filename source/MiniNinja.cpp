#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include "Character.h"
#include "Prop.h"

int main(void) {
	//INIT
	constexpr int windowWidth = 400;
	constexpr int windowHeight = 400;

	//window
	InitWindow(windowWidth, windowHeight, "Mini Ninja");

	//icon
	Image MiniNinjaIcon = LoadImage("assets/MiniNinjaIcon.png");
	SetWindowIcon(MiniNinjaIcon);

	//map
	Texture2D map = LoadTexture("assets/map_v2.png");
	Vector2 mapPosition = { 0.0f, 0.0f };


	//player
	Character ninja(windowWidth, windowHeight);

	//prop
	Texture2D rockTex = LoadTexture("assets/Rock.png");
	Prop rock(Vector2{ 0.0f, 0.0f }, rockTex);

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

		//prop
		rock.Render(ninja.GetWorldPos());

		ninja.HandleInput(GetFrameTime());

		EndDrawing();
	}

	//CLEANUP
	UnloadImage(MiniNinjaIcon);
	UnloadTexture(rockTex);
	CloseWindow();

	return 0;
}