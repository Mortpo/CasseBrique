
#include "include/Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/Bar.h"

int main() {
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "OSEF");

 sf::Event event;
sf::Color coul(0,0,0,255);
 Ball ball(10, 20, 50);

while(renderWindow.isOpen()){
    // Check for all the events that occured since the last frame.
    while (renderWindow.pollEvent(event)){
      //Handle events here
      if (event.type == sf::Event::Closed)
        renderWindow.close();


    }
    renderWindow.clear();
    renderWindow.draw(ball.fball);
    renderWindow.display();
  }
  return 0;
}






