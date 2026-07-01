#include "Camera.h"
#include "Config.h"

void UpdateCameraButtons(Camera &camera) {

    const bool *keyboard = SDL_GetKeyboardState(nullptr);

    if (keyboard[SDL_SCANCODE_W]) {
        camera.y -= CAMERA_SPEED;
    }

    if (keyboard[SDL_SCANCODE_S]) {
        camera.y += CAMERA_SPEED;
    }

    if (keyboard[SDL_SCANCODE_A]) {
        camera.x -= CAMERA_SPEED;
    }

    if (keyboard[SDL_SCANCODE_D]) {
        camera.x += CAMERA_SPEED;
    }
}

void UpdateCameraMouse(Camera &camera, SDL_Window *window) {

    float mouseX;
    float mouseY;

    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_GetWindowSize(window, &camera.viewportWidth, &camera.viewportHeight);

    if (mouseX < CAMERA_EDGE_SIZE) {
        camera.x -= CAMERA_SPEED;
    }

    if (mouseX > camera.viewportWidth - CAMERA_EDGE_SIZE) {
        camera.x += CAMERA_SPEED;
    }

    if (mouseY < CAMERA_EDGE_SIZE) {
        camera.y -= CAMERA_SPEED;
    }

    if (mouseY > camera.viewportHeight - CAMERA_EDGE_SIZE) {
        camera.y += CAMERA_SPEED;
    }
}

void UpdateCamera(Camera &camera, SDL_Window *window) {
    UpdateCameraButtons(camera);
    UpdateCameraMouse(camera, window);
}

void ClampCamera(Camera &camera, const Map &map) {
    float worldWidth = map.map_width * TILE_SIZE;
    float worldHeight = map.map_height * TILE_SIZE;

    if (worldWidth <= camera.viewportWidth) {
        camera.x = -(camera.viewportWidth - worldWidth) / 2.0f;
    } else {
        float maxX = worldWidth - camera.viewportWidth;

        if (camera.x < 0.0f)
            camera.x = 0.0f;

        if (camera.x > maxX)
            camera.x = maxX;
    }

    if (worldHeight <= camera.viewportHeight) {
        camera.y = -(camera.viewportHeight - worldHeight) / 2.0f;
    } else {
        float maxY = worldHeight - camera.viewportHeight;

        if (camera.y < 0.0f)
            camera.y = 0.0f;

        if (camera.y > maxY)
            camera.y = maxY;
    }
}
