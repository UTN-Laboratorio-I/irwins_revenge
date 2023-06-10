#ifndef TURNOS_H
#define TURNOS_H

#include <iostream>
using namespace std;


//VARIABLES DE TURNOS:


//Función que otorga turno inicial de los jugadores según tirada de dados:
void primerTurno(int valor1, int valor2, string turnos[], string jugadores[]){
    if(valor1 > valor2){
        turnos[0]=jugadores[0];
        turnos[1]=jugadores[1];
    }else{
        turnos[0]=jugadores[1];
        turnos[1]=jugadores[0];
    }
}

//Función que modifica la ronda a su subsiguiente:
void siguienteRonda(int& ronda){
    ronda++;
}

//Functión que va rotando los turnos a medida que avanzan las rondas:
void asignarTurno(string turnos[]){
    string jugador_temp = turnos[0];
    turnos[0]=turnos[1];
    turnos[1]=jugador_temp;
    
    // cout << turnos[0] << "   " << turnos[1] <<endl;
}



#endif