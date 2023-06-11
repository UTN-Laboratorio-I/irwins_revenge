#include <iostream>
#include <string>

using namespace std;

bool dados_inicio(int dado1, int dado2, bool &jugador1_primero, bool &jugador2_primero) // recibe la peticion de lanzar el dado de cada jugador
{
    bool jugador1_primero = false, jugador2_primero = false; // ambos jugadores empiezan siendo primero igual a falso

    // este ciclo se repite hasta que los dados sean distintos
    do
    {
        dado1 = rand() % 10 + 1;
        dado1 = rand() % 10 + 1;
    } while (dado1 == dado2);

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