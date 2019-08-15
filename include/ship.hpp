#pragma once
#include <iostream>
#include "things.hpp"
#include <SFML/Graphics.hpp>


class ship{

  public:
    sf::Sprite sprite;
    sf::Texture texture;

    ship(){
      if (!texture.loadFromFile("../media/ship2.png"))
        std::cout << "fail\n";

      sprite.setTexture(texture);
      sprite.setPosition(sf::Vector2f(270, 530));
      sprite.scale(sf::Vector2f(0.15f, 0.15f)); // factor relative to the current scale
    }

    void move(direction& dir){
      
      switch(dir){
        case LEFT:
          sprite.move(-10,0);
          break;
      
        case RIGHT:
          sprite.move(10,0);
          break;

        default:
          break;
      }

      dir=STOP;
    }

    const sf::Vector2f & pos(void){
      return sprite.getPosition();
    }
};