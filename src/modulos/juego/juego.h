#include <iostream>
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "estatuillas/estatuillas.h"


void comenzarJuego(string jugadores[]){
int i=0, max=2;

    bool modo_admin = 0, fase_exp=0, fase_final=0;
    int dado1, dado2, dado3, dado4, dado5, dado_6_caras=6, dado_10_caras=10;
    int fase=0, turno=0, cant_jugadores=2;
    bool posee_salamandra;
    string estatuillas_seleccionadas[2]={};

    string turnos[2]={};
    string cangrejo="CANGREJO", hormiga="HORMIGA", medusa="MEDUSA", aguila="AGUILA", salamandra="SALAMANDRA";
    string estatuillas_disponibles[5]={cangrejo, hormiga, medusa, aguila, salamandra};
    
    solicitarNombresJugadores(jugadores, modo_admin);

    lanzarDados(modo_admin,fase, dado_10_caras, posee_salamandra, dado1, dado2, dado3, dado4, dado5);
    primerTurno(dado1, dado2, turnos, jugadores, fase_exp);

//Fase expedición:
    do{
        seleccionarEstatuilla(turnos,estatuillas_disponibles, estatuillas_seleccionadas);

        for(int i=0; i<cant_jugadores; i++ ){
            
        }
        
    }while(fase_exp);

//Fase final:
    do{

    }while(fase_final);
    
}
