#ifndef LISTADOPUNTAJES_H
#define LISTADOPUNTAJES_H
#include <Puntaje.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <list>

class ListadoPuntajes
{
    public:
        ListadoPuntajes(std::string n, int p);
        void leer();
        void guardar();


    protected:

    private:
        std::string nombre;
        int punt;
        Puntaje p;
        list<Puntaje*> PUNT_P;
        typedef list<Puntaje*>::iterator ipunt;
};

#endif // LISTADOPUNTAJES_H
