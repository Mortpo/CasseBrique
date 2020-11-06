#include "../include/Partie.h"
#include <time.h>
#include <random>
#include <math.h>

void Partie::spawnBar()
{
    float x =  (jeu->getSize().x)/2;
    float y = (jeu->getSize().y) - 40;
    bar.formebar.setPosition(x, y);

}

void Partie::spawnBall()
{
    float x = bar.formebar.getPosition().x;
    float y = bar.formebar.getPosition().y - 200;

    ball.formeball.setPosition(x, y);

}

void Partie::collision()
{
    sf::FloatRect intersection;
    int i;
    float grad;
    if(bar.formebar.getGlobalBounds().intersects(bordgauche))
    {
        bar.formebar.setPosition(60,bar.formebar.getPosition().y);
    }

    if(bar.formebar.getGlobalBounds().intersects(borddroite))
    {
        bar.formebar.setPosition(jeu->getSize().x-60,bar.formebar.getPosition().y);
    }
    if(ball.formeball.getGlobalBounds().intersects(bar.formebar.getGlobalBounds(),intersection))
    {
        colisiontimer = timer->getElapsedTime();


        if ((colisiontimer.asMilliseconds()-lastcolisionbar) >80)
        {
            grad = (intersection.left +intersection.width/2) - (bar.formebar.getGlobalBounds().left+bar.formebar.getGlobalBounds().width/2) ;

            ball.movex = ball.movex+(grad*grad*grad/45000)+atan(grad)/5;
            ball.movey = -1*(ball.movey);
            if (ball.movex>7)
                ball.movex=7;
            if (ball.movex<-7)
                ball.movex=-7;

        }

        lastcolisionbar = colisiontimer.asMilliseconds();
    }



    if(ball.formeball.getGlobalBounds().intersects(bordhaut))
    {
        ball.movey = - ball.movey;


    }

    if(ball.formeball.getGlobalBounds().intersects(bordbas))
    {


        vie--;
        if(vie>0)
        {
            spawnBall();
            ball.movex = 0;
            ball.movey = 5;
        }
        else
        {
            std::cout<<"fin de la partie"<< std::endl;
        }
    }

    if(ball.formeball.getGlobalBounds().intersects(bordgauche))
    {
        ball.movex = - ball.movex;

    }
    if(ball.formeball.getGlobalBounds().intersects(borddroite))
    {
        ball.movex = - ball.movex;

    }


    for(i=0; i<instancebricks.size(); i++)
    {
        if(ball.formeball.getGlobalBounds().intersects(instancebricks[i].formebrick.getGlobalBounds(),intersection))
        {
            if(intersection.height>intersection.width)
            {
                ball.movex= -1*ball.movex;
                ball.movey= 1*ball.movey;
            }
            else
            {
                ball.movex= 1*ball.movex;
                ball.movey= -1*ball.movey;
            }

            score++;

            instancebricks[i].pv--;
            if(instancebricks[i].pv <= 0)
            {
                instancebricks.erase(instancebricks.begin()+i);
            }
            else
            {
                instancebricks[i].couleurfctpv();
            }

        }

    }
}

void Partie::creationbrick()
{
    int i, j;
    srand(time(NULL));
    std::default_random_engine gen (rand());
    // std::random_device(std::random_device{}()) gen;
    int positionbrickx;
    int positionbricky;
    int taillefenetrex = jeu->getSize().x - 60;
    int taillefenetrey = jeu->getSize().y/2;
    std::uniform_int_distribution<int> randx{10, taillefenetrex};
    std::uniform_int_distribution<int> randy{50, taillefenetrey};


    for (i=0; i<instancebricks.size(); i++)
    {

        positionbrickx = randx(gen);
        positionbricky = randy(gen);
        instancebricks[i].formebrick.setPosition(positionbrickx, positionbricky);

        instancebricks[i].pv=(rand()%10)+1;
        instancebricks[i].couleurfctpv();
        instancebricks[i].formebrick.setOutlineColor(sf::Color(255,255,255,0));
        instancebricks[i].formebrick.setOutlineThickness(1);



    }

//possibilité de changer genre check collision a la creation
    for(i=instancebricks.size()-1; i>=0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(instancebricks[j].formebrick.getGlobalBounds().intersects(instancebricks[i].formebrick.getGlobalBounds()))
            {
                instancebricks.erase(instancebricks.begin()+j);
                j=i;

            }

        }
    }

}

/*void Partie::affichetemps(){ //FONCTION vielle dans gui
      sf::Text horloge;
    horloge.setFont(font);
    horloge.setCharacterSize(30);
    horloge.setFillColor(sf::Color::White);
    sf::Time tempspasse = timer->getElapsedTime();
    horloge.setString("Temps : "+std::to_string(static_cast<int>(tempspasse.asSeconds())));
    horloge.setPosition(20,5);
    jeu->draw(horloge);

}

void Partie::affichescore(){ //fonction vielle dans gui
    sf::Text pointscore;
    pointscore.setFont(font);
    pointscore.setCharacterSize(30);
    pointscore.setFillColor(sf::Color::White);
    pointscore.setString("Score: "+std::to_string(static_cast<int>(score)));
    pointscore.setPosition(400,5);
    jeu->draw(pointscore);
}
*/
void Partie::gui()
{
    sf::Text horloge;
    sf::Text pointscore;
    horloge.setFont(font);
    pointscore.setFont(font);
    horloge.setCharacterSize(30);
    pointscore.setCharacterSize(30);
    horloge.setFillColor(sf::Color::White);
    pointscore.setFillColor(sf::Color::White);
    tempspasse = timer->getElapsedTime();
    horloge.setString("Temps : "+std::to_string(static_cast<int>(tempspasse.asSeconds())));
    pointscore.setString("Score: "+std::to_string(static_cast<int>(score)));
    horloge.setPosition(850,5);
    pointscore.setPosition(200,5);
    jeu->draw(horloge);
    jeu->draw(pointscore);

}

void Partie::affichagePartie()
{
    for(int i=0; i<instancebricks.size(); i++)
    {
        jeu->draw(instancebricks[i].formebrick);

    }

    jeu->draw(bar.formebar);
    jeu->draw(ball.formeball);


}


void Partie::debutdepartie()
{
    sf::Text titre;
    sf::Text messagedebut;
    titre.setFont(font);
    titre.setCharacterSize(100);
    titre.setFillColor(sf::Color::Red);
    titre.setPosition(45,160);
    titre.setStyle(sf::Text::Bold);
    titre.setString("BRIQUARMAGEDDON");
    messagedebut.setFont(font);
    messagedebut.setCharacterSize(35);
    messagedebut.setFillColor(sf::Color::Yellow);
    messagedebut.setPosition(125,600);
    messagedebut.setString("Appuyez sur la touche espace pour commencer la partie ");
    jeu->draw(titre);
    jeu->draw(messagedebut);
}



void Partie::findepartie()
{
    sf::Text horloge;
    sf::Text pointscore;
    sf::Text fin;
    sf::Text messagefin;



    horloge.setFont(font);
    pointscore.setFont(font);

    horloge.setCharacterSize(50);
    pointscore.setCharacterSize(50);

    horloge.setFillColor(sf::Color::Green);
    pointscore.setFillColor(sf::Color::Green);
    if(prisedutemps==true)
    {
        tempspasse = timer->getElapsedTime();
        tempsfin = tempspasse.asSeconds();
        prisedutemps=false;

    }
    horloge.setString("Temps : "+std::to_string(static_cast<int>(tempsfin)));
    pointscore.setString("Score: "+std::to_string(static_cast<int>(score)));

    horloge.setPosition(700,60);
    pointscore.setPosition(200,60);

    fin.setFont(font);
    fin.setCharacterSize(80);
    fin.setFillColor(sf::Color::Red);
    fin.setPosition(450,300);
    fin.setStyle(sf::Text::Bold);

    messagefin.setFont(font);
    messagefin.setCharacterSize(26);
    messagefin.setFillColor(sf::Color::Yellow);
    messagefin.setPosition(260,620);
    messagefin.setString("Pour retourner au menu appuyez sur la touche espace");

    if(vie==0)
    {
        fin.setString("PERDU");
    }
    else
    {
        fin.setString("GAGNE");
    }

    jeu->draw(horloge);
    jeu->draw(pointscore);
    jeu->draw(fin);
    jeu->draw(messagefin);



}



Partie::Partie(sf::RenderWindow &gameWindow, sf::Clock &gametimer,int nbbrique)
{
    font.loadFromFile("Xeliard.ttf");
    prisedutemps=true;
    timer = &gametimer;
    jeu = &gameWindow;
    score = 0;
    vie = 3;
    lastcolisionbar=colisiontimer.asMilliseconds();
    instancebricks = std::vector<Bricks>(nbbrique);
    for(int i=0; i<instancebricks.size(); i++)
    {

        instancebricks[i].formebrick.setSize(sf::Vector2f(50, 25));

    }
    creationbrick();
    bar.formebar.setSize(sf::Vector2f(120, 10));
    bar.formebar.setOrigin(60, 5);
    bar.formebar.setFillColor(sf::Color::Cyan);
    spawnBar();
    ball.formeball.setRadius(15);
    ball.formeball.setOrigin(15, 15);
    ball.formeball.setFillColor(sf::Color::Magenta);
    spawnBall();
    ball.movex = 0;
    ball.movey = 5;
    bar.vitesse = 8;
    bordbas = sf::FloatRect(sf::Vector2f(0, jeu->getSize().y), sf::Vector2f(jeu->getSize().x, 20));
    borddroite = sf::FloatRect(sf::Vector2f(jeu->getSize().x, 0), sf::Vector2f(20, jeu->getSize().y));
    bordgauche = sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f( -10, jeu->getSize().y));
    bordhaut = sf::FloatRect(sf::Vector2f(0, -20), sf::Vector2f(jeu->getSize().x, 20));

}
