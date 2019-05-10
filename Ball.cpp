#include "../include/Ball.h"



Ball::Deplacement(float movex, float movey){  // peut etre initié ici
this-> movex=movex;
this-> movey=movey;
fball.move(movex, movey);
}






Ball::Ball()
{
    //ctor

}

Ball::Ball(float x, float y, float rayon){

this-> x=x;
this-> y=x;
this-> rayon=rayon;
position = sf::Vector2f(x, y);
fball.setPosition(position);
fball.setRadius(rayon);

}

Ball::Ball(float x, float y, float rayon,sf::Color couleur){

this-> x;
this-> y;
this-> rayon;
this->colball=couleur;
position = sf::Vector2f(x, y);
fball.setPosition(position);
fball.setRadius(rayon);
fball.setFillColor(colball);
}

Ball::Ball(float x ,float y ,float rayon, std::string linktexture){

this-> x;
this-> y;
this-> rayon;
position = sf::Vector2f(x, y);
fball.setPosition(position);
fball.setRadius(rayon);
tball.loadFromFile(linktexture);
sball.setTexture(tball);

}
