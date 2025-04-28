#pragma once

#include <memory>
#include "utils/Singleton.h"

class GameHud;
class PlayerCharacter;
class Canvas;
class PlayerController;

/**
 * @enum GameState
 * @brief Enumerates the possible states of the game.
 */
enum class GameState {
    DEFAULT = 0, /**< Default uninitialized state */
    MAIN_MENU,   /**< Main menu screen state */
    PLAYING,      /**< Active gameplay state */
    GAME_OVER, /**< Game over state */
};

/**
 * @class GameManager
 * @brief Manages the overall game flow and state transitions.
 *
 * Inherits from Singleton to ensure a single global instance.
 */
class GameManager : public Singleton<GameManager> {
    friend class Singleton<GameManager>;

    /**
     * @brief Constructs the GameManager.
     * @note Private to enforce singleton pattern.
     */
    GameManager();

public:
    /**
     * @brief Initializes the GameManager with the PlayerController.
     * @param pc Pointer to the PlayerController used for player input.
     */
    static void initialize(PlayerController* pc);

    /**
     * @brief Destroys the GameManager instance.
     */
    ~GameManager();

    /**
     * @brief Updates the game each frame.
     * @param dt Delta time since last update in seconds.
     */
    static void update(float dt);

    /**
     * @brief Sets the current game state.
     * @param state The new GameState to set.
     */
    static void setCurrentState(GameState state);

    /**
     * @brief Retrieves the current game state.
     * @return The current GameState.
     */
    static GameState getCurrentState() { return getInstance()->currentState; }

    /**
     * @brief Adds points to the game score.
     * @param amount Number of points to add.
     */
    static void addScorePoint(int amount);

    /**
     * @brief Handles the player getting hit.
     */
    static void onPlayerHit();

private:
    /**
     * @brief Sets up gameplay elements when entering the PLAYING state.
     */
    void setupPlayState();

    PlayerController* playerController;            /**< Controller for player input */
    GameState currentState;                        /**< Current state of the game */

    std::unique_ptr<Canvas> mainMenuCanvas = nullptr;      /**< UI canvas for main menu */
    std::unique_ptr<GameHud> gameHud = nullptr;             /**< UI canvas for in-game HUD */
    std::unique_ptr<Canvas> gameOverCanvas = nullptr;       /**< UI canvas for game over screen */
    std::unique_ptr<PlayerCharacter> playerCharacter = nullptr; /**< The player character entity */

    int currentScore = 0; /**< Current score of the game */
};
