#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


//LIMPIEZA DE LA CONSOLA:
void ClearConsole() {
  cout << "\x1b[2J\x1b[H";
}

void mostrarHeaderJuego(bool fase_exp){
    string fase = fase_exp ? "FASE DE EXPEDICIÓN" : "FASE FINAL";
    cout << "IRWIN'S REVENGE - " << fase<<endl;
    cout << "------------------------------------------------------------------------"<<endl;
    ;
}

//VISUALIZACIÓN DE INFORMACIÓN BÁSICA:
void mostrarPantallaSeleccion(bool fase_exp, string jugadores[], string estatuillas_jugadores[][2], string turnos[], int turno){
//Mostramos el header el juego:
    string estatuillas_jugador1, estatuillas_jugador2;

    for(int i=0; i<5;i++){
        if (estatuillas_jugadores[i][0] !=""){
            estatuillas_jugador1 += " " + estatuillas_jugadores[i][0];
            if(i!=0 && estatuillas_jugadores[i+1][0] !=""){
                estatuillas_jugador1 += ", ";
            }
        }
        if (estatuillas_jugadores[i][1] !=""){
            estatuillas_jugador2 += " " + estatuillas_jugadores[i][1];
            if(i!=0 && estatuillas_jugadores[i+1][1] !=""){
                estatuillas_jugador2 += ", ";
            }
        }
    }
    mostrarHeaderJuego(fase_exp);
    cout << jugadores[0] << "                                       "<<jugadores[1]<<endl;
    cout << "Estatuillas:"<<"                                       "<<"Estatuillas"<<endl;
    cout << estatuillas_jugador1 <<"                                "<<estatuillas_jugador2<<endl;
    cout << endl;
}

void showMessageAndClear(int tipo_mensaje, string message)
{
    //0 : selección de estatuilla
    //1 : 
    switch(tipo_mensaje){
        case 0:
            cout << message << std::endl;
            this_thread::sleep_for(chrono::seconds(5));
            ClearConsole();
            break;
        default:
            break;
    }
}