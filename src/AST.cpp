#include "AST.h"


<<<<<<< HEAD
AST::AST(/*int tam*/) : Entidad("a_1.png","", 1366, rand()%765)
=======
AST::AST(/*int tam*/) : Entidad("a_1.png","","","", 1366, rand()%765)
>>>>>>> origin/master
{
    sprite.setRotation(180);
    sprite.setScale(0.6,0.6);
    vel=6 + rand()%4;
    //Constructor
}

void AST::procesar_evento(sf::Event)
{
}

sf::FloatRect AST::devolver_cuadrado()
{
        return sprite.getGlobalBounds();
}

void AST::accion(Juego&)
{
    sprite.move(-vel,0);
    if (sprite.getPosition().x<-10) sprite.setPosition(1366, rand()%765);
}

void AST::pintar(sf::RenderWindow& w)
{
    w.draw(sprite);
}
