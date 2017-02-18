#include "Caja.h"
Caja::Caja(/*int tam*/) : Entidad("caja.png","", 1366, rand()%765)
{

    sprite.setScale(0.3,0.3);
    vel=2 + rand()%4;
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
    sprite.move(-vel,0);
    if (sprite.getPosition().x<-10) sprite.setPosition(1366, rand()%765);
}

void Caja::pintar(sf::RenderWindow& w)
{
    w.draw(sprite);
}
