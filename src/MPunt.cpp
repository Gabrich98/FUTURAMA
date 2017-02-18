#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "MPunt.h"


MPunt::MPunt(sf::RenderWindow& w):w(w),l(w)
{
    f.loadFromFile("fr-bold.ttf");
    //ctor
}

template <typename T>
std::string to_string(T pNumber)
{
    std::ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}



void MPunt::loop()
{
    ifstream fentrada("a_punt.dat", ios::in | ios::binary);

    if(fentrada.is_open())
    {
        p.leer(fentrada);
    }
    punt1.setFont(f);
    punt1.setColor(sf::Color::Red);
    punt1.setPosition(450,440);
    punt1.setCharacterSize(80);
    punt1.setString(p.GetNombre()+"   "+to_string(p.GetPuntaje()));

    punt.setFont(f);
    punt.setColor(sf::Color::Blue);
    punt.setPosition(125,700);
    punt.setCharacterSize(50);
    punt.setString("[Espacio] REGRESAR AL MENU [Espacio]");

    t1.setFont(f);
    t1.setPosition(300,300);
    t1.setCharacterSize(80);
    t1.setString("MEJOR PUNTAJE");



    t.loadFromFile("fondo.jpg");
    sf::Sprite s;
    s.setPosition(-10,-10);
    s.setTexture(t);
    s.setScale(0.26, 0.3);



    while(w.isOpen())
    {

        sf::Event event;
        while (w.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                   menu m(w);
                   m.loop();
                }

            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::F1){}
            }
        }
        w.clear(sf::Color::Black);


        w.draw(s);
        w.draw(t1);
        w.draw(punt1);
        w.draw(punt);
        w.display();
    }


}
