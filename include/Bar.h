#ifndef BAR_H
#define BAR_H
#include <SFML/Graphics.hpp>

class Bar
{
    public:
        float x,y;
        float hauteur,largeur;

        sf::Vector2f position;
        sf::Vector2f dimension;
        sf::Vector2f vitesse;
        sf::Texture texturebar;
        sf::FloatRect hitbox;
        sf::RectangleShape formebar;
        sf::Vector2f spawnpointball;
        sf::Color couleur;
        sf::Sprite spritebar;

Bar();
Bar(float x , float y, float hauteur, float largeur);
Bar(float x , float y, float hauteur, float largeur,sf::Color couleur);
Bar(float x , float y, float hauteur, float largeur,std::string linktexture);
};

#endif // BAR_H
