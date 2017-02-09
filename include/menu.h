#ifndef MENU_H
#define MENU_H

#include "Juego.h"
#include <SFML/Audio.hpp>


class menu
{
    public:
        menu(sf::RenderWindow& w);
        void loop();
    protected:

    private:
        sf::RenderWindow& w;
        sf::Texture t;
        sf::Text t3;
        sf::Text t2;
        sf::Text t1;
        sf::Font f;
};


#endif // MENU_H
