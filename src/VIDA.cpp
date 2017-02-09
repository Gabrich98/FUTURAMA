#include "VIDA.h"

VIDA::VIDA(/*int tam*/) : Entidad("vida.png","","","", rand()%1366, rand()%50)
{
    sprite.setScale(0.2,0.2);
    vel=3 + rand()%4;
    //Constructor
}


void VIDA::procesar_evento(sf::Event)
{
}

sf::FloatRect VIDA::devolver_cuadrado()
{
        return sprite.getGlobalBounds();
}

void VIDA::accion(Juego&)
{
    sprite.move(0,vel);
    if (sprite.getPosition().y>768) sprite.setPosition(rand()%1366, rand()%100);
}

void VIDA::pintar(sf::RenderWindow& w)
{
    w.draw(sprite);
}
