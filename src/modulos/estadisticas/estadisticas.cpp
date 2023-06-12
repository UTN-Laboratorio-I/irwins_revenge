#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;




int main(){
    
    int acuJ1 = 0;
    int acuJ2 = 0;
    int i, j;
    int vec_jugador [6][2] = {{},{}};
    
    // Este ciclo fuerza para cargar un puntaje en los vectores
    for(i=0; i<6; i++){
        for (j=0; j<2; j++){
            vec_jugador [i][j] = rand () % 15;
            acuJ1 += vec_jugador [i][0];
            acuJ2 += vec_jugador [0][i];
        }
    }
    
    const int FILAS = 6;
    const int COL = 2;
    int m [FILAS][COL] = {{},{}};
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
    cout << "HITO" << "\t" << "\t" << "JUGADOR 1" << "\t" << "JUGARDOR 2" << endl;

    for (i=0; i< FILAS; i++)
    {
    cout << vec_hito[i] << "\t";
        for (j=0; j < COL; j++)
        {
        cout << vec_jugador [i][j]  << " PDV" "\t" << "\t";
        }
        cout << "\n";
    }
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL" << "\t" << "\t" << acuJ1 << " PDV"<< "\t" << "\t" << acuJ2 << " PDV" << endl;

    
    // condicion de ganador

    if(acuJ1 > acuJ2){
        ganador = "JUGADOR 1"; // aca iria el string del nombre del jugador
        puntosGanador = acuJ1;
    }else{
        ganador = "JUGADOR 2";
        puntosGanador = acuJ2;
    }

    cout << "GANADOR: " << ganador << " con " << puntosGanador << " puntos de victoria.";
    
    
    getch ();
    return 0;
}
