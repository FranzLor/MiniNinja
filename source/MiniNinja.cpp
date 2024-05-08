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

	SetTargetFPS(60);

	//MAIN LOOP
	while (!WindowShouldClose()) {
		//INIT RENDER
		BeginDrawing();
		ClearBackground(BLACK);


		EndDrawing();
	}

	//CLEANUP
	UnloadImage(MiniNinjaIcon);
	CloseWindow();

	return 0;
}