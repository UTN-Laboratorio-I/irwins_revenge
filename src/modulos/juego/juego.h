#include <iostream>
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "ui/interfaz.h"
#include "estatuillas/estatuillas.h"
#include "maldiciones/maldiciones.h"
#include "faseFinal/faseFinal.h"
using namespace std;

void comenzarJuego(
    string jugadores[],
    int puntaje_jugadores[6][2],
    string ordenEstatuillas[],
    int vPJ1[6], int vPJ2[6],
    int valor_hitos[6],
    int contador_estatuillas_seleccionadas[5][2],
    string nombre_ganador_fase_final
    )
{
    int i = 0, max = 2;
    bool modo_admin = 0, fase_exp = 0, fase_final = 0;
    int dados[5] = {}, dado_6_caras = 6, dado_10_caras = 10;
    int fase = 0, turno = 0, cant_jugadores = 2;
    bool posee_salamandra;
    bool primer_turno = 1;
    int ronda=1;
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
    ClearConsole();
    solicitarNombresJugadores(jugadores, modo_admin);

    // LanzarDados y primerTurno solo asignan el turno inicial (NO APLICAN PUNTOS).
    lanzarDados(modo_admin, dado_10_caras, posee_salamandra, dados, primer_turno, fase_exp);
    primerTurno(dados, turnos, jugadores, fase_exp, primer_turno);

    // Fase expedición:
    do
    {
        //Aguardamos 3 segundos,limpiamos la pantalla:
        //Mostramos el header del juego con la info de la partida:
        interfazGeneralJuego(fase_exp, jugadores, estatuillas_jugadores, turnos, turno, ronda, true);
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
            jugadores,
            turnos,
            turno,
            ronda,
            estatuillas_disponibles,
            estatuillas_seleccionadas,
            estatuillas_jugadores,
            false
        );


        // Una vez tenemos las estatuillas seleccionadas, los jugadores juegan por ellas:
        jugarPorEstatuilla(
            modo_admin,
            jugadores,
            turnos,
            turno,
            ronda,
            estatuillas_seleccionadas,
            estatuillas_jugadores,
            estatuillas_disponibles,
            maldicion_pendiente,
            listado_estatuillas,
            dados,
            ordenEstatuillas);
        asignarTurno(turnos);        
        checkFinFaseExpedicion(estatuillas_disponibles, fase_exp);
        //Pasamos a la siguiente ronda:
        siguienteRonda(ronda);
    } while (fase_exp);

    // mostrarMensajeCambioFase();
    // Fase final:
    // verificar primeros tiros de cada jugador
    bool primerTiroJugadores[2] = {1, 1};
    int dadoHormiga = 0, dadoAguila = 0;
    do
    {
        //Mostramos el cambio de fase:
        mostrarMensajeCambioFase();
             
        jugar_fase_final(
                        nombre_ganador_fase_final,
                        vPJ1,
                        vPJ2,
                        modo_admin,
                        jugadores,
                        turnos,
                        turno,
                        ronda,
                        dados,
                        dado_6_caras,
                        fase_final,
                        estatuillas_jugadores,
                        primerTiroJugadores, 
                        dadoHormiga,
                        dadoAguila);

    } while (fase_final);
}
