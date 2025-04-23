cmake_minimum_required(VERSION 3.30)
project(space-shooters-ecs)

set(CMAKE_CXX_STANDARD 20)

# Define the executable target using your main.cpp source file
add_executable(space-shooters-ecs main.cpp
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
        src/components/ui/Button.cpp
        src/components/ui/Button.h
        src/components/ui/interfaces/Clickable.h
        src/utils/Timer.cpp
        src/utils/Timer.h
        src/components/ui/Canvas.cpp
        src/components/ui/Canvas.h
        src/components/ui/Widget.cpp
        src/components/ui/Widget.h
        src/components/ui/Sprite.cpp
        src/components/ui/Sprite.h
        src/components/ui/menus/MainMenu.cpp
        src/components/ui/menus/MainMenu.h
        src/utils/Singleton.h
        src/components/ECSManager.cpp
        src/components/ECSManager.h
        src/components/ui/menus/GameHud.cpp
        src/components/ui/menus/GameHud.h
        src/components/ui/Label.cpp
        src/components/ui/Label.h
        src/components/ECSEntities/PlayerCharacter.cpp
        src/components/ECSEntities/PlayerCharacter.h
        src/components/ECSSystems/MoveSystem.h
        src/components/ECSSystems/UpdateSpritePositionSystem.h
        src/components/ECSSystems/WindowGuardSystem.h
        src/components/ECSSystems/UpdateEnemyTargetSystem.h
        src/components/ECSComponents/PlayerTag.h
        src/components/ECSComponents/EnemyTag.h
        src/components/ECSComponents/SpeedComp.h
        src/components/ECSComponents/VelocityComp.h
        src/components/ECSComponents/WindowGuardComp.h
        src/components/ECSComponents/PositionComp.h
        src/utils/Color.h
        src/components/ECSComponents/ECSComponentsGeneral.h
        src/components/ECSSystems/SpriteRenderSystem.h
        src/components/ECSComponents/TargetPosition.h
        src/components/ECSSystems/UpdateEnemyVelocitySystem.h
        src/components/ECSSystems/SpawnEnemySystem.h
        src/components/ECSComponents/GunTag.h
        src/components/ECSSystems/UpdateGunTransformSystem.h
        src/components/ECSComponents/BulletTag.h
        src/components/ECSSystems/DespawnBulletSystem.h
        src/components/ECSComponents/DespawnTag.h
        src/components/ECSSystems/DespawnEntitiesSystem.h
)

target_include_directories(space-shooters-ecs PRIVATE ${CMAKE_SOURCE_DIR}/external/entt/src)

# Find SDL3 package
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)

# Link SDL3 to the target
target_link_libraries(space-shooters-ecs PRIVATE SDL3::SDL3)
target_link_libraries(space-shooters-ecs PRIVATE SDL3_image::SDL3_image)
target_link_libraries(space-shooters-ecs PRIVATE SDL3_ttf::SDL3_ttf)
