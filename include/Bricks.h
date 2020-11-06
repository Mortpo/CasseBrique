#ifndef BRICKS_H
#define BRICKS_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Bricks
{
public:
    int pv, scorebrick;
    sf::RectangleShape formebrick;
    sf::Texture texturebrick;
    sf::Sprite spritebrick;
    sf::Color couleurbrick;

    void couleurfctpv();

    Bricks();
    Bricks(float x,float y,float largeur,float hauteur);
    Bricks(float x,float y,float largeur,float hauteur,sf::Color couleurbrick);
    Bricks(float x,float y, float largeur,float hauteur,int pv);
    Bricks(float x,float y, float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick);
    Bricks(float x,float y,float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick,std::string linktexture);
};

#endif // BRICKS_H
