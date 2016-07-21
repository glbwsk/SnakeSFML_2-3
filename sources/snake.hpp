#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <SFML/Graphics.hpp>
#include <list>

enum Direction
{
    STOP, LEFT, RIGHT, UP, DOWN
};

class Snake
{
public:
    Snake();
    ~Snake();

    void drawSnake(sf::RenderWindow &window);
    void input();
    void update();
    void changePosition(float x, float y);

    //setters & getters
    void setspeed(float sp);
    float getspeed();
    void addSegment(sf::RectangleShape seg);
    sf::RectangleShape getSnakesHead();

private:
    std::list<sf::RectangleShape> snakeSegments;
    sf::RectangleShape singleSegment;
    Direction currDirection;
    float segmentSize;
    float speed;

    sf::Time timeSinceLastUpdate;
    sf::Time timePerFrame;
    sf::Clock clock;
};

#endif
