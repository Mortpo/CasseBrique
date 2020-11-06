#include "../include/Ball.h"


Ball::Ball()
{
    //ctor

}

void Ball::deplacement()
{
    formeball.move(movex, movey);

}

Ball::Ball(float x, float y, float rayon)
{

    formeball.setPosition(sf::Vector2f(x,y));
    formeball.setRadius(rayon);
    formeball.setOrigin(sf::Vector2f(rayon,rayon));

}

Ball::Ball(float x, float y, float rayon,sf::Color couleur)
{

    formeball.setPosition(sf::Vector2f(x,y));
    formeball.setRadius(rayon);
    formeball.setOrigin(sf::Vector2f(rayon,rayon));
    formeball.setFillColor(couleur);
}

Ball::Ball(float x,float y,float rayon, std::string linktexture)
{

    formeball.setPosition(sf::Vector2f(x,y));
    formeball.setRadius(rayon);
    formeball.setOrigin(sf::Vector2f(rayon,rayon));
    textureball.loadFromFile(linktexture);
    spriteball.setTexture(textureball);

}
