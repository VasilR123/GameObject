#include "Player.h"
#include <iostream>

Player::Player() : GameObject(40, 25, '^', GREEN), lives(3), score(0) {}
Player::Player(int x, int y, int lives)
    : GameObject(x, y, '^', GREEN), lives(lives), score(0) {}
Player::Player(const Player& other)
    : GameObject(other), lives(other.lives), score(other.score) {}
Player::Player(Player&& other) noexcept
    : GameObject(std::move(other)), lives(other.lives), score(other.score) {}
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        GameObject::operator=(other);
        lives = other.lives;
        score = other.score;
    }
    return *this;
}
Player& Player::operator=(Player&& other) noexcept {
    if (this != &other) {
        GameObject::operator=(std::move(other));
        lives = other.lives;
        score = other.score;
    }
    return *this;
}
Player::~Player() {}

void Player::moveLeft() { if (x > 0) x--; }
void Player::moveRight() { if (x < 79) x++; }
void Player::shoot() { std::cout << "Player shoots!\n"; }
void Player::update() {}
void Player::render() const {
    std::cout << symbol << " at (" << x << "," << y << ")\n";
}

int Player::getLives() const { return lives; }
int Player::getScore() const { return score; }
void Player::setLives(int l) { lives = l; }
void Player::setScore(int s) { score = s; }

Player& Player::operator+(int points) {
    score += points;
    return *this;
}
Player& Player::operator-(int points) {
    score -= points;
    return *this;
}
