#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
    int direction;

public:
    Bullet();
    Bullet(int x, int y, int dir);
    Bullet(const Bullet& other);
    Bullet(Bullet&& other) noexcept;
    Bullet& operator=(const Bullet& other);
    Bullet& operator=(Bullet&& other) noexcept;
    ~Bullet();

    void update() override;
    void render() const override;
};
