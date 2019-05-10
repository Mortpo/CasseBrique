#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>


class Ball
{
    public:
// attributs
        float x, y;
        float hauteur, largeur, rayon;
        int red, green, blue, alpha;
        int ptvie;
        static int nbball;


        sf::Vector2f position;
        sf::Vector2f dimension;
        sf::Sprite sball;   //sprite de la balle
        sf::Texture tball; //texture de la balle
        sf::CircleShape fball; //cercle
        sf::FloatRect hitbox; //hitbox (rectangle)
        sf::Color colball; //couleur

// constructeur
    Ball();
    Ball(float x, float y, float rayon);
    Ball(float x, float y, float rayon,sf::Color couleur);
    Ball(float x ,float y ,float rayon, std::string linktexture);


};

#endif // BALL_H
