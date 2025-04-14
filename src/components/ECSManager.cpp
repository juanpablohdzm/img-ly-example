//
// Created by Juan Pablo Hernandez Mosti on 14/04/25.
//

#include "ECSManager.h"

ECSManager::ECSManager(): registry(std::make_unique<entt::registry>()) {
}

entt::entity ECSManager::create() {
    const auto* instance = getInstance();
    return instance->registry->create();
}
