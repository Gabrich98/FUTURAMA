#include "Game_Over.h"
#include "Juego.h"
#include "menu.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

Game_Over::Game_Over(sf::RenderWindow& w) : w(w), l(w)
{

     fuente.loadFromFile("sama.ttf");
    //ctor
}


void Game_Over::game_o(bool ganar, int pu){

    t.setFont(fuente);
    t.setPosition(350,640);
    t.setCharacterSize(50);
    t.setString("MENU --PRESS SPACE--");

    t1.setFont(fuente);
    t1.setPosition(400,700);
    t1.setCharacterSize(50);
    t1.setString("EXIT --PRESS ESC--");

    fondo.loadFromFile("game_over.jpg");
    sf::Sprite s;

    s.setTexture(fondo);

    s.setScale(1, 1);

    while(w.isOpen())
    {

        if(ganar==true){
                sf::String nom;
                nom=l.leer("INGRESE SU NOMBRE");
                p=Puntaje(nom,pu);
                ofstream fsalida("a_punt.dat",ios::out | ios::binary);
                if(fsalida.is_open())
                {
                    p.guardar(fsalida);
                    break;
                }


        }
        sf::Event event;
        while (w.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                    menu m(w);
                    return m.loop();
                }
                if(event.key.code == sf::Keyboard::Escape)
                {
                    return w.close();
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::F1){}
            }
        }
        w.clear(sf::Color::Black);
        w.draw(s);
        //w.draw(t);
        //w.draw(t1);
        w.display();
    }
}
