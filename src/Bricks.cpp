#include "../include/Bricks.h"

Bricks::Bricks()
{
}
Bricks::Bricks(float x,float y,float largeur,float hauteur)
{
    formebrick.setPosition(sf::Vector2f(x,y));
    formebrick.setSize(sf::Vector2f(largeur,hauteur));
}

Bricks::Bricks(float x,float y,float largeur,float hauteur,sf::Color couleurbrick)
{
    formebrick.setPosition(sf::Vector2f(x,y));
    formebrick.setSize(sf::Vector2f(largeur,hauteur));
    formebrick.setFillColor(couleurbrick);
}

Bricks::Bricks(float x,float y,float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick)
{
    this->pv=pv;
    this->scorebrick=scorebrick;
    formebrick.setPosition(sf::Vector2f(x,y));
    formebrick.setSize(sf::Vector2f(largeur,hauteur));
    formebrick.setFillColor(couleurbrick);
}
Bricks::Bricks(float x,float y,float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick,std::string linktexture)
{
    this->pv=pv;
    this->scorebrick=scorebrick;
    formebrick.setPosition(sf::Vector2f(x,y));
    formebrick.setSize(sf::Vector2f(largeur,hauteur));
    formebrick.setFillColor(couleurbrick);
    formebrick.setFillColor(couleurbrick);
    texturebrick.loadFromFile(linktexture);
    spritebrick.setTexture(texturebrick);
}

void Bricks::couleurfctpv()
{
    int r= -((pv-10)*(pv-10))*10+250;
    int g=-((pv-5)*(pv-5))*10+250;
    int b=-(pv)*(pv)*10+250;
    if (r<0)
    {
        r=0;
    }
    if (b<0)
    {
        b=0;
    }
    if (g<0)
    {
        g=0;
    }
//   std::cout << r <<":"<< g <<":"<< b << std::endl;
    formebrick.setFillColor(sf::Color(r,g,b));



}


