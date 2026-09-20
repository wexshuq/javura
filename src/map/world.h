//
// Created by wexshuq on 15.09.2026.
//

#pragma once
#include <memory>
#include <vector>

#include "../engine/input_controller.h"
#include "../entity/entity.h"
#include "../entity/impl/player.h"
#include "../math/transformation.h"
#include "../engine/camera.h"
#include "../utils/JavColor.h"

class Engine;

struct MapObject {
    Transformation transformation;
    JavColor color = {0,0,255,255}; // red
};

class World {
public:
    Player mainPlayer;
    Transformation transformation;
    bool initialized = false;

    void Init();
    void Render(const MainCamera& camera) const;
    void Update(PlayerInputData& pid, float deltaTime);

    std::vector<std::unique_ptr<MapObject>> objects;
    std::unique_ptr<std::vector<Entity>> entities;
private:
    float size = 50;
    Vec3 center = Vec3(0, 1, 0);
};

