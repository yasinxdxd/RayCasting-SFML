#ifndef GAME_H
#define GAME_H
#include "Player.h"


class Game
{
public:
    Game();
    virtual ~Game();
    void Gameloop(){while(this->window->isOpen()){this->Update();}}

private:
    sf::RenderWindow* window;
    sf::Event event;
    Player player;
    Line line1;
    Line line2;
    Line line3;

private:
    void Logic();
    void Update();
    void EventUpdate();
    void Draw();

private:
    float getDistance(float x1,float y1,float x2,float y2);
    sf::Vector2f getIntersectionPoint(float d1x1, float d1y1, float d1x2, float d1y2, float d2x1, float d2y1, float d2x2, float d2y2, bool& isIntersects);

};

#endif // GAME_H
