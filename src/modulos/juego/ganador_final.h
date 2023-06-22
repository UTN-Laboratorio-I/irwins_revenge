#include <iostream>
#include <string>

// #include "helpers/helpers.h"
// #include "turnos/turnos.h"
// #include "../dados/dados.h"
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
// dados[5,4,3,2,1]

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
    bool escalera = true;
    int numero;
    numero = dados[0];

    for (i = 0; i < n; i++)
    {
        // verifica que al menos uno sea disinto
        if (dados[i] != dados[i] + 1)
        {
            escalera = false;
            break;
        }
    }
    return escalera;
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

void tiene_medusa(int dados[], bool& tiene_medusa, int id_jugador, string estatuillas_jugadores[5][2])
{   
int i=0, max_filas=5;

for(i;i<max_filas;i++){
            if(estatuillas_jugadores[i][id_jugador]=="MEDUSA"){
                tiene_medusa = true;
                break;
            }
        }
}

void tiene_salamandra(int dados[], bool& tiene_salamandra, int id_jugador, string estatuillas_jugadores[5][2])
{   
int i=0, max_filas=5;

for(i;i<max_filas;i++){
            if(estatuillas_jugadores[i][id_jugador]=="SALAMANDRA"){
                tiene_salamandra = true;
                break;
            }
        }
}