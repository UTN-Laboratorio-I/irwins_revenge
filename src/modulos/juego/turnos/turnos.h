#ifndef TURNOS_H
#define TURNOS_H

#include <iostream>
using namespace std;

int siguienteRonda(int &ronda){
    int siguienteRonda = ronda++;
    return ronda++;
}

void asignarTurno(int jugador, int turnoActual){
    cout <<"Asignar turno";
}

#endif