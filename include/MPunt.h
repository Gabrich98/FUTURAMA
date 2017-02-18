#ifndef MPUNT_H
#define MPUNT_H

#include "Juego.h"
#include "Leer.h"
#include "Puntaje.h"
#include "menu.h"


class MPunt
{
    public:
        MPunt(sf::RenderWindow& w);
        void loop();

    protected:

    private:
        Puntaje p;
        Leer l;
        sf::RenderWindow& w;
        sf::Texture t;
        sf::Text t1;
        sf::Font f;
        sf::Text punt;
        sf::Text punt1;
};

#endif // MPUNT_H
