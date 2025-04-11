cmake_minimum_required(VERSION 3.30)
project(img_ly)

set(CMAKE_CXX_STANDARD 20)

# Define the executable target using your main.cpp source file
add_executable(img_ly main.cpp
        src/App.cpp
        src/App.h
        src/components/PlayerController.cpp
        src/components/PlayerController.h
        src/components/Window.cpp
        src/components/Window.h
        src/components/WindowBackground.cpp
        src/components/WindowBackground.h
        src/components/GameManager.cpp
        src/components/GameManager.h
        src/utils/common.h
        src/components/ui/Button.cpp
        src/components/ui/Button.h
        src/components/ui/interfaces/Clickable.cpp
        src/components/ui/interfaces/Clickable.h
        src/utils/Timer.cpp
        src/utils/Timer.h
        src/components/ui/Canvas.cpp
        src/components/ui/Canvas.h
        src/components/ui/Widget.cpp
        src/components/ui/Widget.h)

target_include_directories(img_ly PRIVATE ${CMAKE_SOURCE_DIR}/external/entt/src)

# Find SDL3 package
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# Link SDL3 to the target
target_link_libraries(img_ly PRIVATE SDL3::SDL3)
target_link_libraries(img_ly PRIVATE SDL3_image::SDL3_image)
