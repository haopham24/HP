#ifndef MAIN_CPP_BACKGROUND_H
#define MAIN_CPP_BACKGROUND_H
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


class background {
private:
    Sprite background1,background2,moon,logo,ground;
    Texture t1,t2,t3,t4;
    float speed;
    RenderWindow *window;
public:
    background(RenderWindow *window,float speed){
        this->window = window;
        this->speed=speed;
        t1.loadFromFile("../background.png");
        t2.loadFromFile("../ground.png");
        t3.loadFromFile("../moon.png");
        t4.loadFromFile("../logo.png");

        background1.setTexture(t1);
        background1.setScale(Vector2f(1.2,1.2));

        background2.setTexture(t1);
        background2.setScale(Vector2f(1.2,1.2));
        background2.setPosition(Vector2f(1200,0));

        ground.setTexture(t2);
        ground.setPosition(sf::Vector2f(0,600));

        moon.setTexture(t3);
        moon.setPosition(Vector2f(200,15));
        moon.setScale(Vector2f(0.45,0.45));

        logo.setTexture(t4);
        logo.setScale(Vector2f(0.05,0.05));
        logo.setPosition(Vector2f(1100,0));

    }

    void draw(RenderWindow& rd){
        rd.draw(moon);
        rd.draw(background1);
        rd.draw(background2);
        rd.draw(ground);
        rd.draw(logo);
    }

    void update(){
        background1.move(Vector2f(-(speed),0));
        background2.move(Vector2f(-(speed),0));
        if(background1.getPosition().x==-1200){
            background1.setPosition(Vector2f(0,0));
            background2.setPosition(Vector2f(1200,0));
        }
    }



};


#endif //MAIN_CPP_BACKGROUND_H
