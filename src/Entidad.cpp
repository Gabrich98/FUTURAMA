#include "Entidad.h"

Entidad::Entidad(string obj1, string obj2, int x, int y)
{
    esta_vivo=true;

    o1.loadFromFile(obj1);
    sprite.setTexture(o1);
    sprite.setPosition(x,y);

    o2.loadFromFile(obj2);
    sprite1.setTexture(o2);
    sprite1.setPosition(x,y);

}

bool Entidad::vivir(){
    return esta_vivo;
}
void Entidad::matar(){
    esta_vivo=false;
}
