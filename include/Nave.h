#ifndef NAVE_H
#define NAVE_H

#include <Entidad.h>

class Juego;

enum Movimiento
{
        Izquierda,
        Derecha,
        Arriba,
        Abajo,
        NoMov
};

class Nave : public Entidad
{
    public:
        Nave();
        void procesar_evento(sf::Event);
        void accion(Juego&);
        void pintar(sf::RenderWindow&);
        void descontar_vidas();
        int mostrar_vidas();
        void sumar_vidas();
        void descontar_salud();
        int mostrar_salud();
        void sumar_salud();
        void actualiza_puntaje();
        int GetPunt(){return puntaje;};
        void Reset_vidas();
        bool var;

    protected:

        int contador;
        long puntaje;
        int vidas;
        int salud;

    private:
        bool subir;
        sf::Text punt;
        sf::Font fuente;
        bool disparando;
        Movimiento actual;
};

#endif // NAVE_H
