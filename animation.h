#ifndef MAIN_CPP_ANIMATION_H
#define MAIN_CPP_ANIMATION_H
#pragma once
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
using namespace std;
using  namespace sf;

class animation{
private:
    vector<Texture> listTexture;
    float currentFrame;
    float deltaTime;
public:
    animation();
    animation(int countImg,string filename,float deltaTime);
    void update();
    void setTexture(Sprite &s);

};
#endif //MAIN_CPP_ANIMATION_H
