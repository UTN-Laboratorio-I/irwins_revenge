#include <iostream>
#include "../dados/dados.h"
using namespace std;


//Función que otorga turno inicial de los jugadores según tirada de dados:
    void primerTurno(int dado_j1, int dado_j2, string turnos[], string jugadores[], bool& fase_exp){
        if(dado_j1 > dado_j2){
            turnos[0]=jugadores[0];
            turnos[1]=jugadores[1];
        }else{
            turnos[0]=jugadores[1];
            turnos[1]=jugadores[0];
        }
        system("cls");
        cout << "----------------------------" << endl;
        cout << "Primer turno: " << turnos[0]<<endl;
        cout << "Segundo turno: " <<turnos[1]<<endl;
        cout << "----------------------------" << endl;
        system("pause");
        fase_exp=1;
    }

//Función que modifica la ronda a su subsiguiente:
    void siguienteRonda(int& ronda){
        ronda++;
    }

//Función que va rotando los turnos a medida que avanzan las rondas:
    void asignarTurno(string turnos[]){
        string jugador_temp = turnos[0];
        turnos[0]=turnos[1];
        turnos[1]=jugador_temp;
    }
//Detenemos fase exp. en caso de no haber más estatuillas disponibles:
    void checkFinFaseExpedicion(string estatuillas_disponibles[], bool finFaseExpedicion){
        int i=0,max=5;
        for(i; i<max;i++){
            if(estatuillas_disponibles[i]!=""){
                finFaseExpedicion=false;
            }
        }
    }
