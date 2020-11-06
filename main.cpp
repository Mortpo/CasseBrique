#include "include/Partie.h"
#include <iostream>
#include <SFML/Graphics.hpp>



int main(int argc, char ** argv)
{

    sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "BRIQUARMAGEDDON",sf::Style::Close|sf::Style::Titlebar);
    renderWindow.setFramerateLimit(60); // Limite la fenêtre à 60 images par seconde
    sf::Event event;
    int i;
    sf::Clock timer;
    Partie game(renderWindow,timer,5);
    bool menudebut = true;
    bool partieencours = false;
    bool findepartie = false;
    bool gauche=false;
    bool droite=false;
    bool lancementdepartie=false;
    bool triggerfrontmontant=false;

    while(renderWindow.isOpen())
    {
        // Check for all the events that occured since the last frame.
        while (renderWindow.pollEvent(event))
        {
            //Handle events here
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
            }
        }
        if (menudebut==true)
        {
            std::cout <<"menu"<<std::endl;
            game.debutdepartie();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==true && triggerfrontmontant==false)
            {
                menudebut=false;
                lancementdepartie=true;
            }
            triggerfrontmontant=sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        }


        if (lancementdepartie==true)
        {
            game=Partie(renderWindow,timer,300);   //pb
            //game.score=0; //deja dans le constructeur
            //game.vie=3; //deja dans le constructeur
            lancementdepartie=false;
            partieencours=true;
            timer.restart();
            std::cout <<"initialisation fini"<<std::endl;
        }
        else
        {
            if (partieencours==true)
            {
                game.ball.deplacement();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                {
                    game.instancebricks.pop_back();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    droite=true;
                }
                else
                {
                    droite=false;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    gauche=true;
                }
                else
                {
                    gauche=false;
                }
                game.bar.deplacement(droite,gauche);
                game.collision();
                game.affichagePartie();
                game.gui();
                if(game.vie<=0 || game.instancebricks.size()<=0 )
                {
                    findepartie=true;
                    partieencours=false;
                }
            }
        }

        if(findepartie==true)
        {
            game.findepartie();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==true&&triggerfrontmontant==false)
            {
                menudebut=true;
                lancementdepartie=false;
                findepartie=false;
            }
            triggerfrontmontant=sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        }

        renderWindow.display();
        renderWindow.clear();


    }
    return 0;
}
