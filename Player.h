#pragma once
#include "GameObject.h"

class Player : public GameObject {
    int lives;
    int score;

public:
    Player();
    Player(int x, int y, int lives = 3);
    Player(const Player& other);
    Player(Player&& other) noexcept;
    Player& operator=(const Player& other);
    Player& operator=(Player&& other) noexcept;
    ~Player();

    void moveLeft();
    void moveRight();
    void shoot();
    void update() override;
    void render() const override;

    int getLives() const;
    int getScore() const;
    void setLives(int l);
    void setScore(int s);

    Player& operator+(int points);
    Player& operator-(int points);
};
