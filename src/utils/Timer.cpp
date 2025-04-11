//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#include "Timer.h"

Timer::Timer() : running(false) {
}

Timer::~Timer() {
    stop();
}

void Timer::start(int milliseconds, const std::function<void()> &callback) {
    if (running) return; // Prevent multiple timers from running simultaneously
    running = true;

    if (timerThread.joinable()) {
        timerThread.join();
    }

    timerThread = std::thread([=]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        if (running) {
            callback();
            running = false;
        }
    });
}

void Timer::stop() {
    running = false;
    if (timerThread.joinable()) {
        timerThread.join();
    }
}
