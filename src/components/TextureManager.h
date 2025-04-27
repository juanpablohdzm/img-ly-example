//
// Created by Juan Pablo Hernandez Mosti on 25/04/25.
//

#pragma once

#include <string>
#include <unordered_map>
#include <SDL3_image/SDL_image.h>
#include "utils/Singleton.h"


/**
 * @class TextureManager
 * @brief A singleton class responsible for managing and caching SDL_Texture objects.
 *
 * This class provides functionality to load and retrieve textures, ensuring that
 * textures are loaded only once and reused when needed. It uses the Singleton pattern
 * to ensure a single instance of the manager throughout the application.
 */
class TextureManager final : Singleton<TextureManager> {
    // Allow Singleton base class to access the private constructor
    friend class Singleton<TextureManager>;

    /**
     * @brief Private constructor to enforce the Singleton pattern.
     */
    TextureManager() = default;

public:
    /**
     * @brief Destructor to clean up loaded textures.
     */
    ~TextureManager();

    /**
     * @brief Loads a texture from the given path or retrieves it if already loaded.
     *
     * @param path The file path to the texture.
     * @return A pointer to the loaded SDL_Texture.
     */
    static SDL_Texture* getOrLoadTexture(const std::string& path);

private:
    /**
     * @brief A map to store cached textures, using the file path as the key.
     */
    std::unordered_map<std::string, SDL_Texture*> textures;
};
