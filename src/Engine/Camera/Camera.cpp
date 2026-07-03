//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Логика камеры                                                                |
//|  Обрабатывает клавиатуру, край экрана                                         |
//|  и ограничивает позицию внутри карты.                                         |
//|                                                                               |
//=================================================================================
#include "Engine/Camera/Camera.h"

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
    UpdateViewport(camera, window);
    UpdateCameraButtons(camera, deltaTime);
    UpdateCameraMouse(camera, window, deltaTime);
}

void UpdateViewport(Camera &camera, SDL_Window *window) {
    SDL_GetWindowSize(window, &camera.viewportWidth, &camera.viewportHeight);
}

void ClampCamera(Camera &camera, const Map &map) {
    MapBounds bounds = GetMapBounds(map, camera);

    if (bounds.left > 0.0f) {
        camera.x -= bounds.left;
    }

    if (bounds.right < camera.viewportWidth) {
        camera.x += camera.viewportWidth - bounds.right;
    }

    if (bounds.top > 0.0f) {
        camera.y -= bounds.top;
    }

    if (bounds.bottom < camera.viewportHeight) {
        camera.y += camera.viewportHeight - bounds.bottom;
    }
}
