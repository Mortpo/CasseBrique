#ifndef BAR_H
#define BAR_H
#include <SFML/Graphics.hpp>

class Bar
{
public:
    sf::Texture texturebar;
    sf::RectangleShape formebar;
    sf::Vector2f spawnpointball;
    sf::Sprite spritebar;
    float vitesse;

    void deplacement(bool droite, bool gauche);

    Bar();
    Bar(float x, float y, float largeur, float hauteur);
    Bar(float x, float y, float largeur, float hauteur,sf::Color couleur);
    Bar(float x, float y, float largeur, float hauteur,std::string linktexture);
};

#endif // BAR_H
