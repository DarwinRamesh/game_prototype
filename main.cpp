#include "raylib.h"

constexpr int screenWidth = 800;
constexpr int screenHeight = 800;

int main(){
    	InitWindow(screenWidth, screenHeight, "Test Window");

    	Camera3D camera = { 0 };
    	camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    	camera.fovy = 45.0f;                                // Camera field-of-view Y
    	camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    	SetTargetFPS(144);                   // Set our game to run at 60 frames-per-second

	while (!WindowShouldClose()){
		UpdateCamera(&camera, CAMERA_FREE);

		if (IsKeyPressed(KEY_Z)) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);

		DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
		DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

		DrawGrid(10, 1.0f);

		EndMode3D();
		EndDrawing();
	}
	CloseWindow();        // Close window and OpenGL context
}

