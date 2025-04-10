cmake_minimum_required(VERSION 3.30)
project(img_ly)

set(CMAKE_CXX_STANDARD 20)

# Define the executable target using your main.cpp source file
add_executable(img_ly main.cpp
        src/App.cpp
        src/App.h
        src/components/PlayerController.cpp
        src/components/PlayerController.h
        src/components/commands/Command.h
        src/components/commands/QuitCommand.cpp
        src/components/commands/QuitCommand.h
        src/components/Window.cpp
        src/components/Window.h
        src/components/WindowBackground.cpp
        src/components/WindowBackground.h
        src/components/GameManager.cpp
        src/components/GameManager.h
        src/utils/common.h
        src/ui/Button.cpp
        src/ui/Button.h)

target_include_directories(img_ly PRIVATE ${CMAKE_SOURCE_DIR}/external/entt/src)

# Find SDL3 package
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# Link SDL3 to the target
target_link_libraries(img_ly PRIVATE SDL3::SDL3)
target_link_libraries(img_ly PRIVATE SDL3_image::SDL3_image)
