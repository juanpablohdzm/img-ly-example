//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#pragma once

/**
 * @class Singleton
 * @brief A template class to implement the Singleton design pattern.
 *
 * The Singleton class ensures that only one instance of a given type T
 * exists throughout the program. It provides a global access point to
 * this instance and prevents copying or moving of the instance.
 *
 * @tparam T The type of the class to be implemented as a Singleton.
 */
template <typename T>
class Singleton {
protected:
    /**
     * @brief Protected default constructor to prevent direct instantiation.
     */
    Singleton() = default;

public:
    /**
     * @brief Virtual destructor to allow proper cleanup in derived classes.
     */
    virtual ~Singleton() = default;

    /**
     * @brief Deleted copy constructor to prevent copying of the Singleton instance.
     */
    Singleton(const Singleton&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying of the Singleton instance.
     */
    Singleton& operator=(const Singleton&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving of the Singleton instance.
     */
    Singleton(Singleton&&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving of the Singleton instance.
     */
    Singleton& operator=(Singleton&&) = delete;

    /**
     * @brief Provides access to the single instance of the class.
     *
     * This function creates the instance on the first call and returns
     * a pointer to it. Subsequent calls return the same instance.
     *
     * @return A pointer to the single instance of the class.
     */
    static T* getInstance() {
        static T instance;
        return &instance;
    }
};
