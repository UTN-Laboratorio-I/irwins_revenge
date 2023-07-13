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
    string estatuillas_jugadores[5][2],
    bool primerTiroJugadores[],
    int &dadoHormiga,
    int &dadoAguila)
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
        bool tiene_medusa = 0, tiene_salamandra = 0, tiene_cangrejo = 0;
        bool ganador = 0, tiene_hormiga = 0, tiene_aguila = 0;
        // Seteamos los parámetros según que jugador tenga turno:
        turnoActual = i;

        setearParametrosJugadaFaseFinal(turnos, jugadores, jugada_j1, jugada_j2, jugador, turnoActual, id_jugador);

        // el jugador que tiene hormiga setea un dado para poder reemplazar luego
        verificar_si_tiene_hormiga(tiene_hormiga, id_jugador, estatuillas_jugadores);
        verificar_si_tiene_aguila(tiene_aguila, id_jugador, estatuillas_jugadores);
        if ((dadoHormiga == 0) && tiene_hormiga)
        {
            cout << "usted posee la bendicion de la hormiga. Elija un numero del 1 al 6" << endl;
            cout << "Elija numero: " << endl;
            cin >> dadoHormiga;
            cout << "Usted elijio:  " << dadoHormiga << ". podra usar este dado en el futuro" << endl;
            cout << endl;
        }

        /*simulamos acción lanzar dados (Apretar enter)*/
        lanzamientoManualDados(turnoActual, turnos);

        lanzarDados(modo_admin, dado_6_caras, false, dados, false, false);

        if (tiene_hormiga)
        {
            int opcionDado, opcion;
            cout << "Al tener la bendicion de la hormiga puede reemplazar uno de sus dados por: " << dadoHormiga << endl;
            cout << "¿Desea cambiar algun dado?" << endl;
            cout << " 1 - SI" << endl;
            cout << " 2 - NO" << endl;
            cin >> opcion;
            if (opcion == 1)
            {
                cout << "¿Cual dado desea cambiar? (elija entre 1 y 6)" << endl;
                for (int j = 0; j < 5; j++)
                {
                    cout << j + 1 << " - " << dados[j] << endl;
                }
                cin >> opcionDado;
                dados[opcionDado - 1] = dadoHormiga;
                cout << dados[opcionDado - 1] << endl;
            }
        }

        if (tiene_aguila)
        {
            int opcionDado, opcion;
            cout << "Al tener la bendicion de la hormiga puede reemplazar uno de sus dados por un numero entre 1 y 6" << endl;
            cout << "¿Desea cambiar algun dado?" << endl;
            cout << " 1 - SI" << endl;
            cout << " 2 - NO" << endl;
            cin >> opcion;
            if (opcion == 1)
            {
                cout << "¿Cual dado desea cambiar? (elija entre 1 y 6)" << endl;
                for (int j = 0; j < 5; j++)
                {
                    cout << j + 1 << " - " << dados[j] << endl;
                }
                cin >> opcionDado;
                cout << "Elija un numero entre 1 y 6 para reemplazar el dado: " << endl;
                cin >> dadoAguila;
                dados[opcionDado - 1] = dadoAguila;
                cout << dados[opcionDado - 1] << endl;
            }
        }

        OrdenarDados(dados); // ordena los dados que se obtuvieron de menor a mayor

        // verifica si el jugador actual tiene medusa para que su tirada tenga chance
        // de ganar
        // por la regla de medusa y tambien para tirar dos veces los dados

        verificar_si_tiene_cangrejo(tiene_cangrejo, id_jugador, estatuillas_jugadores);
        if (tiene_cangrejo)
        {
            if (tiene_cangrejo && primerTiroJugadores[turnoActual])
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

        // verifica si el jugador actual tiene SALAMANDRA para que su tirada
        // tenga chance de ganar
        // por la regla de salamandra
        verificar_si_tiene_salamandra(tiene_salamandra, id_jugador, estatuillas_jugadores);
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