#ifndef GAME_OVER_H
#define GAME_OVER_H
#include <SFML/Graphics.hpp>
#include "Leer.h"
#include "Puntaje.h"
#include "Nave.h"
#include "ListadoPuntajes.h"



using namespace std;
class menu;
class Juego;
class ListadoPuntajes;
class Game_Over
{
    public:
        Game_Over(sf::RenderWindow& w);
        void game_o(bool ganar,int pu);


    protected:

    private:
        Nave nave;
        //Puntaje p;
        Leer lee;
        ListadoPuntajes lista;
        bool ganar;
        sf::RenderWindow& w;
        sf::Texture fondo;
        sf::Font fuente;
        sf::Text t1;
        sf::Text t;
};

#endif // GAME_OVER_H
