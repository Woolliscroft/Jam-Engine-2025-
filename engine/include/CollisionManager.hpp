#pragma once
#include <vector>
#include <algorithm>
#include "SceneObject.hpp"

class CollisionManager {
public:
    static CollisionManager& Instance() {
        static CollisionManager instance;
        return instance;
    }

    void RegisterCollidable(SceneObject* obj) {
        collidables.push_back(obj);
    }

    void UnregisterCollidable(SceneObject* obj) {
        collidables.erase(std::remove(collidables.begin(), collidables.end(), obj), collidables.end());
    }

    const std::vector<SceneObject*>& GetCollidables() const {
        return collidables;
    }

private:
    std::vector<SceneObject*> collidables;
};
