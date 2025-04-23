# Space-shooters-ecs

A cross-platform C++ application that uses SDL3 and a modular design to build a game-like application. The project employs an entity-component system along with several custom systems to enable gameplay logic and rendering.

## Features

-   **SDL3-based Windowing and Rendering:** Initializes an SDL3 window with a fixed resolution.
-   **Entity-Component-system (ECS):** Systems like `EnemyVelocitySystem`, `MoveSystem`, `UpdateSpritePositionSystem`, and `WindowGuardSystem` update game state.
-   **Game Manager:** Centralized management via [`GameManager`](src/components/GameManager.h) and [`PlayerController`](src/components/PlayerController.h) for user input and game state.
-   **Modular Architecture:** Separates rendering, input, and game logic for maintainability.

## Requirements

-   **Compiler:** A C++17 compliant compiler.
-   **CMake:** Version 3.10 or higher.
-   **SDL** 3.0: Required for graphics rendering.
-   **SDL_image** : Required for image loading
-   **SDL_ttf** : Required for fonts

## Building the Project

1. Create a build directory and navigate into it:

    ```sh
    mkdir build
    cd build
    ```

2. Generate the makefiles:

    ```sh
    cmake ..
    ```

3. Build the project:

    ```sh
    make
    ```

## Running the Application

After a successful build, run the generated executable (the name may vary):

```sh
./space-shooters-ecs   # or the appropriate executable name
```

## Directory Structure

```
space-shooters-ecs/
├── [CMakeLists.txt](http://_vscodecontentref_/1)
├── [main.cpp](http://_vscodecontentref_/2)
├── [README.md](http://_vscodecontentref_/3)
├── src/
│   ├── [App.cpp](http://_vscodecontentref_/4)
│   ├── App.h
│   ├── components/
│   │   ├── GameManager.h
│   │   ├── PlayerController.h
│   │   ├── Window.h
│   │   ├── WindowBackground.h
│   │   └── ECSSystems/
│   │       ├── EnemyVelocitySystem.h
│   │       ├── MoveSystem.h
│   │       ├── UpdateSpritePositionSystem.h
│   │       └── WindowGuardSystem.h
└── external/
    └── entt/
```

## License

This project is released under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

This project incorporates external libraries such as [entt](external/entt) for additional functionality.
