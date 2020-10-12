#include "Player.h"

Player::Player()
{
    this->pos = sf::Vector2f(300,400);

    this->circle = new sf::CircleShape(10,360);
    this->circle->setOrigin(this->circle->getRadius(), this->circle->getRadius());
    this->circle->setPosition(this->pos);
    this->circle->setFillColor(sf::Color(255,255,255,150));
    //this->lengthOfLines = std::numeric_limits<int>::max();  ///It is for INFINTY LENGTH :D
    this->lengthOfLines = 100;//99999999;
}

Player::~Player()
{
    delete this->circle;
}

void Player::show(sf::RenderWindow *window)
{
    window->draw(*this->circle);
    for(int i = 0; i<LINES_COUNT; i++)
    {
        this->lines[i].show(window);
    }
}

void Player::move(sf::RenderWindow *window)
{
    this->pos = sf::Vector2f(sf::Mouse::getPosition((*window)).x, sf::Mouse::getPosition((*window)).y);
    this->circle->setPosition(this->pos);


    //auto xoff = 100;
    //auto yoff = 500;

    for(int i = 0; i<LINES_COUNT; i++)
    {
        auto xoff = cos(90*2*PI/360);
        auto yoff = sin((90*2*PI/360));
        //if(i==90)
        //    continue;
        //else if(i == 270)
        //    continue;
        //else
            this->lines[i].setPos(this->pos.x, this->pos.y, this->pos.x+lengthOfLines*xoff, this->pos.y+lengthOfLines*yoff);
    }
}


sf::Vector2f Player::getLinePoint1(int i)
{
    return this->lines[i].getPoint1().position;
}
sf::Vector2f Player::getLinePoint2(int i)
{
    return this->lines[i].getPoint2().position;
}
