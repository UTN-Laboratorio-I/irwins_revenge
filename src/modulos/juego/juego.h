#include <iostream>
#include "helpers/helpers.h"
#include "turnos/turnos.h"


void comenzarJuego(string jugadores[]){
int i=0, max=2;

    bool modo_admin = 0, primer_turno=1;
    int dado1, dado2, dado3, dado4, dado5, dado_6_caras=6, dado_10_caras=10;
    int fase=0;
    bool posee_salamandra;
    string turnos[2]={};
    
    solicitarNombresJugadores(jugadores, modo_admin);

    lanzarDados(modo_admin,fase, dado_10_caras, posee_salamandra, dado1, dado2, dado3, dado4, dado5);
    primerTurno(dado1, dado2, turnos, jugadores );
    
    for(i; i<max; i++){
        cout << turnos[i];
    }
    
}
