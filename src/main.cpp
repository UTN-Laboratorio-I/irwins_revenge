#include <iostream>
#include "modulos/menu/menu.h"
#include "modulos/juego/juego.h"
#include "modulos/estadisticas/estadisticas.h"
#include "modulos/creditos/creditos.h"




using namespace std;

int main()
{
    bool juego_activo = 1;
    string jugadores[2] = {};
    int opcion_seleccionada;

    // Variables estadísticas:
    int puntaje_jugadores[6][2] = {};
    int acumuladores[2] = {};
    int puntaje_descontado[2] = {};
    srand(time(0));
    string ordenEstatuillas[5] = {};
    string nombre_ganador_fase_final;

    // Variables puntajes:
    //int vPJ1[6] = {};
    //int vPJ2[6] = {};
    //int valor_hitos[6] = {};
    puntos_de_hitos(valor_hitos);
    //int contador_estatuillas_seleccionadas[5][2] = {};

    do
    {
        mostrar_menu();
        opcion_seleccionada = seleccionarOpcionMenu();

        switch (opcion_seleccionada)
        {
        case 1:
            comenzarJuego(
                jugadores,
                puntaje_jugadores,
                ordenEstatuillas,
                vPJ1,
                vPJ2,
                valor_hitos,
                contador_estatuillas_seleccionadas,
                nombre_ganador_fase_final
                );
            break;
        case 2:
            mostrar_estadisticas(puntaje_jugadores, jugadores, ordenEstatuillas);
            break;
        case 3:
            mostrar_creditos();
            break;
        case 0:
            juego_activo = 0;
            break;

        default:
            break;
        }

        system("cls");
    } while (juego_activo);
    system("exit");
    return 0;
}