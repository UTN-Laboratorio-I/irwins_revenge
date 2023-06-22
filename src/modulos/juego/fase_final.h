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
    bool &fase_final,
    string estatuillas_jugadores[5][2])
{

    // Declaramos la bandera de si los jugadores realizaron jugada:
    bool jugada_j1 = 0, jugada_j2 = 0;
    int i = 0, max = 2, turnoActual = 0, valor_formateado = 0;

    string jugador = ""; // Este define cual es el jugador que le toca tirar dado
                         //(Se define en setearParametrosJugada)
    int id_jugador;
    // Iteramos por cada jugador dentro del array de turnos:
    for (i; i < max; i++)
    {
        bool tiene_medusa = 0, tiene_salamandra = 0;
        bool ganador = 0;
        // Seteamos los parámetros según que jugador tenga turno:
        turnoActual = i;
        setearParametrosJugada(turnos, jugadores, jugada_j1, jugada_j2, jugador, turnoActual, id_jugador);

        /*simulamos acción lanzar dados (Apretar enter)*/
        lanzamientoManualDados(turnoActual, turnos);

        lanzarDados(modo_admin, dado_6_caras, false, dados, false);

        OrdenarDados(dados); // ordena los dados que se obtuvieron de menor a mayor

        // verifica si el jugador actual tiene medusa para que su tirada tenga chance de ganar
        // por la regla de medusa

        tiene_medusa(dados, tiene_medusa, id_jugador, estatuillas_jugadores);
        if (tiene_medusa)
        {
            ganador = dados_iguales_medusa(dados);
            if (ganador)
            {
                cout << turnos[turnoActual] << " gano la partida al obtener todos los numeros iguales" << endl;
                fase_final = 1;
                break;
            }
        }

        tiene_salamandra(dados, tiene_salamandra, id_jugador, estatuillas_jugadores);

        if (tiene_salamandra)
        {
            ganador = escalera_salamandra(dados);
            if (ganador)
            {
                cout << turnos[turnoActual] << " gano la partida al obtener escalera de 4 numeros" << endl;
                fase_final = 1;
                break;
            }
        }
        
        // si no gano ni por salamandra ni por medusa, verifica que tenga escalera complea
        ganador = escalera_normal(dados); // Si los dados ordenados forman escalera, ganador es true
        if (ganador)
        {
            cout << turnos[turnoActual] << " gano la partida al obtener escalera completa" << endl;
            fase_final = 1;
            break;
        }
    }
}
