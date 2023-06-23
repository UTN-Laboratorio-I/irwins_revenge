#include <iostream>
#include <string>

using namespace std;

void OrdenarDados(int dados[])
{
    int n = 5;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (dados[j] > dados[j + 1])
            {
                // Intercambiar los elementos
                int temp = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = temp;
            }
        }
    }
}

bool escalera_normal(int dados[])
{
    int n = 5, i;
    bool escalera = true;

    for (i = 0; i < n - 1; i++)
    {
        if (dados[i + 1] != dados[i] + 1)
        {
            escalera = false;
            break;
        }
    }
    return escalera;
}

bool dados_iguales_medusa(int dados[])
{
    int n = 5, i;
    bool todos_iguales = true;
    int numero;
    numero = dados[0];

    for (i = 0; i < n; i++)
    {
        // verifica que al menos uno sea disinto
        if (numero != dados[i])
        {
            todos_iguales = false;
            break;
        }
    }
    return todos_iguales;
}

bool escalera_salamandra(int dados[])
{
    int n = 5, i;
    bool escalera = true;

    for (i = 0; i < n - 2; i++)
    {
        if (dados[i + 1] != dados[i] + 1)
        {
            escalera = false;
            break;
        }
    }
    return escalera;
}

void verificar_si_tiene_medusa(int dados[], bool &tiene_medusa, int id_jugador, string estatuillas_jugadores[5][2])
{
    int i = 0, max_filas = 5;

    for (i; i < max_filas; i++)
    {
        if (estatuillas_jugadores[i][id_jugador] == "MEDUSA")
        {
            tiene_medusa = true;
            break;
        }
    }
}

void verificar_si_tiene_salamandra(int dados[], bool &tiene_salamandra, int id_jugador, string estatuillas_jugadores[5][2])
{
    int i = 0, max_filas = 5;

    for (i; i < max_filas; i++)
    {
        if (estatuillas_jugadores[i][id_jugador] == "SALAMANDRA")
        {
            tiene_salamandra = true;
            break;
        }
    }
}