#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    
    int vec_jugador1 [6] = {};
    int vec_jugador2 [6] = {};
    int jugador1, jugador2;
    const int FILAS = 6;
    const int COL = 2;
    int m [FILAS][COL] = {{},{}};
    string vec_hito [5] = {};
    int acuJ1 = 0;
    int acuJ2 = 0;
    string ganador;
    int puntosGanador;

    vec_hito [0] = "Estatuilla";
    vec_hito [1] = "Estatuilla ++";
    vec_hito [2] = "Ganador ";
    vec_hito [3] = "Ganador ++";
    vec_hito [4] = "Estatuilla --";
    vec_hito [5] = "Lanzamiento";


    for(int i=0; i<=6; i++){
        vec_jugador1 [i] = i+1;
        acuJ1 += vec_jugador1[i];
        vec_jugador2 [i] = i+2;
        acuJ2 += vec_jugador2[i];
    }

    /*for(int i=0; i<FILAS; i++)
    {
        for (int j=0; j < COL; j++)
        {
            cout << "Ingresar pts J1: ";
            cin >> vec_jugador1 [i];
            cout << "Ingresar pts J2: ";
            cin >> vec_jugador2 [j];
        }
    }*/

    cout << "IRWIN'S REVENGE - FASE FINAL" << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;
    cout << "HITO" << "\t" << "\t" << "JUGADOR 1" << "\t" << "JUGARDOR 2" << endl;

    for (int i=0; i< FILAS; i++)
    {
        for (int  j=0; j < COL - 1; j++)
        {
            cout << vec_hito[i] << "\t";
            cout << vec_jugador1 [i] << ": PDV" "\t" << "\t";
            cout << vec_jugador2 [i] << ": PDV";
        }
        cout << "\n";
    }
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL" << "\t" << "\t" << acuJ1 << ": PDV"<< "\t" << "\t" << acuJ2 << ": PDV" << endl;

    if(acuJ1 > acuJ2){
        ganador = "JUGADOR 1";
        puntosGanador = acuJ1;
    }else{
        ganador = "JUGADOR 2";
        puntosGanador = acuJ2;
    }

    cout << "GANADOR: " << ganador << " con " << puntosGanador << " putnos de victoria.";
    
    
    getch ();
    return 0;
}