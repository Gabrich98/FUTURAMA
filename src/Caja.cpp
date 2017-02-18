#include "Caja.h"
<<<<<<< HEAD
<<<<<<< HEAD
Caja::Caja(/*int tam*/) : Entidad("caja.png","", 1366, rand()%765)
{

    sprite.setScale(0.3,0.3);
    vel=2 + rand()%4;
    //Constructor
}

=======
=======
>>>>>>> origin/master

Caja::Caja(/*int tam*/) : Entidad("caja.png","","","", 1366, rand()%765)
{
    sprite.setScale(1,1);
    vel=3 + rand()%4;
    //Constructor
}


<<<<<<< HEAD
>>>>>>> origin/master
=======
>>>>>>> origin/master
void Caja::procesar_evento(sf::Event)
{
}

sf::FloatRect Caja::devolver_cuadrado()
{
        return sprite.getGlobalBounds();
}

void Caja::accion(Juego&)
{
<<<<<<< HEAD
<<<<<<< HEAD
    sprite.move(-vel,0);
=======
    sprite.move(0,vel);
>>>>>>> origin/master
=======
    sprite.move(0,vel);
>>>>>>> origin/master
    if (sprite.getPosition().x<-10) sprite.setPosition(1366, rand()%765);
}

void Caja::pintar(sf::RenderWindow& w)
{
    w.draw(sprite);
}
