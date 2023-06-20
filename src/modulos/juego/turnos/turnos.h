#include <iostream>
using namespace std;

// esta funcion permite que los jugadores elijan estatuillas
void asignarTurno(bool turno_jugador1, bool turno_jugador2, int TAM, string jugador1, string jugador2,
                  int &estatuilla_seleccionada_j1, int &estatuilla_seleccionada_j2)
{
    int i;

    if (turno_jugador1 == true && turno_jugador2 == false)
    {

        for (i = 0; i < TAM; i++)
        {
            cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
        }
        cout << jugador1 << " escoja una estatuilla" << endl;
        cin >> estatuilla_seleccionada_j1;
        cout << endl;

        for (i = 0; i < TAM; i++)
        {
            cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
        }
        cout << jugador2 << " escoja una estatuilla" << endl;
        cin >> estatuilla_seleccionada_j2;
        cout << endl;
    }
    else
    {
        if (turno_jugador2 == true && turno_jugador1 == false)
        {

            for (i = 0; i < TAM; i++)
            {
                cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
            }
            cout << jugador2 << " escoja una estatuilla" << endl;
            cin >> estatuilla_seleccionada_j2;
            cout << endl;

            for (i = 0; i < TAM; i++)
            {
                cout << num_estatuilla[i] << " - " << estatuillas[i] << endl;
            }
            cout << jugador1 << " escoja una estatuilla" << endl;
            cin >> estatuilla_seleccionada_j1;
            cout << endl;
        }
    }
}
