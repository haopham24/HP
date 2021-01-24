#ifndef MAIN_CPP_GROUND_H
#define MAIN_CPP_GROUND_H
#pragma once
#include "entity.h"

class ground : public entity{
private:
    RectangleShape ground_;
public:
    ground(){
        ground_.setSize(Vector2f (1250,250));
//        ground_.setOrigin(ground_.getSize()*0.5f);
        ground_.setFillColor(Color(94, 57, 22));
        ground_.setPosition(Vector2f(0,600));

        this->body.setPosition(ground_.getPosition());
        this->resize(ground_.getSize());
//        this->body.setOrigin(ground_.getSize()*0.5f);
    }

    void update(){

    }
    void draw(RenderWindow& rd){
        entity::draw(rd);
        rd.draw(ground_);
    }
};


#endif //MAIN_CPP_GROUND_H
