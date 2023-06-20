#include <iostream>
#include "helpers/helpers.h"
#include "turnos/turnos.h"
#include "estatuillas/estatuillas.h"


void comenzarJuego(string jugadores[]){
int i=0, max=2;

    bool modo_admin = 0, fase_exp=0, fase_final=0;
    int dado1, dado2, dado3, dado4, dado5, dado_6_caras=6, dado_10_caras=10;
    int fase=0;
    bool posee_salamandra;

    string turnos[2]={};
    string cangrejo="CANGREJO", hormiga="HORMIGA", medusa="MEDUSA", aguila="AGUILA", salamandra="SALAMANDRA";
    string estatuillas_disponibles[]={cangrejo, hormiga, medusa, aguila, salamandra}
    
    solicitarNombresJugadores(jugadores, modo_admin);

    lanzarDados(modo_admin,fase, dado_10_caras, posee_salamandra, dado1, dado2, dado3, dado4, dado5);
    primerTurno(dado1, dado2, turnos, jugadores, fase_exp);
    
    do{
        seleccionarEstatuilla(jugadores, )
    }while(fase_exp);

    do{

    }while(fase_final)
    
}
