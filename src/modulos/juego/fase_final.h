#include <iostream>
#include <string>
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "estatuillas/estatuillas.h"
#include "../dados/dados.h"
#include "ganador_final.h"
using namespace std;

// Función que administra el juego por una estatuilla:
void jugar_fase_final(
    bool &modo_admin,
    string jugadores[],
    string turnos[],
    int dados[], int dado_6_caras,
    bool &fase_final)
{
    bool tiene_medusa = 0, tiene_salamandra = 0;
    // Declaramos la bandera de si los jugadores realizaron jugada:
    bool jugada_j1 = 0, jugada_j2 = 0;
    int i = 0, max = 2, turnoActual = 0, valor_formateado = 0;

    string jugador = ""; // Este define cual es el jugador que le toca tirar dado
                         //(Se define en setearParametrosJugada)

    // Iteramos por cada jugador dentro del array de turnos:
    for (i; i < max; i++)
    {
        bool ganador = 0;
        // Seteamos los parámetros según que jugador tenga turno:
        turnoActual = i;
        setearParametrosJugada(turnos, jugadores, jugada_j1, jugada_j2, jugador, turnoActual);

        /*simulamos acción lanzar dados (Apretar enter)*/
        lanzamientoManualDados(turnoActual, turnos);

        lanzarDados(modo_admin, dado_6_caras, false, dados, false);

        OrdenarDados(dados); // ordena los dados que se obtuvieron de menor a mayor

        // verificar_estatuillas(){}

        ganador = escalera(dados); // Si los dados ordenados forman escalera, ganador es true

        if (ganador)
        {
            cout << turnos[turnoActual] << " gano la partida al obtener escalera" << endl;
            fase_final = 1;
        }
    }
}
