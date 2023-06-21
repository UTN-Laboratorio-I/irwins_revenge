#include <iostream>
using namespace std;


//Función que otorga turno inicial de los jugadores según tirada de dados:
    void primerTurno(int dados[], string turnos[], string jugadores[], bool& fase_exp, bool& primer_turno){
        if(dados[0]< dados[1]){
            turnos[0]=jugadores[0];
            turnos[1]=jugadores[1];
        }else{
            turnos[0]=jugadores[1];
            turnos[1]=jugadores[0];
        }

        cout << "----------------------------" << endl;
        cout << "Primer turno: " << turnos[0]<<endl;
        cout << "Segundo turno: " <<turnos[1]<<endl;
        cout << "----------------------------" << endl;
        // system("pause");
        // system("cls");
        fase_exp=1;
        primer_turno=0;
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
    void checkFinFaseExpedicion(string estatuillas_disponibles[], bool& fase_exp){
        int i=0,max=5;
        fase_exp=false;
        for(i; i<max;i++){
            if(estatuillas_disponibles[i]!=""){
            //Si el bucle encuentra contenido en el array, entonces continua la fase exp:
                fase_exp=true;
            }
        }
    }

    void setearParametrosJugada(
        string turnos[], 
        string jugadores[], 
        bool& jugada_j1, 
        bool& jugada_j2,
        string& jugador,
        int& turnoActual
        )
    {
    //Si el nombre del jugador corresponde, y no jugó, se le otorga la tirada:
            if(turnos[turnoActual]==jugadores[0] && !jugada_j1)
            {
                jugador=turnos[turnoActual];
                jugada_j1=true;
            }
            else if(turnos[turnoActual] == jugadores[1]&& !jugada_j2)
            {
                jugador=turnos[turnoActual];
                jugada_j2=true;
            }
    }