#include "../include/Bar.h"

Bar::Bar()
{

}
Bar::Bar(float x, float y, float largeur, float hauteur)
{
    formebar.setPosition(sf::Vector2f(x,y));
    formebar.setSize(sf::Vector2f(largeur,hauteur));
    formebar.setOrigin(sf::Vector2f(largeur/2,hauteur/2));



}
Bar::Bar(float x, float y, float largeur, float hauteur,sf::Color couleur)
{
    formebar.setPosition(sf::Vector2f(x,y));
    formebar.setSize(sf::Vector2f(largeur,hauteur));
    formebar.setFillColor(couleur);
    formebar.setOrigin(sf::Vector2f(largeur/2,hauteur/2));

}
Bar::Bar(float x, float y, float largeur, float hauteur,std::string linktexture)
{

    formebar.setPosition(sf::Vector2f(x,y));
    formebar.setSize(sf::Vector2f(largeur,hauteur));
    texturebar.loadFromFile(linktexture);
    spritebar.setTexture(texturebar);
    formebar.setOrigin(sf::Vector2f(largeur/2,hauteur/2));
}

void Bar::deplacement(bool droite, bool gauche)
{
    if (droite)
    {
        formebar.move(vitesse,0);

    }

    if (gauche)
    {
        formebar.move(-vitesse,0);
    }



}
