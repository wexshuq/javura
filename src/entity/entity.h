//
// Created by wexshuq on 16.09.2026.
//

#pragma once
#include "../math/Angle.h"
#include "../math/transformation.h"

class World;

class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;

    float getHealth() const { return health; }
    void setHealth(const float newHealth) {
        if (newHealth > maxHealth) health = maxHealth;
        else if (newHealth < 0.0f) health = 0.0f;
        else health = newHealth;
    }

    float getSpeed() const { return speed; }
    void setSpeed(const float newSpeed) {
        if (newSpeed > maxSpeed) speed = maxSpeed;
        else if (newSpeed < 0.0f) speed = 0.0f;
        else speed = newSpeed;
    }

    const Transformation& getTransformation() const { return transformation; }
    const Vec3& getSize() const { return size; }
    void setSize(const Vec3& newSize) {
        size = newSize;
        transformation.scale = size;
    }

    const Vec3& getPosition() const { return transformation.pos; }
    Vec3& getPosition() { return transformation.pos; }

    Angle& getRotationAngle() { return rotation; }
    const Angle& getRotationAngle() const { return rotation; }

    virtual void Update(World& world) {}
    virtual void Draw(const World& world) const {}

private:
    Transformation transformation;
    Vec3 size;
    Angle rotation;
    Vec3 velocity;
    float maxSpeed = 10;
    float maxHealth = 150;
    float speed = 0;
    float health = 100;
};