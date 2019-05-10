
#include "include/Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>


int main(int argc, char ** argv) {
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "OSEF",sf::Style::Close|sf::Style::Titlebar);
  renderWindow.setFramerateLimit(60); // Limite la fenêtre à 60 images par seconde

 sf::Event event;

 Ball ball(10, 20, 30);
 Ball ball2(10, 20, 20);


while(renderWindow.isOpen()){
    // Check for all the events that occured since the last frame.
    while (renderWindow.pollEvent(event)){
      //Handle events here
      if (event.type == sf::Event::Closed)
        renderWindow.close();

    }

    ball.fball.move(0.5, 0);
    ball2.fball.move(1, 2);
    std::cout<< ball.fball.getPosition().x<< std::endl;
    renderWindow.clear();
    renderWindow.draw(ball.fball);
    renderWindow.draw(ball2.fball);
    renderWindow.display();

    if ( ball.fball.getGlobalBounds().intersects( ball2.fball.getGlobalBounds())){

        std::cout<< "Collision"<< std::endl;
    }
    else{
     std::cout<< "No Collision"<<std::endl;
    }

  }
  return 0;
}






