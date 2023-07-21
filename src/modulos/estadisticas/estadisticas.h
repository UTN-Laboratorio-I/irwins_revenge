#include <iostream>
#include <string>
using namespace std;

/*int estadisticas_en_cero(int m[][2])
{
    int i, j;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 2; j++)
        {
            m[i][j] = 0;
        }
    }
    return m[6][2];
}*/

// Funcion para cargar estadisticas

void cargar_estadisticas(int puntaje_jugadores[6][2])
{

    int i, j;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 2; j++)
        {
            puntaje_jugadores[i][j];
        }
    }

}

// Funcion para mostrar las estadisticas

void mostrar_estadisticas(
    int puntaje_jugadores[][2],
    string jugadores[],
    string ordenEstatuillas[])
{
    string n_J1 = jugadores[0], n_J2 = jugadores[1];
    int acuJ1 = 0, acuJ2 = 0;
    int i, j, z;

    // Este vector muestra la columna con los hitos a mostrar por pantalla
    string vec_hito[8] = {"Estatuilla", "Estatuilla ++", "Ganador ", "Ganador ++", "Estatuilla --", "Lanzamiento", "Maldicion CANGREJO", "Maldicion HORMIGA"};

    // Variable de jugador ganador
    string ganador;

    // Variable que muestra el puntaje ganador
    int puntosGanador;

    // print de encabezado
    cout << "IRWIN'S REVENGE - FASE FINAL" << endl;
    cout << "------------------------------------------------------------------------" << endl
         << endl;
    cout << "HITO"
         << "\t"
         << "\t" 
         << "\t"
         << n_J1 << "\t"
         << "\t" << n_J2 << endl;

    for (i = 0; i < 8; i++)
    {
        cout << vec_hito[i] << "\t";
        for (j = 0; j < 2; j++)
        {
            if (i == 6 || i == 7)
            {
                cout << puntaje_jugadores[i][j] << " PDV"
                     << "\t" << "\t";
            }
            else
            {
                cout << "\t" << puntaje_jugadores[i][j] << " PDV"
                     << "\t";
            }
        }
        acuJ1 += puntaje_jugadores[i][0];
        acuJ2 += puntaje_jugadores[i][1];
        cout << "\n";
    }
    cout << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL"       
         << "\t"
         << "\t"
         << "\t" << acuJ1 << " PDV"
         << "\t"
         << "\t" << acuJ2 << " PDV" << endl;

    // Condicion de ganador
    if (acuJ1 > acuJ2)
    {
        ganador = n_J1;
        puntosGanador = acuJ1;
    }
    else
    {
        ganador = n_J2;
        puntosGanador = acuJ2;
    }

    if (acuJ1 <= 0 || acuJ1 <= 0)
    {
        cout << "\n"
                "No hay ganadores aun"
             << "\n"
             << "\n";
    }
    else
    {

        cout << "GANADOR: " << ganador << " con " << puntosGanador << " puntos de victoria."
             << "\n";
    }

    cout << endl;
    cout << "El orden en el que se ganaron las estatuillas fue el siguiente: " << endl;
    for (int z = 0; z < 5; z++)
    {
        cout << "#" << z + 1 << " - " << ordenEstatuillas[z] << endl;
    }

    system("pause");
    system("cls");
}