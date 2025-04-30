#pragma once
#include "GameObject.h"

class Enemy : public GameObject {
protected:
    int direction;

public:
    Enemy();
    Enemy(int x, int y, char symbol, COLORS color);
    Enemy(const Enemy& other);
    Enemy(Enemy&& other) noexcept;
    Enemy& operator=(const Enemy& other);
    Enemy& operator=(Enemy&& other) noexcept;
    virtual ~Enemy();

    void update() override;
    void render() const override;
};
