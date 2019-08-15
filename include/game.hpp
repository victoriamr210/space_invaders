#pragma once
#include "ship.hpp"
#include "things.hpp"
#include "bullet.hpp"
#include "aliens.hpp"
#include <vector>
#include <iterator>
#include <SFML/Graphics.hpp>


using namespace std;

// enum dir {UP, DOWN, LEFT, RIGHT};

class game{

public:
  sf::RenderWindow window;
  sf::RectangleShape r;
  // vector<bullets> pew;
  ship falcon;
  bullet pew;
  aliens bois;
  bool fired=false;

  direction dir=STOP;

  // sf::RectangleShape snake(sf::Vector2f(120.f, 50.f));
  // sf::RectangleShape food(sf::Vector2f(120.f, 50.f));

  game(){
    this->window.create(sf::VideoMode(600, 600), "game");
    // r.setSize(sf::Vector2f(32,25));
    // r.setPosition(70,220);
    // r.setFillColor(sf::Color::Blue);

  }

  void drawGame(void){
    window.draw(falcon.sprite);
    window.draw(r);
    // if(fired) window.draw(pew.b);
    for(int i=0; i<pew.bb.size(); i++)
      window.draw(pew.bb[i]);

    for(int i=0; i<10; i++)
      window.draw(bois.a[i]);

    for(int i=0; i<10; i++)
      window.draw(bois.b[i]);

    for(int i=0; i<10; i++)
      window.draw(bois.c[i]);

     for(int i=0; i<10; i++)
      window.draw(bois.d[i]);
  }

  void input(sf::Event event){
    switch(event.key.code){
      case sf::Keyboard::Left:	
        dir=LEFT;
        break;
      
      case sf::Keyboard::Right:
        dir=RIGHT;
        break;
      
      case sf::Keyboard::Space:
        new_bullet();
        break;
        
    }
    falcon.move(dir);

  }
  
  void new_bullet(void){

    // bullet aux;
    sf::Vector2f pos;
    // pos=falcon.pos();
    int x = falcon.pos().x;
    int y = falcon.pos().y;
    pos.x=x+21;
    pos.y=y-10;
    // aux.setPosition(sf::Vector2f(x+21,y-10));
    pew.push(pos);
    // window.draw(pew.b);
    fired=true;

  }

  void killed(void){
    std::vector<sf::RectangleShape>::iterator i;
    std::vector<sf::Sprite>::iterator j;

    // for(i=)
  }


  void gameloop(void){

    sf::Clock clock;
    window.setFramerateLimit(16);

    while (window.isOpen()){
      // check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
      while (window.pollEvent(event)){
    

        if (event.type == sf::Event::Closed)
          window.close();
        
        if(event.type == sf::Event::KeyPressed)
          input(event);
      }

      // clear the window with black color
      window.clear(sf::Color::Black);
      sf::Time time = clock.getElapsedTime();

      pew.check();
      killed();

      if(time.asSeconds() > 0.1){
					pew.move();
					clock.restart();
				}

      // clock.getElapsedTime();

      
      drawGame();

      // end the current frame
      window.display();
    }
  }
};

