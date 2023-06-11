#include <iostream>
#include "modulos/juego/turnos/turnos.h"
#include "modulos/juego/dados/lanzamiento_dados.h"
#include "modulos/juego/dados/lanzamiento_inicial.h"
#include "modulos/menu/menu.h"
using namespace std;

int main()
{
    int opcion = -1;

    while (opcion != 0)
    {
        mostrar_menu();
        cin >> opcion;
    }

    return 0;
}
