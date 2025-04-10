# img-ly

TODO

## Features

-   **CMake Build:** Easily build the project using CMake.
-   **Cross-platform:** Designed to work on multiple operating systems with a C++17 compliant compiler.

## Requirements

-   **Compiler:** A C++17 compliant compiler.
-   **CMake:** Version 3.10 or higher.
-   **SDL** 3.0: Required for graphics rendering.

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
./img_ly   # or the appropriate executable name
```

## Directory Structure

```
.gitignore
.gitmodules
CMakeLists.txt
main.cpp
README.md
.idea/
cmake-build-debug/
external/
src/
```

## License

This project is released under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

This project incorporates external libraries such as [entt](external/entt) for additional functionality.
