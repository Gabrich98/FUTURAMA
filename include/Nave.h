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
        void sumar_cajas();
        int mostrar_cajas();
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> origin/master
        void actualiza_puntaje();
        int GetPunt(){return puntaje;};
>>>>>>> origin/master
        void Reset_vidas();
        bool var;

    protected:

        int contador;
        int vidas;
        int cajas;

    private:
        bool subir;
        sf::Font fuente;
        bool disparando;
        Movimiento actual;
};

#endif // NAVE_H
