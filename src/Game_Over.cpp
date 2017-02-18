#include "Game_Over.h"
#include "Juego.h"
#include "menu.h"
#include "ListadoPuntajes.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

Game_Over::Game_Over(sf::RenderWindow& w) : w(w), lee(w)
{

     fuente.loadFromFile("sama.ttf");
    //ctor
}


void Game_Over::game_o(bool ganar, int pu){



    fondo.loadFromFile("game_over.jpg");
    sf::Sprite s;

    s.setTexture(fondo);

    s.setScale(1.02, 1);
    s.setPosition(-10,0);

    while(w.isOpen())
    {

        if(ganar==true){

                w.draw(s);

                sf::String nom;
                nom=lee.leer("INGRESE SU NOMBRE");
                /*p=Puntaje(nom,pu);
                ofstream fsalida("a_punt.dat",ios::out | ios::binary);
                if(fsalida.is_open())
                {

                    p.guardar(fsalida);
                    break;
                }*/
                lista=ListadoPuntajes(nom,pu);
                lista.guardar();




        }
        sf::Event event;
        while (w.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Return)
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
