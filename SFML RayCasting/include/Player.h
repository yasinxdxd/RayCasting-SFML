#ifndef PLAYER_H
#define PLAYER_H
#include <Wall.h>
#define LINES_COUNT 360


class Player
{
public:
    Player();
    virtual ~Player();
    void show(sf::RenderWindow *window);
    void move(sf::RenderWindow *window);
    sf::Vector2f getLinePoint1(int);
    sf::Vector2f getLinePoint2(int);

private:
    sf::Vector2f pos;
    sf::CircleShape* circle;
    Line lines[LINES_COUNT];
    int lengthOfLines;

friend class Game;
};

#endif // PLAYER_H
