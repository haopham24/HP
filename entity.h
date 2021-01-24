#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#ifndef MAIN_CPP_ENTITY_H
#define MAIN_CPP_ENTITY_H
using namespace sf;
using namespace std;


class entity {
protected:
    Vector2f size;

    float mass;
    float gravity=9.8f;
    Vector2f velocity;
    RectangleShape body;

public:
    entity(){
        body.setFillColor(Color(0,0,0,0));
        body.setOutlineColor(Color::Transparent);
        body.setOutlineThickness(1);

        mass=0;
        velocity.x=velocity.y=0;
    }
    void applyGravity(){
        velocity.y+=gravity * 0.2f;
    }

    virtual void update(){
        applyGravity();
        if(body.getPosition().y>500)
            velocity.y=0;
    }
    virtual void draw(RenderWindow& rd){
        rd.draw(body);
    }
    void resize(Vector2f size){
        body.setSize(size);
    }
    void setPosition(Vector2f position){
        body.setPosition(position);
    }

    virtual bool isCollision(entity*other)
    {

        if(this->body.getGlobalBounds().intersects(other->body.getGlobalBounds())){

            return true;
        }

        return false;
    }
    RectangleShape getBody(){
        return body;
    }

};


#endif //MAIN_CPP_ENTITY_H
