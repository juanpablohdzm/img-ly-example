//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#pragma once

#include <functional>
#include <thread>

/**
 * @class Timer
 * @brief A utility class for managing timed callbacks using a separate thread.
 *
 * The Timer class allows scheduling a callback function to be executed
 * after a specified interval. It runs the callback in a separate thread
 * and provides functionality to start and stop the timer.
 */
class Timer final {
public:
    /**
     * @brief Constructs a Timer object.
     *
     * Initializes the Timer instance and sets the running state to false.
     */
    Timer();

    /**
     * @brief Destroys the Timer object.
     *
     * Ensures that the timer thread is stopped and cleaned up properly.
     */
    ~Timer();

    /**
     * @brief Starts the timer and executes the callback after the specified interval.
     *
     * @param milliseconds The interval in milliseconds after which the callback is executed.
     * @param callback The function to be executed after the interval.
     */
    void start(int milliseconds, const std::function<void()>& callback);

    /**
     * @brief Stops the timer if it is running.
     *
     * Ensures that the timer thread is terminated safely.
     */
    void stop();

private:
    bool running; ///< Indicates whether the timer is currently running.
    std::thread timerThread; ///< The thread used to execute the timer callback.
};
