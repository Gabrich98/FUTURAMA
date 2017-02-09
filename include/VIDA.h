#ifndef VIDA_H
#define VIDA_H

#include <Entidad.h>


class VIDA : public Entidad
{
    public:
        VIDA();
        void procesar_evento(sf::Event);
        void pintar(sf::RenderWindow&);
        void accion(Juego&);
        sf::FloatRect devolver_cuadrado();

    protected:
        int vel;
    private:
};

#endif // VIDA_H
