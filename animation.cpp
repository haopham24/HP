#include "animation.h"

animation::animation() {

}
animation::animation(int countImg,string filename,float deltaTime) {
    for(int i=1;i<=countImg;i++){
        Texture tmpImg;
        tmpImg.loadFromFile("../"+filename+to_string(i)+".png");
        listTexture.push_back(tmpImg);

    }
    this->deltaTime=deltaTime;
}
void animation::update() {
    currentFrame+=deltaTime;
    if(currentFrame>listTexture.size()){
        currentFrame=0;
    }
}

void animation::setTexture(Sprite &s) {
    s.setTexture(listTexture[currentFrame]);
    s.setTextureRect(IntRect(0,0,listTexture[currentFrame].getSize().x,listTexture[currentFrame].getSize().y));
    s.setOrigin((Vector2f)listTexture[currentFrame].getSize()*0.5f);
}