#include "Game.h"

Game::Game()
{
    this->window = new sf::RenderWindow (sf::VideoMode(WIDTH, HEIGHT), "RAY CASTING", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
    //this->window->setMouseCursorVisible(false);

    camera.x=window->getSize().x;
    camera.y=window->getSize().y;
    view.setCenter(camera.x/2,camera.y/2);
    view.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));

    for(int i = 0; i < WALL_COUNT; i++)
    {
        Line l;
        walls.push_back(l);
    }
    walls[0].setPos(300,60,500,300);
    walls[1].setPos(1200,700,700,800);
    walls[2].setPos(1500,300,1300,700);
    walls[3].setPos(1500,300,1900,300);
    walls[4].setPos(1900,300,1300,700);
    walls[5].setPos(1000,500,1000,300);

}

Game::~Game()
{
    delete this->window;
}

void Game::EventUpdate()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    this->window->close();
                break;
            default:
                break;
        }
    }
}

void Game::Draw()
{
    this->window->clear();
    //Draw
    this->window->setView(this->view);
        this->player.show(window);
        for(int j = 0; j<walls.size(); j++)
            walls[j].show(window);
    //Draw
    window->setView(window->getDefaultView());
    this->window->display();
}

void Game::Update()
{
    EventUpdate();

    //UPDATES:
    player.update(window);
    player.move();
    view.setCenter(camera.x/2,camera.y/2);
    view.reset(sf::FloatRect(player.pos.x-camera.x/2,player.pos.y-camera.y/2,camera.x,camera.y));
    Logic();

    //

    Draw();
}


void Game::Logic()
{
    for(int j = 0; j<walls.size(); j++)
    {
        for(int i = 0; i<LINES_COUNT; i++)
        {
            auto p1 = player.lines[i].L[0].position;
            auto p2 = player.lines[i].L[1].position;

            auto L1 = walls[j].L[0].position;
            auto L2 = walls[j].L[1].position;

            auto p = getIntersectionPoint(p1.x,p1.y,p2.x,p2.y,L1.x,L1.y,L2.x,L2.y,player.lines[i].isIntersects);

            if(this->player.lines[i].isIntersects)
                this->player.lines[i].setPos(this->player.pos.x, this->player.pos.y, p.x, p.y);
            //walls[j].setAlpha(0);

        }
    }
}


float Game::getDistance(float x1,float y1,float x2,float y2)
{
    return sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
}

sf::Vector2f Game::getIntersectionPoint(float d1x1, float d1y1, float d1x2, float d1y2, float d2x1, float d2y1, float d2x2, float d2y2, bool& isIntersects)
{
    float m1;
    float m2;
    float X;
    float Y;
    m1 = d1x1 < d1x2 ? (d1y1-d1y2)/(d1x1-d1x2) : (d1y2-d1y1)/(d1x2-d1x1);
    m2 = d2x1 < d2x2 ? (d2y1-d2y2)/(d2x1-d2x2) : (d2y2-d2y1)/(d2x2-d2x1);
    /*
    if(d1x2-d1x1!=0)
        m1 = d1x1 < d1x2 ? (d1y1-d1y2)/(d1x1-d1x2) : (d1y2-d1y1)/(d1x2-d1x1);
    else
        m1=1;

    if(d2x2-d2x1!=0)
        m2 = d2x1 < d2x2 ? (d2y1-d2y2)/(d2x1-d2x2) : (d2y2-d2y1)/(d2x2-d2x1);
    else
        m2=1;

    if(d1y2-d1y1==0)
        m1=0;

    if(d2y2-d2y1==0)
        m2=0;
    */

    if(m1 == std::numeric_limits<float>::infinity() || m1 <=-1.6384e+010)
    {
        X = d1x1;
        Y = m2 * (X - d2x1) + d2y1;
    }
    else if(m2 == std::numeric_limits<float>::infinity() || m2 <=-1.6384e+010)
    {
        X = d2x1;
        Y = m1 * (X - d1x1) + d1y1;
    }
    else
    {
        X = ((m1 * d1x1) - d1y1 - (m2 * d2x1) + d2y1)/(m1-m2);
        Y = m1 * (X - d1x1) + d1y1;
    }






    sf::Vector2f result;
    result.x=X;
    result.y=Y;


    //if(m2==std::numeric_limits<float>::infinity()||m2==std::numeric_limits<double>::quiet_NaN())
      //std::cout<<"Merhaba"<<std::endl;
      //  return result;
    //if(m1==std::numeric_limits<float>::infinity()||m1==std::numeric_limits<double>::quiet_NaN())
      //std::cout<<"Merhaba"<<std::endl;
      //  return result;

    float d1 = getDistance(d1x1, d1y1, d1x2, d1y2);
    float d2 = getDistance(d2x1, d2y1, d2x2, d2y2);

    sf::Vector2f far1;
    sf::Vector2f far2;
///////////////
    if(getDistance(d1x1, d1y1, result.x, result.y) > getDistance(d1x2, d1y2, result.x, result.y))
    {
        far1.x = d1x1;
        far1.y = d1y1;
    }
    else
    {
        far1.x = d1x2;
        far1.y = d1y2;
    }
///.////////////
    if(getDistance(d2x1, d2y1, result.x, result.y) > getDistance(d2x2, d2y2, result.x, result.y))
    {
        far2.x = d2x1;
        far2.y = d2y1;
    }
    else
    {
        far2.x = d2x2;
        far2.y = d2y2;
    }
///////////////
    //std::cout <<"m1: "<<m1<<"   m2: "<<m2<<"   X: "<<X<<"   Y: "<<Y<<"   isIntersection: "<<isIntersects<<" d2: "<<d2<<" bla: "<<getDistance(far2.x, far2.y, result.x, result.y)<<std::endl;
    if(getDistance(far1.x, far1.y, result.x, result.y)<=d1&&getDistance(far2.x, far2.y, result.x, result.y)<=d2)
        isIntersects = true;
    else
        isIntersects = false;

    if(isIntersects)
        return result;
    else
        return sf::Vector2f(0,0);





}

















