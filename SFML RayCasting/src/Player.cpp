#include "Player.h"

Player::Player()
{
    this->pos = sf::Vector2f(300,400);

    this->circle = new sf::CircleShape(10,30);
    this->circle->setPosition(this->pos);
    //this->circle->setSize(sf::Vector2f(20,20));
    this->circle->setOrigin(10, 10);
    this->circle->setFillColor(sf::Color(255,255,255,150));
    //this->lengthOfLines = std::numeric_limits<int>::max();  ///It is for INFINTY LENGTH :D
    this->lengthOfLines = 99999999;
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

void Player::move()
{
    //this->pos = sf::Vector2f(sf::Mouse::getPosition((*window)).x, sf::Mouse::getPosition((*window)).y);
    float speed = 1;
    this->circle->setPosition(this->pos);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->pos.y-=speed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->pos.y+=speed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->pos.x-=speed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->pos.x+=speed;

}

void Player::update(sf::RenderWindow *window)
{
    this->angle = atan2(sf::Mouse::getPosition(*window).y-540,sf::Mouse::getPosition(*window).x-960); //(* 360) / (PI * 2);
    auto degree = (angle * 360) / (PI * 2);
    this->circle->setRotation(degree);
    //this->lines[55].

    for(int i = 0; i<LINES_COUNT; i++)
    {
        auto xoff = cos(((i-LINES_COUNT/2)*2*PI/360)+angle);
        auto yoff = sin(((i-LINES_COUNT/2)*2*PI/360)+angle);
            this->lines[i].setPos(this->pos.x, this->pos.y, this->pos.x+lengthOfLines*xoff, this->pos.y+lengthOfLines*yoff);
    }
    std::cout<<degree<<std::endl;
}


sf::Vector2f Player::getLinePoint1(int i)
{
    return this->lines[i].getPoint1().position;
}
sf::Vector2f Player::getLinePoint2(int i)
{
    return this->lines[i].getPoint2().position;
}
