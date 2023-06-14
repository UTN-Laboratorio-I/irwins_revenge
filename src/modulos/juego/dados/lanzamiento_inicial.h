#include <iostream>
#include <string>

using namespace std;

bool dados_inicio(bool &jugador1_primero, bool &jugador2_primero) // recibe la peticion de lanzar el dado de cada jugador
{
    int dado1 = 0, dado2 = 0;
    // este ciclo se repite hasta que los dados sean distintos
    do
    {
        dado1 = rand() % 10 + 1;
        dado2 = rand() % 10 + 1;
    } while (dado1 == dado2);
    cout << endl;
    cout << dado1 << endl;
    cout << dado2 << endl;

    // una vez aseguro que los dados son distintos, comparo con estos dos if
    if (dado1 > dado2)
    {
        cout << "jugador 1 va primero";
        jugador1_primero = true;
        return jugador1_primero; // aca el jugador 1 gano el dado, por lo que ahora ir primero es verdadero
    }
    else
    {
        cout << "jugador 2 va primero";
        jugador2_primero = true; // aca el jugador 2 gano el dado, por lo que ahora ir primero es verdadero
        return jugador2_primero;
    }
}