#include <iostream>
#include "modulos/menu/menu.h"
#include "modulos/juego/juego.h"
#include "modulos/estadisticas/estadisticas.h"
#include "modulos/creditos/creditos.h"
using namespace std;

int main()
{
    bool juego_activo=1;
    string jugadores[2]={};
    int opcion_seleccionada;
    int m[6][2]={};

    bool turno_jugador1 = false, turno_jugador2 = false; // estados de jugadores para los turnos
    int fase_exp = 1, fase_final = 2;                    // estado de las fases

    int estatuilla_seleccionada_j1, estatuilla_seleccionada_j2; // estatuillas que seleccionan los jugadores

    do{
        mostrar_menu();
        opcion_seleccionada = seleccionarOpcionMenu();

        switch (opcion_seleccionada)
        {
        case 1:
            comenzarJuego(jugadores);
            break;
        case 2:
            mostrar_estadisticas(m, jugadores);
            break;
        case 3:
            mostrar_creditos();
            break;
        case 0:
            juego_activo=0;
            break;

        default:
            break;
        }
        
        system("cls");
    }while(juego_activo);
    system("exit");
    return 0;
}