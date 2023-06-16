#ifndef TURNOS_H
#define TURNOS_H

#include <iostream>
using namespace std;

<<<<<<< HEAD
// esta funcion permite que los jugadores elijan estatuillas
void asignarTurno(bool turno_jugador1, bool turno_jugador2, int TAM, string jugador1, string jugador2,
                  int &estatuilla_seleccionada_j1, int &estatuilla_seleccionada_j2)
{
    int i;

    if (turno_jugador1 == true && turno_jugador2 == false)
    {

        for (i = 0; i < TAM; i++)
        {
            cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
        }
        cout << jugador1 << " escoja una estatuilla" << endl;
        cin >> estatuilla_seleccionada_j1;
        cout << endl;

        for (i = 0; i < TAM; i++)
        {
            cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
        }
        cout << jugador2 << " escoja una estatuilla" << endl;
        cin >> estatuilla_seleccionada_j2;
        cout << endl;
    }
    else
    {
        if (turno_jugador2 == true && turno_jugador1 == false)
        {

            for (i = 0; i < TAM; i++)
            {
                cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
            }
            cout << jugador2 << " escoja una estatuilla" << endl;
            cin >> estatuilla_seleccionada_j2;
            cout << endl;

            for (i = 0; i < TAM; i++)
            {
                cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
            }
            cout << jugador1 << " escoja una estatuilla" << endl;
            cin >> estatuilla_seleccionada_j1;
            cout << endl;
        }
    }
}
=======

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
>>>>>>> escudero/estatuillas
