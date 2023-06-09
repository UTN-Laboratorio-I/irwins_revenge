#ifndef TURNOS_H
#define TURNOS_H

#include <iostream>
using namespace std;

//Función que modifica la ronda a su subsiguiente:
void siguienteRonda(int &ronda){
    int siguienteRonda = ronda++;
    ronda++;
}

void asignarTurno(int jugador, int turnoActual){
    cout <<"Asignar turno";
}

#endif