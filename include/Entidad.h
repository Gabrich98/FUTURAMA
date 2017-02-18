#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>
#include <string>
//#include <SoundSource.hpp>

using namespace std;

class Juego;

class Entidad
{
    public:
        Entidad(string obj1, string obj2, int x, int y);
        virtual void procesar_evento(sf::Event) = 0;
        virtual void accion(Juego&) = 0;
        virtual void pintar(sf::RenderWindow&) = 0;
        bool vivir();
        void matar();

    protected:


        sf::Texture o1;
        sf::Texture o2;


        sf::Sprite sprite;
        sf::Sprite sprite1;


    private:
        bool esta_vivo;
};

#endif // ENTIDAD_H
