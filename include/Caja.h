#ifndef Caja_H
#define Caja_H

#include <Entidad.h>


class Caja : public Entidad
{
    public:
        Caja();
        void procesar_evento(sf::Event);
        void pintar(sf::RenderWindow&);
        void accion(Juego&);
        sf::FloatRect devolver_cuadrado();

    protected:
        int vel;
    private:
};

<<<<<<< HEAD
#endif // Caja_H
=======
#endif // VIDA_H
>>>>>>> origin/master

