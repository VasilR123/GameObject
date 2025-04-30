#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : GameObject(0, 0, 'E', RED), direction(1) {}
Enemy::Enemy(int x, int y, char sym, COLORS color)
    : GameObject(x, y, sym, color), direction(1) {}
Enemy::Enemy(const Enemy& other) : GameObject(other), direction(other.direction) {}
Enemy::Enemy(Enemy&& other) noexcept : GameObject(std::move(other)), direction(other.direction) {}
Enemy& Enemy::operator=(const Enemy& other) {
    if (this != &other) {
        GameObject::operator=(other);
        direction = other.direction;
    }
    return *this;
}
Enemy& Enemy::operator=(Enemy&& other) noexcept {
    if (this != &other) {
        GameObject::operator=(std::move(other));
        direction = other.direction;
    }
    return *this;
}
Enemy::~Enemy() {}

void Enemy::update() {
    x += direction;
    if (x < 0 || x > 79) direction *= -1;
}
void Enemy::render() const {
    std::cout << symbol << " at (" << x << "," << y << ")\n";
}
