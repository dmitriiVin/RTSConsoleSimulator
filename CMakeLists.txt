cmake_minimum_required(VERSION 3.10)

project(RTSEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Units/Unit.cpp
    src/Map/Map.cpp
    src/Map/MapGenerator.cpp
    src/Render/SDLRender.cpp
    src/Math/WorldMath.cpp
    src/Camera/Camera.cpp
    src/Engine/Time/EngineTime.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        src
        src/Config
        src/Units
        src/Map
        src/Render
        src/Math
        src/Camera
        src/Engine/Time
)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)
find_package(SDL3_ttf CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
        nlohmann_json::nlohmann_json
)
