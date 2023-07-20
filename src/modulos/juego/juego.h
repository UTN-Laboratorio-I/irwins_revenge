#include <iostream>
#include "../estadisticas/estadisticas.h"
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "ui/interfaz.h"
#include "estatuillas/estatuillas.h"
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
    //Variables maldiciones:
    string maldito_medusa_3_turnos="";
    int cont_turnos_maldicion_medusa = 3;
    int jugador_salamandra_3_dados=999;
    int jugador_doble_tiro_aguila =999;

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
     
        seleccionarEstatuilla(
            jugadores,
            turnos,
            turno,
            ronda,
            maldito_medusa_3_turnos,
            cont_turnos_maldicion_medusa,
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
            jugador_salamandra_3_dados,
            maldito_medusa_3_turnos,
            cont_turnos_maldicion_medusa,
            jugador_doble_tiro_aguila,
            estatuillas_seleccionadas,
            estatuillas_jugadores,
            estatuillas_disponibles,
            listado_estatuillas,
            dados,
            ordenEstatuillas);
        asignarTurno(turnos);        
        checkFinFaseExpedicion(estatuillas_disponibles, fase_exp);
        //Pasamos a la siguiente ronda:
        siguienteRonda(ronda);

        //Si finaliza la fase de expedición, mostramos el mensaje.
        if(!fase_exp){
            mostrarMensajeCambioFase();
        }
    } while (fase_exp);

    // mostrarMensajeCambioFase();
    // Fase final:
    // verificar primeros tiros de cada jugador
    bool primerTiroJugadores[2] = {1, 1};
    int dadoHormiga = 0, dadoAguila = 0;
    do
    {
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
                        dadoAguila
                        );
    } while (fase_final);

    // Carga todos los puntos recolectados del juego
    puntaje_jugadores_final(vPJ1 ,vPJ2 ,valor_hitos, puntaje_jugadores);

    // Muesta las estadisticas finales del juego
    mostrar_estadisticas(puntaje_jugadores, jugadores, ordenEstatuillas);
}
