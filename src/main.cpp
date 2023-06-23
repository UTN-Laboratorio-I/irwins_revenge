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

//Variables estadísticas:
    int m[6][2]={};
    int acumuladores[2]={};
    int puntaje_descontado[2]={}
    srand(time(0));

    do{
        mostrar_menu();
        opcion_seleccionada = seleccionarOpcionMenu();

        switch (opcion_seleccionada)
        {
            case 1:
                comenzarJuego(
                    jugadores,
                    acumuladores,
                    puntaje_descontado
                );
                break;
            case 2:
                mostrar_estadisticas(m, jugadores, acumuladores);
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