#include <iostream>
using namespace std;


/*CANGREJO:
Rival tira un dado de diez caras y el valor obtenido son los puntos
de victoria que se le DESCUENTAN al portador de la estatuilla al final
de la partida:
*/
void maldicion_cangrejo(
    string jugadores[],
    int dados[],
    bool modo_admin,
    string jug  
    )
{
    int i=0, max=2, dado_10_caras=10;
    string jugador_rival,jugador_afectado;
    int id_jugador_afectado, id_jugador_rival, valor_dado;

//Seleccionamos el jugador RIVAL al que ganó estatuilla cangrejo,
    if(jugadores[0] == jug){
        id_jugador_afectado=0;
        id_jugador_rival=1;
        jugador_rival = jugadores[id_jugador_rival];
    }else{
        id_jugador_afectado=1;
        id_jugador_rival=0;
        jugador_rival = jugadores[id_jugador_rival];

    }

    jugador_afectado = jugadores[id_jugador_afectado];

    string mensaje_fuiste_maldito = jugador_afectado + ", fuiste maldito por la estatuilla CANGREJO!";
    string mensaje_tirar_dados = jugador_rival + ", tira un dado de 10 caras y restale puntos a " + jugador_afectado + "!";

    mensajeConDelay(mensaje_fuiste_maldito);
    mensajeConDelay(mensaje_tirar_dados);

    lanzamientoManualDados(0,jugadores, jugador_rival);
    lanzarDados(modo_admin, dado_10_caras, false, dados, false, true, true);

//Valor del primer dado:
    valor_dado=dados[0];

    string mensaje_puntaje = jugador_afectado.append(", CANGREJO te maldijo con -").append(to_string(valor_dado)).append(" puntos!");
    mensajeConDelay(mensaje_puntaje);
    
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

// void maldicion_medusa(int& contador_turnos_jugadores, string maldicion_pendiente){
    
// }

// void maldicion_aguila(int& contador_turnos_jugadores, string maldicion_pendiente){

// }

// void maldicion_salamandra(
//     string jugadores[],
//     int dados[],
//     bool modo_admin,
//     string jug,
//     int& jugador_maldito_salamandra
//     ){

//         cout << jugador_maldito_salamandra;
//     }



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
                    //La maldición la aplicamos en accionesEstatuillaGanada();
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