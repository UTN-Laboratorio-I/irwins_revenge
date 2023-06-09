#include "../src/modulos/juego/turnos/turnos.h"
using namespace std;
#include "../src/modulos/menu/nombre_jugadores.h"
#include "../src/modulos/menu/menu.h"

int main()
{
    string jugadores[2] = {};
    int opcion;

    mostrar_menu();
    cin >> opcion;
    if (opcion == 1)
    {
        solicitar_nombres(jugadores);
    }

    asignarTurno();
    
    return 0;
}