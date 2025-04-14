//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton {
protected:
    Singleton() = default;
public:

    virtual ~Singleton()  = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static T* getInstance() {
        static T instance;
        return &instance;

    }
};

#endif //SINGLETON_H
