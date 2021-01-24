#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#pragma once
#include "entity.h"
#include "animation.h"

class player : public entity{
private:
    Sprite s;

    animation currentAnimation;

public:
    player(){

        currentAnimation=animation(10,"carrot_run_0",0.6f);
        currentAnimation.setTexture(s);
        this->body.setSize((Vector2f)s.getTexture()->getSize()-Vector2f(60,50));
        this->body.setOrigin((Vector2f)s.getTexture()->getSize()*0.5f);
        s.setPosition(Vector2f(450,500));
    }
    void update(){
        entity ::update();
        currentAnimation.update();
        currentAnimation.setTexture(s);
        Input();
        Move(this->velocity *0.8f);

    }



    void Input(){
        if(s.getPosition().y>=500){
            this->velocity.y=0;
        }

        if(Keyboard::isKeyPressed(sf::Keyboard::Space )&& s.getPosition().y>=0 ){

            this->velocity.y=-25;

        }


    }

    void Move(Vector2f velocity){
        s.move(velocity);
        this->body.setPosition(s.getPosition());
    }

    void draw(RenderWindow& rd){
        entity::draw(rd);
        rd.draw(s);
    }

};


#endif //MAIN_CPP_PLAYER_H
