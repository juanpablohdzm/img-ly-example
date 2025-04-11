//
// Created by Juan Pablo Hernandez Mosti on 11/04/25.
//

#ifndef TIMER_H
#define TIMER_H
#include <functional>
#include <thread>


class Timer final{
public:
    Timer();
    ~Timer();

    void start(int milliseconds, const std::function<void()>& callback);
    void stop();

private:
    bool running;
    std::thread timerThread;
};



#endif //TIMER_H
