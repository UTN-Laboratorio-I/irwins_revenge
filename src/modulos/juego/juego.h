#include <iostream>
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "estatuillas/estatuillas.h"


void comenzarJuego(string jugadores[]){
int i=0, max=2;

    bool modo_admin = 0, fase_exp=0, fase_final=0;
    int dados[5]={}, dado_6_caras=6, dado_10_caras=10;
    int fase=0, turno=0, cant_jugadores=2;
    bool posee_salamandra;
    bool primer_turno=1;
//Booleano utilizado cuando el J1 gana la misma estatuilla.
    bool j2_reseleccion_estatuilla=0;
    string estatuillas_jugadores[5][2]={};
    string estatuillas_seleccionadas[2]={};

    string turnos[2]={};
    string cangrejo="CANGREJO", hormiga="HORMIGA", medusa="MEDUSA", aguila="AGUILA", salamandra="SALAMANDRA";
    string estatuillas_disponibles[5]={cangrejo, hormiga, medusa, aguila, salamandra};
    
    solicitarNombresJugadores(jugadores, modo_admin);

    lanzarDados(modo_admin, dado_10_caras, posee_salamandra, dados, primer_turno);
    primerTurno(dados, turnos, jugadores, fase_exp, primer_turno);

//Fase expedición:
    do{
        seleccionarEstatuilla(turnos,estatuillas_disponibles, estatuillas_seleccionadas);

        bool pendiente_j1=1, pendiente_j2=1;
        while(pendiente_j1 && pendiente_j2){
            // if(pendiente)
        }

    //
        checkFinFaseExpedicion(estatuillas_disponibles, fase_exp);
    }while(fase_exp);

//Fase final:
    do{

    }while(fase_final);
    
}
