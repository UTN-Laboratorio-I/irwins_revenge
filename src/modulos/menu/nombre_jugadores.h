#include <iostream>
#include <string>
using namespace std;

// Esta funcion pide los nombres de los jugadores y los guarda en un vector en MAIN

void solicitar_nombres(string jugadores[])
{
    const int N = 2;
    int i;
    for (i = 0; i < N; i++)
    {
        if (i == 0)
        {
            cout << "ingrese el nombre del primero jugador" << endl;
            cin >> jugadores[0];
        }
        else
        {
            cout << "ingrese el nombre del segundo jugador" << endl;
            cin >> jugadores[1];
        }
    }
}
