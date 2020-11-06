#ifndef PARTIE_H
#define PARTIE_H
#include "Bar.h"
#include "Ball.h"
#include "Bricks.h"
#include <iostream>



class Partie
{
public:

    int lastcolisionbar;
    int score;
    int vie;
    int tempsfin;
    sf::RenderWindow *jeu;
    bool prisedutemps;
    sf::Time tempspasse;
    sf::Time colisiontimer ;
    sf::FloatRect bordhaut;
    sf::FloatRect bordbas;
    sf::FloatRect borddroite;
    sf::FloatRect bordgauche;
    sf::Clock *timer;
    sf::Font font;
    Bar bar;
    Ball ball;
    std::vector<Bricks> instancebricks;

    void spawnBar();
    void spawnBall();
    void creationbrick();
    void collision();
    void affichetemps();
    void affichescore();
    void findepartie();
    void gui();
    void affichagePartie();
    void debutdepartie();

    Partie(sf::RenderWindow &gameWindow, sf::Clock &gametimer,int nbbrique);
};

#endif // PARTIE_H
