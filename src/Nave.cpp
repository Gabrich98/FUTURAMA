#include "Nave.h"
#include "Juego.h"
#include "Bala.h"
#include <string>
#include <sstream>


Nave::Nave() : Entidad("nave_mov.png","propulsor.psd","","", 250, 200)
{
    vidas=3;
    salud=100;
    disparando = false;
    contador = 10;
    actual = NoMov;
    fuente.loadFromFile("letra.ttf");
    puntaje=0;
    subir=false;
    //Constructor
}


template <typename T>
std::string to_string(T pNumber)
{
 std::ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}



void Nave::actualiza_puntaje()
{
    puntaje=puntaje+1;
}


void Nave::descontar_vidas()
{
    vidas--;
}
int Nave::mostrar_vidas(){

        return vidas;
}
void Nave::descontar_salud()
{
    salud=salud-20;
}

void Nave::sumar_salud()
{
    salud=salud+20;
}
void Nave::sumar_vidas()
{
    vidas++;
}

int Nave::mostrar_salud()
{
    return salud;
}

void Nave::Reset_vidas()
{
    vidas=3;
    puntaje=0;


}




void Nave::procesar_evento(sf::Event event)
{
    if (event.type == sf:: Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            actual = Izquierda;
            break;
        case sf::Keyboard::Right:
            actual = Derecha;
            break;
        case sf::Keyboard::Up:
            actual = Arriba;
            subir=true;
            break;
        case sf::Keyboard::Down:
            actual = Abajo;
            break;
        default:
            break;
        }
    }
    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            if (actual == Izquierda) actual = NoMov;
            if(subir==true)subir=false;
            break;
        case sf::Keyboard::Right:
            if (actual == Derecha) actual = NoMov;
            if(subir==true)subir=false;
            break;
        case sf::Keyboard::Up:
            if (actual == Arriba){
                    actual = NoMov;
                    subir=false;
            }
            break;
        case sf::Keyboard::Down:
            if (actual == Abajo) actual = NoMov;
            if(subir==true)subir=false;
            break;
        default:
            break;
        }
    }

    if(event.type==sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Space)
        {
            disparando = true;
        }
    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            disparando = false;
        }
    }
    sprite.setRotation(90);

}


void Nave::accion(Juego& j) {
        //comparar nave con asteroides

        AST* a = j.colision_con_nave(sprite.getGlobalBounds());



        if(a != NULL){
            a->matar();
            matar();
            descontar_salud();
            var=true;
            if (salud==0){
                descontar_vidas();
                salud=100;

            }
        }

        VIDA* v=j.salva_nave(sprite.getGlobalBounds());
        if(v != NULL)
        {
            v->matar();
            //var=true;

            if (salud==100)
            {
                sumar_vidas();
                salud=0;
            }
            sumar_salud();
        }

        sprite.setScale(0.6,0.5);

        punt.setCharacterSize(25);
        punt.setFont(fuente);
        punt.setColor(sf::Color::Yellow);
        punt.setPosition(sprite.getPosition().x+70,sprite.getPosition().y+50);
        punt.setString(to_string(puntaje));

        sprite1.setPosition(sprite.getPosition().x+35,sprite.getPosition().y+170);



        if(disparando){
            if (contador <= 0) {
                j.disparar(sprite.getPosition() + sf::Vector2f(o1.getSize().x / 2-23, -50));
                contador = 5;
            }
            contador--;
        }
        switch (actual) {
            case Izquierda:
               if(sprite.getPosition().x>=3) sprite.move(-12, 0);
            break;
            case Derecha:
                if(sprite.getPosition().x<=1228)sprite.move(12, 0);
            break;
            case Arriba:
                if(sprite.getPosition().y>=3)sprite.move(0, -5);
            break;
            case Abajo:
                if(sprite.getPosition().y<=650)sprite.move(0, 8);
            break;
            case NoMov:

            break;
        }

}

void Nave::pintar(sf::RenderWindow& w) {

    //Este es para pintar la nave
    if(subir==true)w.draw(sprite1);
    w.draw(sprite);
    w.draw(punt);
}
