#ifndef BRICKS_H
#define BRICKS_H
#include <SFML/Graphics.hpp>

class Bricks
{
    public:
        float x,y,largeur,hauteur;
        int pv , scorebrick;
        sf::Vector2f position;
        sf::Vector2f dimension;
        sf::FloatRect hitbox;
        sf::RectangleShape formebrick;
        sf::Texture texturebrick;
        sf::Sprite spritebrick;
        sf::Color couleurbrick;


        Bricks();
        Bricks(float x,float y ,float largeur,float hauteur);
        Bricks(float x,float y ,float largeur,float hauteur,sf::Color couleurbrick);
        Bricks(float x,float y, float largeur,float hauteur,int pv);
        Bricks(float x,float y, float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick);
        Bricks(float x,float y ,float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick,std::string linktexture);
};

#endif // BRICKS_H
