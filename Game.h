#pragma once
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Game {
    Player player;
    std::vector<GameObject*> enemies;
    std::vector<GameObject*> bullets;
    int level;
    bool running;

public:
    Game();
    ~Game();

    void initializeEnemies();
    void input();
    void update();
    void render();
    void checkCollisions();
    void run();
};
