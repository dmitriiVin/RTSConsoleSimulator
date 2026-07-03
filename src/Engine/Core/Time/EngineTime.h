//=================================================================================
//|                                                                               |
//|  RTSEngine                                                                    |
//|  Таймер кадра и FPS                                                           |
//|  Считает delta time, общее время работы                                       |
//|  и обновляет частоту кадров раз в секунду.                                    |
//|                                                                               |
//=================================================================================
#pragma once

#include <chrono>
#include <iostream>

class Time {

  public:
    Time();
    void Update();

    float GetDeltaTime() const;
    float GetElapsedTime() const;
    float GetFPS() const;
    bool IsFPSUpdated() const;

  private:
    std::chrono::steady_clock::time_point LastTime;
    double ElapsedTime = 0.0;

    float DeltaTime = 0.0f;
    float FPS = 0.0f;

    double FPSAccumulator = 0.0;
    int FPSFrameCounter = 0;

    bool FPSUpdated = false;
};
