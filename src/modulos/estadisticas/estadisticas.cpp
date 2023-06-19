#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;






int mostrar_estadisticas(int m_jugadores [][2], string n_J1, string n_J2){

    int acuJ1 = 0;
    int acuJ2 = 0;
    int i, j;
    string vec_hito [5] = {};

    // Variable de jugador ganador
    string ganador;

    // Variable que muestra el puntaje ganador
    int puntosGanador;

    // Este vector muestra la columna con los hitos a mostrar por pantalla
    vec_hito [0] = "Estatuilla";
    vec_hito [1] = "Estatuilla ++";
    vec_hito [2] = "Ganador ";
    vec_hito [3] = "Ganador ++";
    vec_hito [4] = "Estatuilla --";
    vec_hito [5] = "Lanzamiento";


    // print de encabezado
    cout << "IRWIN'S REVENGE - FASE FINAL" << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;
    cout << "HITO" << "\t" << "\t" << n_J1 << "\t" << n_J2 << endl;

    for (i=0; i< 6; i++)
    {
    cout << vec_hito[i] << "\t";
        for (j=0; j < 2; j++)
        {
        cout << m_jugadores [i][j]  << " PDV" "\t" << "\t";
        acuJ1 += m_jugadores [i][0];
        acuJ2 += m_jugadores [0][i];
        }
        cout << "\n";
    }
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL" << "\t" << "\t" << acuJ1 << " PDV"<< "\t" << "\t" << acuJ2 << " PDV" << endl;


    // Condicion de ganador
    if(acuJ1 > acuJ2){
        ganador = n_J1;
        puntosGanador = acuJ1;
    }else{
        ganador = n_J2;
        puntosGanador = acuJ2;
    }

    cout << "GANADOR: " << ganador << " con " << puntosGanador << " puntos de victoria.";

    system ("pause");
    system ("cls");
    return 0;
}
