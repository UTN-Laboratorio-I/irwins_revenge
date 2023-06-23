#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED
#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED
#ifndef BENDICIONES_H_INCLUDED
#define BENDICIONES_H_INCLUDED
// #include "Bendiciones/bendiciones.h"
#include <iostream>
#include <string>
// #include "turnos/turnos.h"
#include "ganadorfinal.h"
// #include "dados/dados.h"
using namespace std;

// Función que administra el juego por una estatuilla:
void jugar_fase_final(
    bool &modo_admin,
    string jugadores[],
    string turnos[],
    int dados[], int dado_6_caras,
    bool &fase_final,
    string estatuillas_jugadores[5][2], bool primerTiroJugadores[])
{

    // Declaramos la bandera de si los jugadores realizaron jugada:
    bool jugada_j1 = 0, jugada_j2 = 0;
    int i = 0, max = 2, turnoActual = 0, valor_formateado = 0;
    fase_final = 1;

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

        setearParametrosJugadaFaseFinal(turnos, jugadores, jugada_j1, jugada_j2, jugador, turnoActual, id_jugador);

        /*simulamos acción lanzar dados (Apretar enter)*/
        lanzamientoManualDados(turnoActual, turnos);

        lanzarDados(modo_admin, dado_6_caras, false, dados, false, false);

        OrdenarDados(dados); // ordena los dados que se obtuvieron de menor a mayor

        // verifica si el jugador actual tiene medusa para que su tirada tenga chance de ganar
        // por la regla de medusa y tambien para tirar dos veces los dados

        verificar_si_tiene_medusa(dados, tiene_medusa, id_jugador, estatuillas_jugadores);
        if (tiene_medusa)
        {
            if (tiene_medusa && primerTiroJugadores[turnoActual])
            {
                int tirar;
                cout << "¿Quiere tirar una segunda vez? (esta tirada reemplaza a la anterior)" << endl;
                cout << "1 - SI" << endl;
                cout << "2 - NO" << endl;
                cin >> tirar;
                if (tirar == 1)
                {
                    lanzarDados(modo_admin, dado_6_caras, false, dados, false, false);
                    OrdenarDados(dados);
                }
                setearPrimerTurno(turnos, jugadores, primerTiroJugadores, jugador, turnoActual);
            }
            ganador = dados_iguales_medusa(dados);
        }

        // verifica si el jugador actual tiene SALAMANDRA para que su tirada tenga chance de ganar
        // por la regla de salamandra
        verificar_si_tiene_salamandra(dados, tiene_salamandra, id_jugador, estatuillas_jugadores);

        if (tiene_salamandra && !ganador)
        {
            ganador = escalera_salamandra(dados);
        }
        // si no gano ni por salamandra ni por medusa, verifica que tenga escalera complea
        if (!ganador)
        {
            ganador = escalera_normal(dados); // Si los dados ordenados forman escalera, ganador es true
        }

        if (ganador)
        {
            cout << turnos[turnoActual] << " GANO LA PARTIDA!!" << endl;
            fase_final = 0;
            break;
        }
    }
}

#endif
#endif
#endif
