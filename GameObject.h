#pragma once
#include <iostream>

enum COLORS {
    BLACK = 0, BLUE = 1, CYAN = 3, GREEN = 2,
    RED = 4, BROWN = 6, PURPLE = 5, LIGHT_GREY = 7,
    GREY = 8, LIGHT_BLUE = 9, LIGHT_CYAN = 11, LIGHT_GREEN = 10,
    LIGHT_RED = 12, YELLOW = 14, PINK = 13, WHITE = 15
};

class GameObject {
protected:
    int x, y;
    char symbol;
    COLORS color;

public:
    GameObject();
    GameObject(int x, int y, char symbol, COLORS color);
    GameObject(const GameObject& other);
    GameObject(GameObject&& other) noexcept;
    GameObject& operator=(const GameObject& other);
    GameObject& operator=(GameObject&& other) noexcept;
    virtual ~GameObject();

    virtual void update() = 0;
    virtual void render() const = 0;

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    char getSymbol() const;
    COLORS getColor() const;
};
