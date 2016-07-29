#pragma once

#include <SFML/Graphics.hpp>
#include <list>

enum class Direction
{
    STOP, LEFT, RIGHT, UP, DOWN
};

class Snake
{
public:

    Snake(int mapWidth, int mapHeight, int segmentSize, int initLength);
    ~Snake();

    //main methods
    void DrawSnake(sf::RenderWindow &window);
    void HandleSnakeInput();
    void UpdateSnake(const float secElapsed);
    void ChangePosition(float x, float y);

    //utils
    float FloatMod(float num, float modulo);

    //setters & getters for snake body
    sf::RectangleShape GetSnakesSegment(unsigned int N);
    void AddSegment(sf::RectangleShape seg);
    int GetSnakeLength();

    //setters & getters for movement speed
    void SetSpeed(float speed) { this->speed=speed; }
    float GetSpeed() { return speed; }

private:

    //body
    std::list<sf::RectangleShape> snakeSegments;
    sf::RectangleShape singleSegment;
    int segmentSize;
    int initLength;

    //movement
    Direction currDirection;
    float speed;
    float timeSinceSnakeUpdate;

    //map resolution
    int mapWidth, mapHeight;
};

