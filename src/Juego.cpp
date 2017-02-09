#include "Juego.h"
#include "Bala.h"
#include "Nave.h"
#include "AST.h"
#include "archivo.h"
#include "Leer.h"
#include "Game_Over.h"
#include <Puntaje.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>



using namespace std;


Juego::Juego(sf::RenderWindow& window) : window(window),game(window), l(window)

{
    nivel=1;
    puntaje=3000;
    contador=1;

    for (int i=0; i<10; i++) {
        AST_V.push_back(new AST());
    }
      for (int i=0; i<3; i++) {
        VIDA_V.push_back(new VIDA());
    }
    fuente.loadFromFile("letra.ttf");

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
    v.setPosition(32,40);;

    sf::Text s;
    s.setColor(sf::Color::Green);
    s.setFont(fuente);
    s.setCharacterSize(25);
    s.setPosition(1200,32);

    sf::Text pun;
    pun.setColor(sf::Color::Red);
    pun.setFont(fuente);
    pun.setCharacterSize(30);
    pun.setPosition(600,0);

    sf::Text pun1;
    pun1.setFont(fuente);
    pun1.setCharacterSize(30);
    pun1.setPosition(630,40);

    ifstream fentrada("a_punt.dat", ios::in | ios::binary);

    if(fentrada.is_open())
    {
        p.leer(fentrada);
    }
    while (window.isOpen())
    {
        nave.var=false;
        //Setear los textos

        v.setString("VIDAS: "+to_string(nave.mostrar_vidas()));
        s.setString("SALUD");
        //pun.setString("MEJOR PUNTAJE:");
        //pun1.setString(p.GetNombre()+"   "+to_string(p.GetPuntaje()));

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            nave.procesar_evento(event);



            /**/

        }

        for(ivid i=VIDA_V.begin(); i!=VIDA_V.end();i++)
        {
            if (!(*i)->vivir())
            {
                delete *i;
                i = VIDA_V.erase(i);
                for(int i=0;i<1;i++)
                {
                    VIDA_V.push_back(new VIDA());
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
        for(ivid i=VIDA_V.begin(); i!=VIDA_V.end();i++)
        {
            (*i)->accion(*this);
        }

        if((nave.GetPunt()<=puntaje+5)&&(nave.GetPunt()>=puntaje-1))
        {
            if(nivel==2||nivel==3)contador=nivel-1;
            if(nivel==4||nivel==5)contador=nivel/2-1;
            if(nivel==6||nivel==7)contador=nivel/3-2;
            nivel++;
            puntaje=puntaje+4000;
        }

        window.clear(sf::Color::Black);
        window.draw(bg);

        sf::Texture sal;
        switch(nave.mostrar_salud())
        {
            case 100:
                sal.loadFromFile("vel100.png");
                break;
            case 80:
                sal.loadFromFile("vel75.png");
                break;
            case 60:
                sal.loadFromFile("vel50.png");
                break;
            case 40:
                sal.loadFromFile("vel25.png");
                break;
            case 20:
                sal.loadFromFile("vel0.png");
                break;
        }

        sf::Sprite i_s;
        i_s.setTexture(sal);
        i_s.setPosition(1120,60);
        i_s.setScale(0.5,0.5);
        window.draw(i_s);

        nave.pintar(window);

        for(ibalas i=balas.begin(); i!=balas.end();i++)
        {
            (*i)->pintar(window);
        }
        for(iast i=AST_V.begin(); i!=AST_V.end();i++){
            (*i)->pintar(window);
        }

        for(ivid i=VIDA_V.begin(); i!=VIDA_V.end();i++){
            (*i)->pintar(window);
        }


        if(nave.mostrar_vidas()==0){
            if(nave.GetPunt()>p.GetPuntaje()){
                return game.game_o(true,nave.GetPunt());

            }else{
                return game.game_o(false,nave.GetPunt());
            }


        }
        if(nave.var==true){
            window.clear(sf::Color::Red);
            window.display();

        }
        nave.actualiza_puntaje();


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

VIDA* Juego::salva_nave(sf::FloatRect n)
{
   for(ivid i=VIDA_V.begin();i!=VIDA_V.end();i++)
    {
        if((*i)->devolver_cuadrado().intersects(n))
        {
            return *i;
        }

    }
    return NULL;

}
