#include "../include/Bricks.h"

Bricks::Bricks()
{
}
Bricks::Bricks(float x,float y ,float largeur,float hauteur){
this->x=x;
this->y=y;
this->largeur=largeur;
this->hauteur=hauteur;
position=sf::Vector2f(x,y);
dimension=sf::Vector2f(largeur,hauteur);
formebrick.setPosition(position);
formebrick.setSize(dimension);
}

Bricks::Bricks(float x,float y ,float largeur,float hauteur,sf::Color couleurbrick){
this->x=x;
this->y=y;
this->largeur=largeur;
this->hauteur=hauteur;
this->couleurbrick=couleurbrick;
position=sf::Vector2f(x,y);
dimension=sf::Vector2f(largeur,hauteur);
formebrick.setPosition(position);
formebrick.setSize(dimension);
formebrick.setFillColor(couleurbrick);
}

Bricks::Bricks(float x,float y ,float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick){
this->x=x;
this->y=y;
this->largeur=largeur;
this->hauteur=hauteur;
this->pv=pv;
this->scorebrick=scorebrick;
position=sf::Vector2f(x,y);
dimension=sf::Vector2f(largeur,hauteur);
formebrick.setPosition(position);
formebrick.setSize(dimension);
formebrick.setFillColor(couleurbrick);
}
Bricks::Bricks(float x,float y ,float largeur,float hauteur,int pv,int scorebrick,sf::Color couleurbrick,std::string linktexture){
this->x=x;
this->y=y;
this->largeur=largeur;
this->hauteur=hauteur;
this->pv=pv;
this->scorebrick=scorebrick;
position=sf::Vector2f(x,y);
dimension=sf::Vector2f(largeur,hauteur);
formebrick.setPosition(position);
formebrick.setSize(dimension);
formebrick.setFillColor(couleurbrick);
texturebrick.loadFromFile(linktexture);
spritebrick.setTexture(texturebrick);
}
