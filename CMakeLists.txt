cmake_minimum_required(VERSION 3.20)
project(ChaoticEngine
        VERSION 0.1.0
        LANGUAGES CXX
        )


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(SOURCE_FILES 
    src/main.cpp
    engine/core/logger/logger.cpp
    engine/graphics/renderer/renderer.cpp
    engine/graphics/texture/Texture.cpp
    engine/core/window/window.cpp
    engine/core/main/engine.cpp
    engine/graphics/sprite/sprite.cpp
    engine/core/time/game_clock.cpp
    engine/core/actors/actor_components/transform.cpp
    engine/core/actors/actor.cpp
    engine/graphics/animation/actor_animator.cpp
    # engine/graphics/animation/animation.cpp
    )

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_subdirectory(vendored/SDL_image EXCLUDE_FROM_ALL)

# Create your game executable target as usual
add_executable(ChaoticEngine 
                ${SOURCE_FILES}
)

target_include_directories(ChaoticEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/engine)

# Link to the actual SDL3 library.
target_link_libraries(ChaoticEngine PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)

target_compile_features(ChaoticEngine PRIVATE cxx_std_20)

if(MSVC)
    target_compile_options(ChaoticEngine PRIVATE /W4)
else()
    target_compile_options(ChaoticEngine PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()