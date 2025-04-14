//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#ifndef ECSMANAGER_H
#define ECSMANAGER_H
#include <memory>
#include <entt/entity/registry.hpp>

#include "../utils/Singleton.h"


class ECSManager : public Singleton<ECSManager> {

    friend Singleton<ECSManager>;
    ECSManager();

public:
    static entt::entity create();
    template <typename T, typename ...Args>
    static void emplace(Args&&... args);
    template<typename... Components, typename... Exclude>
    static auto view(entt::exclude_t<Exclude...> exclude = entt::exclude_t<Exclude...>{});

private:
    std::unique_ptr<entt::registry> registry = nullptr;
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


#endif //ECSMANAGER_H
