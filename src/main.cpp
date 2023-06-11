#include <iostream>
#include "modulos/juego/turnos/turnos.h"
#include "modulos/juego/dados/lanzamiento_dados.h"
using namespace std;

int main()
{
    int dados_exp[3] = {}, dados_final[5] = {}, i;
    int fase = 1;
    bool salamandra = true;

    resultado_dados(fase, salamandra, dados_exp, dados_final);

    for (i = 0; i < 3; i++)
    {
        cout << dados_exp[i] << endl;
    }

    for (i = 0; i < 5; i++)
    {
        cout << dados_final[i] << endl;
    }

    return 0;
}
