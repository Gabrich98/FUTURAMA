#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "AST.h"
#include "Bala.h"
#include "Puntaje.h"
#include "Leer.h"
#include "Game_Over.h"
#include "menu.h"
#include "Caja.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include <ListadoPuntajes.h>
=======
>>>>>>> origin/master
=======
>>>>>>> origin/master
#include <vector>
#include <list>
#include "Entidad.h"


using namespace std;



class Juego
{
    public:
        Juego(sf::RenderWindow&);
        void loop();
        void disparar(sf::Vector2f);
        bool vivo;
        void pintar(sf::RenderWindow&);
        AST* colision_con_asteroide(sf::FloatRect);
        AST* colision_con_nave(sf::FloatRect);
        Caja* ingresa_nave(sf::FloatRect);

    protected:

    private:
        int puntaje;
        int contador;
        Nave nave;
        Puntaje p;
        Leer lee;
        Game_Over game;
        sf::RenderWindow& window;
        sf::Font fuente;
        list<Bala*> balas;
        list<AST*> AST_V;
        list<Caja*> CAJA_C;
        typedef list<Bala*>::iterator ibalas;
        typedef list <AST*>::iterator iast;
        typedef list <Caja*>::iterator icaj;
};

#endif // JUEGO_H
