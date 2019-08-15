#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include "things.hpp"
using namespace std;

#include <SFML/Graphics.hpp>


class aliens{

  public:
    vector<sf::Sprite> a;
    vector<sf::Sprite> b;
    vector<sf::Sprite> c;
    vector<sf::Sprite> d;
    sf::Texture t1;
    sf::Texture t2;
    sf::Texture t3;
    sf::Texture t4;
    int row1=70; int row2; int row3; int row4;

   aliens(void){

    //  if (!t1.loadFromFile("../media/alien3.png"))
    //   std::cout << "fail\n";
    
    // sprite.setTexture(t1);
    // sprite.setPosition(sf::Vector2f(300, 300));
    // sprite.scale(sf::Vector2f(0.07f, 0.07f)); 
     load_texture();

     set_size(a ,size1);
     set_size(b, size1);
     set_size(c,size1);
     set_size(d,size1);

     set_pos(a,0);
     set_pos(b,50);
     set_pos(c,100);
     set_pos(d,150);

  
   }

   void load_texture(void){
    

    if (!t1.loadFromFile("../media/aliens1.png"))
      std::cout << "fail\n";
    if (!t2.loadFromFile("../media/aliens2.png"))
      std::cout << "fail\n";
    if (!t3.loadFromFile("../media/aliens3.png"))
      std::cout << "fail\n";
    if (!t4.loadFromFile("../media/aliens4.png"))
      std::cout << "fail\n";

    set_sprite(a, t1);
    set_sprite(b, t2);
    set_sprite(c, t3);
    set_sprite(d, t4);
   }

   void set_sprite(vector<sf::Sprite>& x, sf::Texture& t){
    sf::Sprite sprite;
    sprite.setTexture(t);
    // sprite.setPosition(sf::Vector2f(50, 100));
    // sprite.scale(sf::Vector2f(sz, sz)); 
    for(int i=0; i<10; i++){
      x.push_back(sprite);
    }
    // x[0]=sprite;
   }

  void set_pos(vector<sf::Sprite>& x, int row){
    // sprite.setPosition(sf::Vector2f(50, 100));
    int aux=0;;
    for(int i=0; i<10; i++){
      x[i].setPosition(sf::Vector2f(70+aux, 70+row)); 
      aux+=45;
    }
  }

  void set_size(vector<sf::Sprite> &x, float sz){
    for(int i=0; i<10; i++){
      x[i].scale(sf::Vector2f(sz, sz)); 
    }
  }

  
};