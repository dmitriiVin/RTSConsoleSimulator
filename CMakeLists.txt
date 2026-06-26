cmake_minimum_required(VERSION 3.10)

project(RTSConsoleSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Unit.cpp
    src/Map.cpp
    )

target_include_directories(${PROJECT_NAME} PRIVATE include)

# find_package(SDL3 CONFIG REQUIRED)

# target_link_libraries(${PROJECT_NAME}
#     PRIVATE
#     SDL3::SDL3
# )

# find_package(SDL3_image CONFIG REQUIRED)

# target_link_libraries(${PROJECT_NAME}
#     PRIVATE
#     SDL3_image::SDL3_image
# )

# find_package(SDL3_ttf CONFIG REQUIRED)

# target_link_libraries(${PROJECT_NAME}
#     PRIVATE
#     SDL3_ttf::SDL3_ttf
# )
