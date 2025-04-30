#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

Game::Game() : level(1), running(true) {
    player = Player(40, 24);
    initializeEnemies();
}

Game::~Game() {
    for (auto e : enemies) delete e;
    for (auto b : bullets) delete b;
}

void Game::initializeEnemies() {
    enemies.clear();
    for (int i = 0; i < 5; ++i)
        enemies.push_back(new Enemy(i * 10 + 10, 2, 'X', RED));
}

void Game::input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'a') player.moveLeft();
        else if (ch == 'd') player.moveRight();
        else if (ch == ' ') bullets.push_back(new Bullet(player.getX(), player.getY() - 1, -1));
        else if (ch == 'q') running = false;
    }
}

void Game::update() {
    for (auto e : enemies) e->update();
    for (auto b : bullets) b->update();
    checkCollisions();
}

void Game::checkCollisions() {
}

void Game::render() {
    system("cls");
    player.render();
    for (auto e : enemies) e->render();
    for (auto b : bullets) b->render();
    std::cout << "Score: " << player.getScore() << "  Lives: " << player.getLives() << "\n";
}

void Game::run() {
    while (running) {
        input();
        update();
        render();
        Sleep(100);
    }
}
