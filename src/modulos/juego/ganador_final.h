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

bool escalera(int dados[])
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

void tiene_medusa()
{
}

void tiene_salamandra()
{
}