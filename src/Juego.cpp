#include "Juego.h"
#include "Bala.h"
#include "Nave.h"
#include "AST.h"
#include "archivo.h"
#include "Leer.h"
#include "Game_Over.h"
#include "Caja.h"

#include <Puntaje.h>

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>




using namespace std;


Juego::Juego(sf::RenderWindow& window) : window(window),game(window), lee(window)

{
    nivel=1;
    puntaje=3000;
    contador=1;

    for (int i=0; i<10; i++) {
        AST_V.push_back(new AST());
    }
<<<<<<< HEAD
   for (int i=0; i<3; i++) {
=======
      for (int i=0; i<3; i++) {
<<<<<<< HEAD
>>>>>>> origin/master
=======
>>>>>>> origin/master
        CAJA_C.push_back(new Caja());
    }
    fuente.loadFromFile("fr-bold.ttf");

    //Constructor

}





template <typename T>
std::string to_string(T pNumber)
{
    std::ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}



void Juego::disparar(sf::Vector2f v)
{
    balas.push_back(new Bala(v));
}


void Juego::loop()
{
    ifstream fentrada("a_punt.dat", ios::in | ios::binary);

    if(fentrada.is_open())
    {
        p.leer(fentrada);
    }

    sf::Texture bg_t;
    bg_t.loadFromFile("fondo.jpg");

    sf::Sprite bg;
    bg.setPosition(-10,-10);
    bg.setTexture(bg_t);
    bg.setScale(0.26, 0.3);

    sf::Text v;
    v.setColor(sf::Color::Green);
    v.setFont(fuente);
    v.setCharacterSize(30);
    v.setPosition(20,20);;

    sf::Text s;
    s.setColor(sf::Color::Green);
    s.setFont(fuente);
    s.setCharacterSize(25);
    s.setPosition(1200,32);

    sf::Text pun;
    pun.setColor(sf::Color::Red);
    pun.setFont(fuente);
    pun.setCharacterSize(30);
    pun.setPosition(50,730);

    sf::Text pun1;
    pun1.setFont(fuente);
    pun1.setCharacterSize(30);
    pun1.setPosition(10,690);
    pun1.setColor(sf::Color::Red);
    pun1.setString("MEJOR PUNTAJE");

    while (window.isOpen())
    {
        nave.var=false;
<<<<<<< HEAD
=======
        //Setear los textos

        v.setString("CAJAS: "+to_string(nave.mostrar_cajas()));
        //pun.setString("MEJOR PUNTAJE:");
        //pun1.setString(p.GetNombre()+"   "+to_string(p.GetPuntaje()));
>>>>>>> origin/master

        v.setString("CAJAS: "+to_string(nave.mostrar_cajas()));
        pun.setString(p.GetNombre()+"   "+to_string(p.GetPuntaje()));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            nave.procesar_evento(event);

        }

        for(icaj i=CAJA_C.begin(); i!=CAJA_C.end();i++)
        {
            if (!(*i)->vivir())
            {
                delete *i;
                i = CAJA_C.erase(i);
                for(int i=0;i<1;i++)
                {
<<<<<<< HEAD
<<<<<<< HEAD
                    CAJA_C.push_back(new Caja());
=======
                   CAJA_C.push_back(new Caja());
>>>>>>> origin/master
=======
                   CAJA_C.push_back(new Caja());
>>>>>>> origin/master
                }
            }
        }

        for(iast i=AST_V.begin(); i!=AST_V.end();i++)
        {
            if (!(*i)->vivir())
            {
                delete *i;
                i = AST_V.erase(i);
                for(int i=0;i<contador;i++)
                {
                    AST_V.push_back(new AST());
                }
            }
        }
        for(ibalas i=balas.begin(); i!=balas.end();i++)
        {
            if (!(*i)->vivir())
            {
                delete *i;
                i = balas.erase(i);
            }

        }


        nave.accion(*this);

        for(ibalas i=balas.begin(); i!=balas.end();i++)
        {
            (*i)->accion(*this);
        }

        for(iast i=AST_V.begin(); i!=AST_V.end();i++)
        {
            (*i)->accion(*this);
        }
        for(icaj i=CAJA_C.begin(); i!=CAJA_C.end();i++)
        {
            (*i)->accion(*this);
        }


        window.clear(sf::Color::Black);
        window.draw(bg);

<<<<<<< HEAD

        sf::Texture b;
        sf::Texture l;
        sf::Texture f;

        b.loadFromFile("bender.png");
        l.loadFromFile("leela.png");
        f.loadFromFile("fry.png");

        sf::Sprite ben;
        sf::Sprite lee;
        sf::Sprite fry;

        ben.setTexture(b);
        ben.setPosition(1200,600);
        ben.setScale(0.6,0.6);

        lee.setTexture(l);
        lee.setPosition(1050,600);
        lee.setScale(0.52,0.52);


        fry.setTexture(f);
        fry.setPosition(900,580);
        fry.setScale(0.5,0.5);


=======
        sf::Texture sal;
<<<<<<< HEAD
>>>>>>> origin/master
=======
>>>>>>> origin/master
        switch(nave.mostrar_vidas())
        {
            case 3:
               window.draw(ben);
               window.draw(lee);
               window.draw(fry);

                break;
            case 2:
                window.draw(ben);
               window.draw(lee);
                break;
            case 1:
                window.draw(ben);
                break;
        }


        nave.pintar(window);

        for(ibalas i=balas.begin(); i!=balas.end();i++)
        {
            (*i)->pintar(window);
        }
        for(iast i=AST_V.begin(); i!=AST_V.end();i++){
            (*i)->pintar(window);
        }

        for(icaj i=CAJA_C.begin(); i!=CAJA_C.end();i++){
            (*i)->pintar(window);
        }

        if(nave.mostrar_vidas()==0){
            //if(nave.mostrar_cajas()>p.GetPuntaje()){
                return game.game_o(true,nave.mostrar_cajas());

            //}else{
               // return game.game_o(false,nave.mostrar_cajas());
            }


        }
        if(nave.var==true){
            window.clear(sf::Color::Red);
            window.display();

        }

        window.draw(v);
        window.draw(s);
        window.draw(pun);
        window.draw(pun1);
        window.display();

    }
}



AST* Juego::colision_con_asteroide(sf::FloatRect l)
{
    for(iast i=AST_V.begin(); i!=AST_V.end();i++)
        {
            if((*i)->devolver_cuadrado().intersects(l))
            {
                return *i;
            }
        }
        return NULL;
}

AST* Juego::colision_con_nave(sf::FloatRect n)
{
    for(iast i=AST_V.begin();i!=AST_V.end();i++)
        {
            if((*i)->devolver_cuadrado().intersects(n))
            {
                return *i;
            }

        }
    return NULL;
}

Caja* Juego::ingresa_nave(sf::FloatRect n)
{
   for(icaj i=CAJA_C.begin();i!=CAJA_C.end();i++)
    {
        if((*i)->devolver_cuadrado().intersects(n))
        {
            return *i;
        }

    }
    return NULL;

}
