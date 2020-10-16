#ifndef PLAYER_H
#define PLAYER_H
#include <Line.h>
#define LINES_COUNT 60


class Player
{
public:
    Player();
    virtual ~Player();
    void show(sf::RenderWindow *window);
    void move();
    sf::Vector2f getLinePoint1(int);
    sf::Vector2f getLinePoint2(int);
    void update(sf::RenderWindow *window);

private:
    sf::Vector2f pos;
    sf::CircleShape* circle;
    Line lines[LINES_COUNT];
    int lengthOfLines;
    float angle;

friend class Game;
};

#endif // PLAYER_H
