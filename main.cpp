#include <SFML/Graphics.hpp>
#include "animation.h"
#include "entity.h"
#include "player.h"
#include "monster.h"
#include "background.h"
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 700), "HP");
    window.setFramerateLimit(40);
    entity* player_ =new player();

    background background_(&window,6);

    monster monster1(&window,9,1800,520);
    monster monster2(&window,9,1100,520);


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;

                default:
                    break;

            }

        }



        if(monster1.isCollision(player_) || monster2.isCollision(player_)){
            Texture tmp;
            tmp.loadFromFile("../GameOver.png");
            Sprite s;
            s.setTexture(tmp);
            s.setPosition(Vector2f(480,100));

            window.clear(sf::Color::Black);
            background_.draw(window);
            player_->draw(window);
            monster1.draw();
            monster2.draw();
            window.draw(s);
            window.display();
        }
        else{
            monster1.update();
            monster2.update();
            player_->update();
            background_.update();

            window.clear(sf::Color::Black);
            background_.draw(window);
            player_->draw(window);
            monster1.draw();
            monster2.draw();

            window.display();
        }

    }

    return 0;
}