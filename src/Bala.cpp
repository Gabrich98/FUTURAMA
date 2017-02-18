#include "Bala.h"
#include "Juego.h"

Bala::Bala(sf::Vector2f& pos_ini):Entidad("laser.png","", pos_ini.x, pos_ini.y)
{
    sprite.setPosition(pos_ini.x-120, pos_ini.y+60);

}


void Bala::procesar_evento(sf::Event){}

//comparacion de colisiones
void Bala::accion(Juego& j)
{
    AST* a = j.colision_con_asteroide(sprite.getGlobalBounds());
    if(a!=NULL )
    {
        a->matar();
        matar();
    }
sprite.move(5,0);

}

void Bala::pintar(sf::RenderWindow& w)
{
      w.draw(sprite);
}
