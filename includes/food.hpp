#pragma once

#include <SFML/Graphics.hpp>
#include "snake.hpp"

class Food
{
public:

    Food(int mapWidth, int mapHeight, int mapBorder, int radius);
    ~Food()=default;

    //methods for drawing
    void DrawFood(sf::RenderWindow &window);
    void SetRandomizedPosition();
    void DrawScore(sf::RenderWindow &window);

    //best score handling, reading from file
    int ReadBestScore();
    bool SetBestScore();

    //setters & getters
    sf::CircleShape GetFoodShape() { return foodShape; };
    void incrementScore() { score++; }

private:

    sf::CircleShape foodShape;
    int radius;

    //variables for score display
    int score;
    int bestScore;
    sf::Font font;
    sf::Text scoreText;
    sf::Text bestScoreText;

    //map resolution
    int mapWidth, mapHeight, mapBorder;
};

