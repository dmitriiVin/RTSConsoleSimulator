#include "EngineTime.h"
#include <chrono>

void Time::Update() {
    FPSUpdated = false;
    auto currentTime = std::chrono::steady_clock::now();

    DeltaTime = std::chrono::duration<float>(currentTime - LastTime).count();

    LastTime = currentTime;

    ElapsedTime += DeltaTime;

    FPSAccumulator += DeltaTime;
    FPSFrameCounter++;

    if (FPSAccumulator >= 1) {
        FPS = FPSFrameCounter;
        FPSAccumulator = FPSAccumulator - 1;
        FPSFrameCounter = 0;

        FPSUpdated = true;
    }
}

bool Time::IsFPSUpdated() const {
    return FPSUpdated;
}

float Time::GetElapsedTime() const {
    return ElapsedTime;
}

float Time::GetDeltaTime() const {
    return DeltaTime;
}

float Time::GetFPS() const {
    return FPS;
}

Time::Time() {
    LastTime = std::chrono::steady_clock::now();
}
