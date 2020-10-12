#include "Line.h"

Line::Line(float _x1, float _y1, float _x2, float _y2)
{
    this->point1.position = sf::Vector2f(_x1, _y1);
    this->point2.position = sf::Vector2f(_x2, _y2);

    this->L.setPrimitiveType(sf::Lines);
    this->L.append(this->point1);
    this->L.append(this->point2);

    this->isIntersects=false;
}

Line::Line()
{
    this->point1.position = sf::Vector2f(0, 0);
    this->point2.position = sf::Vector2f(0, 0);

    this->L.setPrimitiveType(sf::Lines);
    this->L.append(this->point1);
    this->L.append(this->point2);

    this->isIntersects=false;
}

Line::~Line()
{

}

void Line::show(sf::RenderWindow *window)
{
    window->draw(this->L);
}

void Line::setPos(float _x1, float _y1, float _x2, float _y2)
{
    this->L[0].position = sf::Vector2f(_x1, _y1);
    this->L[1].position = sf::Vector2f(_x2, _y2);

}
