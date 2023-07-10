#include <iostream>
using namespace std;


/*CANGREJO:
Rival tira un dado de diez caras y el valor obtenido son los puntos
de victoria que se le DESCUENTAN al portador de la estatuilla al final
de la partida:
*/
void maldicion_cangrejo(
    int& contador_turnos_jugadores, 
    string maldicion_pendiente[],
    string jugadores[],
    int dados[],
    bool modo_admin    
    )
{
    int i=0, max=2, dado_10_caras=10;
    string jugador_rival;
    int id_jugador_afectado, valor_dado;

//Seleccionamos el jugador RIVAL al que ganó estatuilla cangrejo,
    if(maldicion_pendiente[1]==jugadores[0]){
        jugador_rival=jugadores[1];
        id_jugador_afectado=0;
    }else{
        jugador_rival=jugadores[0];
        id_jugador_afectado=1;

    }

    lanzarDados(modo_admin, dado_10_caras, false, dados, false, true);

//Valor del primer dado:
    valor_dado=dados[0];
//Descontamos puntos al jugador afectado:
    // puntaje_jugadores
}


/*
Rival tira 2 dados de 10 caras, valor obtenido se le descuenta al ganador de la estatuilla.
*/
void maldicion_hormiga(
    int& contador_turnos_jugadores, 
    string maldicion_pendiente[],
    string jugadores[],
    int dados[],
    bool modo_admin
    )
    {
        int i=0, max=2, dado_10_caras=10;
        string jugador_rival;
        int id_jugador_afectado, valor_dado;

    //Seleccionamos el jugador RIVAL al que ganó estatuilla cangrejo,
    //Y buscamos el id del jugador al que se le descontarán los puntos:
        if(maldicion_pendiente[1]==jugadores[0]){
            jugador_rival=jugadores[1];
            id_jugador_afectado=0;
        }else{
            jugador_rival=jugadores[0];
            id_jugador_afectado=1;
        }

        lanzarDados(modo_admin, dado_10_caras, false, dados, false, true);

    //Valor del primer dado:
        valor_dado= dados[0]+dados[1];
    //Descontamos puntos al jugador afectado:
        // puntaje_descontado[id_jugador_afectado]-=valor_dado;
}

void maldicion_medusa(int& contador_turnos_jugadores, string maldicion_pendiente){
    
}

// void maldicion_aguila(int& contador_turnos_jugadores, string maldicion_pendiente){

// }

// void maldicion_salamandra(int& contador_turnos_jugadores, string maldicion_pendiente){

// }



void administradorMaldiciones(
    bool& maldito, 
    string maldicion_pendiente[],
    int cont_turnos_maldicion,
    string jugadores[],
    int dados[],
    bool modo_admin
    )
    {
    int i=0, max=2, id_estatuilla;
    
    id_estatuilla=formatearAInt(maldicion_pendiente[0]);

     switch(id_estatuilla){
                case 0: //Cangrejo
           
                    maldicion_cangrejo(cont_turnos_maldicion, maldicion_pendiente, jugadores, dados, modo_admin);

                    break;
                case 1: //Hormiga
                    maldicion_hormiga(cont_turnos_maldicion, maldicion_pendiente, jugadores, dados, modo_admin);
                    break;
                case 2: //Medusa
                    break;
                case 3: //Aguila
                    break;
                case 4: //Salamandra
                    break;
            }
}