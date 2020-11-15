#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>


class Ball
{
public:
// attributs

    int ptvie;
    float movex, movey;


    sf::Vector2f position;
    sf::Sprite spriteball;
    sf::Texture textureball;
    sf::CircleShape formeball;
    sf::Color colball;
    void deplacement();


    Ball();
    Ball(float x, float y, float rayon);
    Ball(float x, float y, float rayon,sf::Color couleur);
    Ball(float x,float y,float rayon, std::string linktexture);


};

#endif // BALL_H
