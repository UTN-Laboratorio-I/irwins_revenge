#include <iostream>
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "estatuillas/estatuillas.h"
#include "fase_final.h"

void comenzarJuego(string jugadores[])
{
    int i = 0, max = 2;

    bool modo_admin = 0, fase_exp = 0, fase_final = 0;
    int dados[5] = {}, dado_6_caras = 6, dado_10_caras = 10;
    int fase = 0, turno = 0, cant_jugadores = 2;
    bool posee_salamandra;
    bool primer_turno = 1;
    // Booleano utilizado cuando el J1 gana la misma estatuilla.
    bool j2_reseleccion_estatuilla = 0;
    string estatuillas_jugadores[5][2] = {};

    string estatuillas_seleccionadas[2] = {}; // Estatuillas que seleccionaron en seleccionarEstatuilla();

    string cangrejo = "CANGREJO", hormiga = "HORMIGA", medusa = "MEDUSA", aguila = "AGUILA", salamandra = "SALAMANDRA";
    string listado_estatuillas[5] = {cangrejo, hormiga, medusa, aguila, salamandra};
    string estatuillas_disponibles[5] = {cangrejo, hormiga, medusa, aguila, salamandra};

    string turnos[2] = {}; // turnos = ["PABLO", "FELIPE"] --> Si rotan los turnos es: = ["FELIPE", "PABLO"];

    solicitarNombresJugadores(jugadores, modo_admin);

    // LanzarDados y primerTurno solo asignan el turno inicial (NO APLICAN PUNTOS).
    lanzarDados(modo_admin, dado_10_caras, posee_salamandra, dados, primer_turno);
    primerTurno(dados, turnos, jugadores, fase_exp, primer_turno);

    // Fase expedición:
    do
    {
        seleccionarEstatuilla(turnos, estatuillas_disponibles, estatuillas_seleccionadas);

        // Una vez tenemos las estatuillas seleccionadas, los jugadores juegan por ellas:
        jugarPorEstatuilla(
            modo_admin,
            jugadores,
            turnos,
            estatuillas_seleccionadas,
            estatuillas_jugadores,
            estatuillas_disponibles,
            listado_estatuillas,
            dados);

        //
        checkFinFaseExpedicion(estatuillas_disponibles, fase_exp);
        asignarTurno(turnos);
    } while (fase_exp);

    // Fase final:
    do
    {

        jugar_fase_final(modo_admin, jugadores, turnos, dados, dado_6_caras, fase_final);


    } while (fase_final);
}
