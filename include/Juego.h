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
#include "VIDA.h"
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
        AST* colision_con_asteroide(sf::FloatRect);
        AST* colision_con_nave(sf::FloatRect);
        VIDA* salva_nave(sf::FloatRect);

    protected:
        int nivel;

    private:
        int puntaje;
        int contador;
        void pintar(sf::RenderWindow&);
        Nave nave;
        Puntaje p;
        Leer l;
        Game_Over game;
        sf::RenderWindow& window;
        sf::Font fuente;
        list<Bala*> balas;
        list<AST*> AST_V;
        list<VIDA*> VIDA_V;
        typedef list<Bala*>::iterator ibalas;
        typedef list <AST*>::iterator iast;
        typedef list <VIDA*>::iterator ivid;
};

#endif // JUEGO_H
