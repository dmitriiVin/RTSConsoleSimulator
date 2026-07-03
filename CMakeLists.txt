#=================================================================================
#|                                                                               |
#|  RTSEngine                                                                    |
#|  Корневая сборка проекта                                                      |
#|  Здесь подключаются исполняемый файл                                          |
#|  и все модули движка и игры.                                                  |
#|                                                                               |
#=================================================================================
cmake_minimum_required(VERSION 3.10)

project(RTSEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/Engine/Core/Time/EngineTime.cpp

    src/Engine/Modules/TileMap/Map.cpp
    src/Engine/Modules/TileMap/MapGenerator.cpp
    src/Engine/Render/SDLRender.cpp
    src/Engine/Math/Isometric.cpp
    src/Engine/Camera/Camera.cpp

    src/Game/Units/Unit.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

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
