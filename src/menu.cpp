#include "menu.h"


menu::menu(sf::RenderWindow& w):w(w)
{
    f.loadFromFile("fr-bold.ttf");
    //ctor
}


void menu::loop()
{
    t1.setFont(f);
    t1.setPosition(20,700);
    t1.setCharacterSize(60);
    t1.setString("START [1]");

    t2.setFont(f);
    t2.setPosition(500,700);
    t2.setCharacterSize(60);
    t2.setString("SCORE [2]");

    t3.setFont(f);
    t3.setPosition(1000,700);
    t3.setCharacterSize(60);
    t3.setString("EXIT [3]");

    t.loadFromFile("menu.jpg");

    sf::Sprite s;
    //s.setPosition(-100,-100);
    s.setPosition(-20,-50);
    s.setTexture(t);
    s.setScale(1.38, 0.98);


    while(w.isOpen())
    {


        sf::Event event;
        while (w.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Numpad1)
                {
                    Juego j(w);
                    j.loop();
                }

                if(event.key.code == sf::Keyboard::Numpad2)
                {
                    return w.close();
                }

                if(event.key.code == sf::Keyboard::Numpad3)
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
        w.draw(t1);
        w.draw(t2);
        w.draw(t3);
        w.display();
    }


}
