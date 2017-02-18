#include "ListadoPuntajes.h"

ListadoPuntajes::ListadoPuntajes(std::string n, int p):nombre(n),punt(p)
{
    //ctor
}

void ListadoPuntajes::guardar()
{
    for(ipunt i=PUNT_P.end())

}

void ListadoPuntajes::leer()
{

    for(ipunt i=PUNT_P.begin(); i!=PUNT_P.end();i++)
        {


        }
}
void ListadoPuntajes::guardar()
{

     PUNT_P.push_back(new Puntaje(nombre,punt));
     p=Puntaje(nombre,punt);
     ofstream fsalida("a_punt.dat",ios::out | ios::binary);
                if(fsalida.is_open())
                {

                    p.guardar(fsalida);
                    break;
                }


}
