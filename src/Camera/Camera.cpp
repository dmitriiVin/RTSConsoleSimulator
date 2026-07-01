#include "Camera.h"

void UpdateCamera(Camera &camera) {
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
