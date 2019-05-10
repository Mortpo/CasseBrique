#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>


class Ball
{
    public:
// attributs
        float x, y, spx, spy;
        float hauteur, largeur, rayon;
        int red, green, blue, alpha;
        int ptvie;
        static int nbball;
        float movex, movey;



        sf::Vector2f position;
        sf::Vector2f dimension = sf::Vector2f(largeur, hauteur);
        sf::Vector2f spawn = sf::Vector2f(spx, spy); //point de spawn de la balle
        sf::Sprite sball;   //sprite de la balle
        sf::Texture tball; //texture de la balle
        sf::CircleShape fball; //cercle
        sf::FloatRect hitbox = sf::FloatRect(position, dimension); //hitbox (rectangle)
        sf::Color colball = sf::Color(red, green, blue, alpha); //couleur
        Deplacement( float movex,float  movey);

// constructeur
    Ball();
    Ball(float x, float y, float rayon);
    Ball(float x, float y, float rayon,sf::Color couleur);
    Ball(float x ,float y ,float rayon, std::string linktexture);


};

#endif // BALL_H
