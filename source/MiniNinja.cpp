#include <iostream>
#include <raylib.h>


int main(void) {
	//INIT
	constexpr int windowWidth = 390;
	constexpr int windowHeight = 390;

	//window
	InitWindow(windowWidth, windowHeight, "Mini Ninja");

	SetTargetFPS(60);

	//MAIN LOOP
	while (!WindowShouldClose()) {
		//INIT RENDER
		BeginDrawing();
		ClearBackground(BLACK);


		EndDrawing();
	}

	//CLEANUP
	CloseWindow();

	return 0;
}