//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#pragma once

#include <memory>
#include <entt/entity/registry.hpp>

#include "utils/Singleton.h"

/**
 * @class ECSManager
 * @brief A singleton class for managing the Entity-Component-System (ECS) registry.
 *
 * The ECSManager class provides functionality to create entities, add components,
 * and retrieve views of entities with specific components. It uses the EnTT library
 * for ECS management and ensures a single instance of the registry is used throughout
 * the application.
 */
class ECSManager : public Singleton<ECSManager> {

    friend Singleton<ECSManager>; ///< Allows Singleton to access private members.

    /**
     * @brief Private constructor to enforce the singleton pattern.
     *
     * Initializes the ECS registry.
     */
    ECSManager();

public:
    /**
     * @brief Creates a new entity in the ECS registry.
     *
     * @return The newly created entity.
     */
    static entt::entity create();

    /**
     * @brief Adds a component of type T to an entity.
     *
     * This function forwards the provided arguments to the constructor of the component.
     *
     * @tparam T The type of the component to add.
     * @tparam Args The types of the arguments to pass to the component's constructor.
     * @param args The arguments to pass to the component's constructor.
     */
    template <typename T, typename ...Args>
    static void emplace(Args&&... args);

    /**
     * @brief Retrieves a view of entities with specific components.
     *
     * This function allows querying entities that have the specified components
     * and optionally excludes entities with certain components.
     *
     * @tparam Components The types of components to include in the view.
     * @tparam Exclude The types of components to exclude from the view.
     * @param exclude An optional exclusion list of components.
     * @return A view of entities matching the specified criteria.
     */
    template<typename... Components, typename... Exclude>
    static auto view(entt::exclude_t<Exclude...> exclude = entt::exclude_t<Exclude...>{});

    /**
     * @brief Destroys entities in the specified range.
     *
     * This function destroys all entities in the provided iterator range [begin, end)
     * within the ECS registry. The iterator's value type must be convertible to
     * entt::entity.
     *
     * @tparam Iterator Iterator type with values convertible to entt::entity.
     * @param begin Iterator pointing to the beginning of the range.
     * @param end Iterator pointing to the end of the range.
     */
    template<typename Iterator>
    static std::enable_if_t<std::is_convertible_v<typename std::iterator_traits<Iterator>::value_type, entt::entity>, void>
    destroy(Iterator begin, Iterator end);
private:
    std::unique_ptr<entt::registry> registry = nullptr; ///< The ECS registry instance.
};

template<typename T, typename ... Args>
void ECSManager::emplace(Args &&...args) {
    auto* instance = getInstance();
    instance->registry->emplace<T>(std::forward<Args>(args)...);
}

template<typename ... Components, typename ... Exclude>
auto ECSManager::view(entt::exclude_t<Exclude...> exclude) {
        return getInstance()->registry->view<Components...>(exclude);
}

template<typename Iterator>
std::enable_if_t<std::is_convertible_v<typename std::iterator_traits<Iterator>::value_type, entt::entity>, void>
ECSManager::destroy(Iterator begin, Iterator end) {
        getInstance()->registry->destroy(begin, end);
}
