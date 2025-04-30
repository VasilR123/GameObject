#include "Bullet.h"
#include <iostream>

Bullet::Bullet() : GameObject(0, 0, '|', WHITE), direction(-1) {}
Bullet::Bullet(int x, int y, int dir) : GameObject(x, y, '|', WHITE), direction(dir) {}
Bullet::Bullet(const Bullet& other) : GameObject(other), direction(other.direction) {}
Bullet::Bullet(Bullet&& other) noexcept : GameObject(std::move(other)), direction(other.direction) {}
Bullet& Bullet::operator=(const Bullet& other) {
    if (this != &other) {
        GameObject::operator=(other);
        direction = other.direction;
    }
    return *this;
}
Bullet& Bullet::operator=(Bullet&& other) noexcept {
    if (this != &other) {
        GameObject::operator=(std::move(other));
        direction = other.direction;
    }
    return *this;
}
Bullet::~Bullet() {}

void Bullet::update() {
    y += direction;
}
void Bullet::render() const {
    std::cout << symbol << " at (" << x << "," << y << ")\n";
}
