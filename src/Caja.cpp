#include "Caja.h"

Caja::Caja(/*int tam*/) : Entidad("caja.png","","","", 1366, rand()%765)
{
    sprite.setScale(1,1);
    vel=3 + rand()%4;
    //Constructor
}


void Caja::procesar_evento(sf::Event)
{
}

sf::FloatRect Caja::devolver_cuadrado()
{
        return sprite.getGlobalBounds();
}

void Caja::accion(Juego&)
{
    sprite.move(0,vel);
    if (sprite.getPosition().x<-10) sprite.setPosition(1366, rand()%765);
}

void Caja::pintar(sf::RenderWindow& w)
{
    w.draw(sprite);
}
