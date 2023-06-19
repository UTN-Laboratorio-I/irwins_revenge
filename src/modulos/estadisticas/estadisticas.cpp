#include <iostream>
#include <string>
using namespace std;



    void mostrar_estadisticas (int m[][2], string , string);

int main (){

    string nombre_J1 = "Fede";
    string nombre_J2 = "Elias";

    int matriz_jugadores [6][2] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}, {11,12}};

    mostrar_estadisticas(matriz_jugadores, nombre_J1, nombre_J2);


    return 0;
}

    void mostrar_estadisticas(int m[][2], string n_J1, string n_J2){

    int acuJ1 = 0;
    int acuJ2 = 0;
    int i, j;
    
    // Este vector muestra la columna con los hitos a mostrar por pantalla
    string vec_hito [6] = {"Estatuilla", "Estatuilla ++", "Ganador ", "Ganador ++", "Estatuilla --", "Lanzamiento"};

    // Variable de jugador ganador
    string ganador;

    // Variable que muestra el puntaje ganador
    int puntosGanador;

    // print de encabezado
    cout << "IRWIN'S REVENGE - FASE FINAL" << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;
    cout << "HITO" << "\t" << "\t" << n_J1 << "\t" << "\t"<< n_J2 << endl;

    for (i=0; i< 6; i++)
    {
    cout << vec_hito[i] << "\t";
        for (j=0; j < 2; j++)
        {
        cout << m[i][j]  << " PDV" "\t" << "\t";
        }
        acuJ1 += m[i][0];
        acuJ2 += m[i][1];
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

    cout << "GANADOR: " << ganador << " con " << puntosGanador << " puntos de victoria." << "\n";

    system ("pause");
    system ("cls");
}

