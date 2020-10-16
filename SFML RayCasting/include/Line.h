#ifndef LINE_H
#define LINE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <SFML/Graphics.hpp>
#define WIDTH 1920
#define HEIGHT 1080
#define PI 3.14159265359

class Line
{
public:
    Line(float _x1, float _y1, float _x2, float _y2);
    Line();
    virtual ~Line();
    void show(sf::RenderWindow *window);
    void setPos(float _x1, float _y1, float _x2, float _y2);
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void setAlpha(uint8_t a);
    sf::Vertex getPoint1() {return point1;}
    sf::Vertex getPoint2() {return point2;}
private:
    sf::VertexArray L;
    sf::Vertex point1;
    sf::Vertex point2;
    bool isIntersects;

friend class Player;
friend class Game;

};

#endif // LINE_H
