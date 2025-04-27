cmake_minimum_required(VERSION 3.30)

project(space-shooters-ecs
        VERSION 0.1.0
        DESCRIPTION "A simple ECS-based space shooter"
        LANGUAGES CXX
)

# ——————————————————————————————————————————————
# 1. C++ Standard & Build Type Defaults
# ——————————————————————————————————————————————
set(CMAKE_CXX_STANDARD        20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS      OFF)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING
            "Choose the type of build (Debug, Release, RelWithDebInfo, MinSizeRel)"
            FORCE)
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ——————————————————————————————————————————————
# 2. Options
# ——————————————————————————————————————————————
option(BUILD_TESTS "Build unit tests" OFF)

# ——————————————————————————————————————————————
# 3. Fetch External libraries automatically
# ——————————————————————————————————————————————
include(FetchContent)
FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG        v3.12.0  # pin to a stable release
)
FetchContent_MakeAvailable(entt)

FetchContent_Declare(
        glm
        GIT_REPOSITORY	https://github.com/g-truc/glm.git
        GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

# ——————————————————————————————————————————————
# 4. Collect your sources
# ——————————————————————————————————————————————
file(GLOB_RECURSE SHOOTER_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE SHOOTER_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# ——————————————————————————————————————————————
# 5. Define the executable
# ——————————————————————————————————————————————
add_executable(space-shooters-ecs
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${SHOOTER_SOURCES}
        ${SHOOTER_HEADERS}
)

# ——————————————————————————————————————————————
# 6. Include dirs
# ——————————————————————————————————————————————
target_include_directories(space-shooters-ecs
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${entt_SOURCE_DIR}/src>
)

# ——————————————————————————————————————————————
# 7. Compiler warnings
# ——————————————————————————————————————————————
if(MSVC)
    target_compile_options(space-shooters-ecs
            PRIVATE /W4 /permissive- /WX
    )
else()
    target_compile_options(space-shooters-ecs
            PRIVATE -Wall -Wextra -Wpedantic -Werror
    )
endif()

# ——————————————————————————————————————————————
# 8. Find & link SDL3
# ——————————————————————————————————————————————
find_package(SDL3      REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf   REQUIRED)

target_link_libraries(space-shooters-ecs
        PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
)

target_link_libraries(space-shooters-ecs PRIVATE glm::glm)

# ——————————————————————————————————————————————
# 9. Install rules
# ——————————————————————————————————————————————
install(TARGETS space-shooters-ecs
        RUNTIME DESTINATION bin
)

# Copy your resource tree alongside the binary
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resource/
        DESTINATION share/space-shooters-ecs/resource
)

# ——————————————————————————————————————————————
# 10. (Optional) Testing
# ——————————————————————————————————————————————
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# ——————————————————————————————————————————————
# 11. CPack packaging
# ——————————————————————————————————————————————
include(CPack)
set(CPACK_PACKAGE_NAME        "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION     "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT     "mosti.dev@gmail.com")
