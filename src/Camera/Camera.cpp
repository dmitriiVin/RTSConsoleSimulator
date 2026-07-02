#include "Camera.h"
#include "Config.h"

void UpdateCameraButtons(Camera &camera, float deltaTime) {

    const bool *keyboard = SDL_GetKeyboardState(nullptr);
    const float speed = CAMERA_SPEED * deltaTime;

    if (keyboard[SDL_SCANCODE_W]) {
        camera.y -= speed;
    }

    if (keyboard[SDL_SCANCODE_S]) {
        camera.y += speed;
    }

    if (keyboard[SDL_SCANCODE_A]) {
        camera.x -= speed;
    }

    if (keyboard[SDL_SCANCODE_D]) {
        camera.x += speed;
    }
}

void UpdateCameraMouse(Camera &camera, SDL_Window *window, float deltaTime) {

    float mouseX;
    float mouseY;

    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_GetWindowSize(window, &camera.viewportWidth, &camera.viewportHeight);

    const float speed = CAMERA_SPEED * deltaTime;

    if (mouseX < CAMERA_EDGE_SIZE) {
        camera.x -= speed;
    }

    if (mouseX > camera.viewportWidth - CAMERA_EDGE_SIZE) {
        camera.x += speed;
    }

    if (mouseY < CAMERA_EDGE_SIZE) {
        camera.y -= speed;
    }

    if (mouseY > camera.viewportHeight - CAMERA_EDGE_SIZE) {
        camera.y += speed;
    }
}

void UpdateCamera(Camera &camera, SDL_Window *window, float deltaTime) {
    UpdateCameraButtons(camera, deltaTime);
    UpdateCameraMouse(camera, window, deltaTime);
}

void ClampCamera(Camera &camera, const Map &map) {
    float worldWidth = map.map_width * TILE_SIZE;
    float worldHeight = map.map_height * TILE_SIZE;

    if (worldWidth <= camera.viewportWidth) {
        camera.x = -(camera.viewportWidth - worldWidth) / 2.0f;
    }
    else {
        float maxX = worldWidth - camera.viewportWidth;

        if (camera.x < 0.0f)
            camera.x = 0.0f;

        if (camera.x > maxX)
            camera.x = maxX;
    }

    if (worldHeight <= camera.viewportHeight) {
        camera.y = -(camera.viewportHeight - worldHeight) / 2.0f;
    }
    else {
        float maxY = worldHeight - camera.viewportHeight;

        if (camera.y < 0.0f)
            camera.y = 0.0f;

        if (camera.y > maxY)
            camera.y = maxY;
    }
}
