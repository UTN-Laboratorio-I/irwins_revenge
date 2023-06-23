#include <iostream>
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "estatuillas/estatuillas.h"
#include "maldiciones/maldiciones.h"
#include "faseFinal/faseFinal.h"
using namespace std;

void comenzarJuego(
    string jugadores[],
    int m[6][2])
{
    int i = 0, max = 2;
    bool modo_admin = 0, fase_exp = 0, fase_final = 0;
    int dados[5] = {}, dado_6_caras = 6, dado_10_caras = 10;
    int fase = 0, turno = 0, cant_jugadores = 2;
    bool posee_salamandra;
    bool primer_turno = 1;
    // Cuando haya alguna maldición, acá registramos cual es la estatuilla y quien el rival.
    string maldicion_pendiente[2];
    bool maldito = maldicion_pendiente[0] != "";
    int cont_turnos_maldicion = 0;

    // Booleano utilizado cuando el J1 gana la misma estatuilla.
    string estatuillas_jugadores[5][2] = {};
    // Estatuillas que seleccionaron en seleccionarEstatuilla():
    string estatuillas_seleccionadas[2] = {};

    string cangrejo = "CANGREJO", hormiga = "HORMIGA", medusa = "MEDUSA", aguila = "AGUILA", salamandra = "SALAMANDRA";
    string listado_estatuillas[5] = {cangrejo, hormiga, medusa, aguila, salamandra};
    string estatuillas_disponibles[5] = {cangrejo, hormiga, medusa, aguila, salamandra};

    string turnos[2] = {}; // turnos = ["PABLO", "FELIPE"] --> Si rotan los turnos es: = ["FELIPE", "PABLO"];

    solicitarNombresJugadores(jugadores, modo_admin);

    // LanzarDados y primerTurno solo asignan el turno inicial (NO APLICAN PUNTOS).
    lanzarDados(modo_admin, dado_10_caras, posee_salamandra, dados, primer_turno, fase_exp);
    primerTurno(dados, turnos, jugadores, fase_exp, primer_turno);

    // Fase expedición:
    do
    {
        if (maldito)
        {
            administradorMaldiciones(
                maldito,
                maldicion_pendiente,
                cont_turnos_maldicion,
                jugadores,
                dados,
                modo_admin);
        }
        seleccionarEstatuilla(
            turnos,
            estatuillas_disponibles,
            estatuillas_seleccionadas);
        // Una vez tenemos las estatuillas seleccionadas, los jugadores juegan por ellas:
        jugarPorEstatuilla(
            modo_admin,
            jugadores,
            turnos,
            estatuillas_seleccionadas,
            estatuillas_jugadores,
            estatuillas_disponibles,
            maldicion_pendiente,
            listado_estatuillas,
            dados);

        asignarTurno(turnos);
        checkFinFaseExpedicion(estatuillas_disponibles, fase_exp);
    } while (fase_exp);

    mostrarMensajeCambioFase();
    // Fase final:
    // verificar primeros tiros de cada jugador
    bool primerTiroJugadores[2] = {1, 1};
    int dadoHormiga=0;
    do
    {
        
        jugar_fase_final(modo_admin,
                         jugadores,
                         turnos,
                         dados,
                         dado_6_caras,
                         fase_final,
                         estatuillas_jugadores,
                         primerTiroJugadores, 
                         dadoHormiga);

    } while (fase_final);
}
