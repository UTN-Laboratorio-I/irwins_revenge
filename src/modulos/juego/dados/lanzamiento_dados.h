#include <iostream>
#include <string>
using namespace std;

// la funcion toma la fase y la estatuilla del jugador. Con eso define que dados tirar
void resultado_dados(int fase, bool salamandra /*aca no se si dejar string o int*/, int dados_exp[], int dados_final[])
{
    int i;
    dados_exp[3] = {};
    dados_final[5] = {};

    if (fase == 1) // Fase 1 seria la de expedicion, el else lanzaria por fase final
    {
        if (salamandra == true) // aca cambiaria por un numero que representa a la estatuilla o por un bool
        {
            for (i = 0; i < 3; i++)
            {
                dados_exp[i] = rand() % 10 + 1;
            }
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                dados_exp[i] = rand() % 10 + 1;
            }
        }
    }
    else // aca estan los lanzamiento de la fase final
    {
        for (size_t i = 0; i < 5; i++)
        {
            dados_final[i] = rand() % 6 + 1;
        }
    }

    // IMPORTANTE: DEFINIR COMO DEVOLVER LOS VALORES, CONSDIERO QUE ES MEJOR
    // HACER UN VECTOR Y ENVIAR LOS RESULTADOS CON ESTA FUNCION
}