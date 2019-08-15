#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "things.hpp"
#include <SFML/Graphics.hpp>

class bullet{

  public:
    std::vector<sf::RectangleShape> bb; //array wih bullets present on screen
    sf::RectangleShape b;

    bullet(){
      // b.setSize(sf::Vector2f(2.f, 6.f));
      // b.setPosition(sf::Vector2f(300,300));
      // b.setFillColor(sf::Color::Green);
    }

    void push(sf::Vector2f a){
      b.setSize(sf::Vector2f(2.f, 6.f));
      b.setFillColor(sf::Color::Green);
      b.setPosition(a);
      bb.push_back(b);
    }

    void move(void){
      for(int i=0; i<bb.size(); i++)
        bb[i].move(0,-50.f);
    }

    void check(void){
      std::vector<sf::RectangleShape>::iterator i;
      for(i=bb.begin(); i!=bb.end(); i++){
        if((*i).getPosition().y < 70){
          bb.erase(i);
          // erase_b(i);
          break;
        }
      }
      // for(int i=0; i<bb.size(); i++){
      //   if(bb[i].getPosition().y == 100)
      //     bb.erase(i);
      // }
    }

    void erase_b(std::vector<sf::RectangleShape>::iterator i){
      bb.erase(i);
    }

};