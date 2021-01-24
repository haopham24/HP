#ifndef MAIN_CPP_MONSTER_H
#define MAIN_CPP_MONSTER_H
#pragma once
#include "entity.h"


class monster : public entity {
private:
//    RectangleShape monster1;
    float x,y;
    float speed;
    RenderWindow * window;
    Sprite sprite;
    vector<Texture> listTexture;
public:
    monster(RenderWindow *window,float speed,float x,float y){

        this->window=window;
        this->x=x;
        this->y=y;
        this->speed=speed;
        for(int i=1;i<=3;i++){
            Texture tmpImg;
            tmpImg.loadFromFile("../monster"+to_string(i)+".png");
            listTexture.push_back(tmpImg);

        }
        this->sprite.setTexture(listTexture[0]);
        this->sprite.setScale(Vector2f(0.9f,0.9f));
        this->body.setSize((Vector2f)this->sprite.getTexture()->getSize()-Vector2f(40,57));
        this->body.setOrigin((Vector2f)body.getSize()*0.5f);

        body.setFillColor(Color(0,0,0,0));
        body.setOutlineColor(Color::Transparent);
        body.setOutlineThickness(0.1f);
//        this->sprite.setScale(Vector2f(1.5,1.5));
    }
    void update(){
        x-=speed;
        if(x<=-100){
            x=1200;
            int tmp=(rand())%3;
            sprite.setTexture(listTexture[tmp]);
            sprite.setScale(Vector2f(0.9f,0.9f));
        }
    }
    void draw(){
        sprite.setPosition(x,y);
        this->window->draw(this->sprite);
        this->speed=speed;
    }


    bool isCollision(entity* other){
        if(other->getBody().getGlobalBounds().intersects(this->sprite.getGlobalBounds()))
            return true;
        return false;
    }

};


#endif //MAIN_CPP_MONSTER_H
