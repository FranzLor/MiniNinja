#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

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
	Texture2D ninjaTexture = LoadTexture("assets/ninja_sprite.png");
	Character ninja(windowWidth, windowHeight);

	//enemy
	Texture2D samuraiTexture = LoadTexture("assets/enemy.png");
	Vector2 samuraiPos = { 0.0f, 0.0f };
	Enemy samurai(samuraiPos, samuraiTexture);

	//prop
	Texture2D rockTex = LoadTexture("assets/Rock.png");
	Texture2D logTex = LoadTexture("assets/Log.png");

	//current size of props in map
	Prop props[2]{
		Prop {Vector2{ 600.0f, 300.0f }, rockTex},
		Prop {Vector2{ 500.0f, 800.0f }, logTex}
	};

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

		//collision check for props
		for (auto& prop : props) {
			if (CheckCollisionRecs(prop.GetCollisionRec(ninja.GetWorldPos()), ninja.GetCollisionRect())) {
				ninja.StopMovement();
			}
		}

		//render prop
		for (auto& prop: props) {
			prop.Render(ninja.GetWorldPos());
		}

		ninja.Movement(GetFrameTime());

		samurai.Movement(GetFrameTime());

		EndDrawing();
	}

	//CLEANUP
	UnloadImage(MiniNinjaIcon);
	UnloadTexture(rockTex);
	CloseWindow();

	return 0;
}