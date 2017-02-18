#include "Bala.h"
#include "Juego.h"

Bala::Bala(sf::Vector2f& pos_ini):Entidad("laser.png","", pos_ini.x, pos_ini.y)
{
<<<<<<< HEAD
    sprite.setPosition(pos_ini.x-120, pos_ini.y+60);

=======
    sprite.setPosition(pos_ini.x+105, pos_ini.y+30);
    sprite1.setRotation(90);
    sprite1.setPosition(pos_ini.x-53,pos_ini.y+60);

    //sprite2.setPosition(pos_ini.x+52, pos_ini.y+15);
   // sprite3.setPosition(pos_ini.x,pos_ini.y+15);
    //Constructor
>>>>>>> origin/master
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

<<<<<<< HEAD
=======
    sprite.move(5,0);
    sprite1.move(5,0);
    sprite2.move(5,0);
    sprite3.move(5,0);
>>>>>>> origin/master
}

void Bala::pintar(sf::RenderWindow& w)
{
      w.draw(sprite);
}
