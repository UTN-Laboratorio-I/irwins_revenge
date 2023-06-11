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

    vec_hito [0] = "Estatuilla";
    vec_hito [1] = "Estatuilla ++";
    vec_hito [2] = "Ganador ";
    vec_hito [3] = "Ganador ++";
    vec_hito [4] = "Estatuilla --";
    vec_hito [5] = "Lanzamiento";


    for(int i=0; i<=6; i++){
        vec_jugador1 [i] = i+1;
        vec_jugador2 [i] = i+2;
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

    for (int i=0; i< FILAS; i++)
    {
        for (int  j=0; j < COL - 1; j++)
        {
            cout << vec_hito[i] <<"\t"<< "J1: ";
            cout << vec_jugador1 [i] << "\t";
            cout << "J2: ";
            cout << vec_jugador2 [i];
        }
        cout << "\n";
    }
    
    
    getch ();
    return 0;
}