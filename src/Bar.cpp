#include "../include/Bar.h"

Bar::Bar()
{

}
Bar::Bar(float x , float y, float hauteur, float largeur){
this->x=x;
this->y=y;
this->hauteur=hauteur;
this->hauteur=hauteur;
position=sf::Vector2f(x,y);
dimension=sf::Vector2f(hauteur,largeur);
formebar.setPosition(position);
formebar.setSize(dimension);


}
Bar::Bar(float x , float y, float hauteur, float largeur,sf::Color couleur){
this->x=x;
this->y=y;
this->hauteur=hauteur;
this->hauteur=hauteur;
this->couleur=couleur;
position=sf::Vector2f(x,y);
dimension=sf::Vector2f(hauteur,largeur);
formebar.setPosition(position);
formebar.setSize(dimension);
formebar.setFillColor(couleur);

}
Bar::Bar(float x , float y, float hauteur, float largeur,std::string linktexture){

this->x=x;
this->y=y;
this->hauteur=hauteur;
this->hauteur=hauteur;
position=sf::Vector2f(x,y);
dimension=sf::Vector2f(hauteur,largeur);
formebar.setPosition(position);
formebar.setSize(dimension);
texturebar.loadFromFile(linktexture);
spritebar.setTexture(texturebar);
}
