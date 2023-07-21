#include <iostream>
using namespace std;
    
    int vPJ1[8] = {};
    int vPJ2[8] = {};
    int valor_hitos[8] = {};
    int puntaje_jugadores[8][2] = {};
    int contador_estatuillas_seleccionadas[5][2] = {};




//----------------------------------------------------------------------//

//REVISAR!!
void puntaje_jugadores_final(int vPJ1[],int vPJ2 [], int valor_hitos[], int puntaje_jugadores[][2]){
//1 +5 Estatuilla Obtenerunaestatuilla
//2 +10 Estatuilla++ Obtieneunaestatuillaenelprimerintentoporobtenerla
//3 +15 Ganador GanadordelaFaseFinal
//4 +50 Ganador++ GanadordelaFaseFinalsinestatuillas
//5 -3 Estatuilla-- Rivalobtieneunaestatuilla
//6 -1 Lanzamiento Lanzamientoenlafasefinal


    int i;
    
    for(i=0;i<8;i++){
            puntaje_jugadores [i][0] = valor_hitos [i] * vPJ1 [i];
            puntaje_jugadores [i][1] = valor_hitos [i] * vPJ2 [i];    
    }


}


void puntos_de_hitos (int valor_hitos[8]){
    valor_hitos [0] = 5;
    valor_hitos [1] = 10;
    valor_hitos [2] = 15;
    valor_hitos [3] = 50;
    valor_hitos [4] = -3;
    valor_hitos [5] = -1;
    valor_hitos [6] = -1;
    valor_hitos [7] = -1;
}

/*int contadores_jugadores_en_cero (int vPJ1[6],int vPJ2 [6]){
    int i;
        for (i=0;i<6;i++){
        vPJ1[i] = 0;
        vPJ2[i] = 0;
        }
    return vPJ1[6],vPJ2[6];
}*/


void ganador_fase_final (string ganador_fase_final, int vPJ1[6],int vPJ2[6], string jugadores[2]){

    if (ganador_fase_final == jugadores[0]){
        vPJ1[2] ++;
    }else{
        vPJ2[2] ++;
    }

}

void ganador_fase_final_sin_estatuillas(int vPJ1[6],int vPJ2[6], string estatuillas_jugadores[5][2],string jugadores[2], string nombre_ganador_fase_final){

    int i;
    bool J1_tiene_estatuillas = false;
    bool J2_tiene_estatuillas = false;

    for(i=0;i<5;i++){
        if(estatuillas_jugadores[i][0] != ""){
            J1_tiene_estatuillas = true;
        }
        if(estatuillas_jugadores[i][1] != ""){
            J2_tiene_estatuillas = true;
        }
    }

    if(J1_tiene_estatuillas == false && nombre_ganador_fase_final == jugadores[0]){
        vPJ1[3]++;
    }else if(J2_tiene_estatuillas == false && nombre_ganador_fase_final == jugadores[1]){
        vPJ2[3]++;
    }

}

void puntaje_lanzamiento_fase_final(int vPJ1[], int vPJ2[], int id_jugador){

    
    if(id_jugador == 0){
        vPJ1[5] ++;
    }else{
        vPJ2[5] ++;
    }
    
    /*if (fase_final == true){
        if(turnos[0] == jugadores[0]){
            vPJ1[5] ++;
        }else if(turnos[1] == jugadores[0]){
            vPJ1[5] ++;
        }
        if(turnos[0] == jugadores[1]){
            vPJ2[5] ++;
        }else if(turnos[1] == jugadores[1]){
            vPJ2[5] ++;
        }
    }*/

}

void contador_obtener_estatuilla (int vPJ1[], int vPJ2[], string estatuillas_jugadores[][2], int id_jugador, string estatuilla)
{

    int i, j;

    for (i = 0; i < 5; i++)
    {
        if (estatuillas_jugadores[i][0] != "" && id_jugador == 0 && estatuillas_jugadores[i][0] == estatuilla)
        {
            vPJ1[0]++;
            vPJ2[4]++;
        }
        if (estatuillas_jugadores[i][1] != "" && id_jugador == 1 && estatuillas_jugadores[i][1] == estatuilla)
        {
            vPJ1[4]++;
            vPJ2[0]++;
        }
    }
}

void puntaje_estatuilla_primer_intento(int vPJ1[], int vPJ2[], int contador_estatuillas_seleccionadas[][2], string estatuillas_jugadores[][2], string estatuilla)
{

    int i, j;
    bool estatuilla_ganada_j1 = false;
    bool estatuilla_ganada_j2 = false;

    for(j=0; j<5; j++){

        for (i = 0; i < 4; i++)
        {

            if (contador_estatuillas_seleccionadas[j][0] == 1 && estatuilla == estatuillas_jugadores[i][0] && estatuilla_ganada_j1 == false)
            {
                vPJ1[1]++;
                contador_estatuillas_seleccionadas[j][0] = 0;
                estatuilla_ganada_j1 = true;
                break;
            }
            if (contador_estatuillas_seleccionadas[j][1] == 1 && estatuilla == estatuillas_jugadores[i][1] && estatuilla_ganada_j2 == false)
            {
                vPJ2[1]++;
                contador_estatuillas_seleccionadas[j][1] = 0;
                estatuilla_ganada_j2 = true;
                break;
            }
        }
    }
}

void asignar_estatuilla_a_contador(string estatuilla_auxiliar, int contador_estatuillas_seleccionadas[][2], int id_jugador){

    if (estatuilla_auxiliar == "CANGREJO"){
        contador_estatuillas_seleccionadas[0][id_jugador] ++;
    }else if(estatuilla_auxiliar == "HORMIGA"){
        contador_estatuillas_seleccionadas[1][id_jugador] ++;
    }else if(estatuilla_auxiliar == "MEDUSA"){
        contador_estatuillas_seleccionadas[2][id_jugador] ++;
    }else if(estatuilla_auxiliar == "AGUILA"){
        contador_estatuillas_seleccionadas[3][id_jugador] ++;
    }else if(estatuilla_auxiliar == "SALAMANDRA"){
        contador_estatuillas_seleccionadas[4][id_jugador] ++;
    }

}


void contador_seleccion_estatuilla(int contador_estatuillas_seleccionadas[][2], string estatuillas_seleccionadas[], string estatuillas_disponibles[], string jugador, string turnos[], string jugadores[])
{
        int i, j, z;
        int id_jugador;
        int id_turno;
        bool estatuilla_contada = false;
        string estatuilla_auxiliar;
        
        for(j=0; j<2; j++){
            
            if (jugadores[j] == jugador)
            {
                id_jugador = j;                
            }
            if (turnos[j] == jugador){
                id_turno = j;
            }
        }
            
        for(z=0; z<2; z++){

            for (i = 0; i < 5; i++)
            {
                if (estatuillas_seleccionadas[id_turno] == estatuillas_disponibles[i] && jugadores[id_jugador] == jugador && id_turno == z && estatuilla_contada == false)
                {   
                    estatuilla_auxiliar = estatuillas_seleccionadas[id_turno];

                    if(estatuilla_auxiliar == ""){
                        estatuilla_contada = true;
                        break;
                    }
                    
                    asignar_estatuilla_a_contador(estatuilla_auxiliar, contador_estatuillas_seleccionadas, id_jugador);
                    estatuilla_contada = true;
                    break;
                }
                /*else if (estatuillas_seleccionadas[j] == estatuillas_disponibles[i] && jugadores[j] == jugador && id_jugador == 1)
                {
                    contador_estatuillas_seleccionadas[i][1]++;

                    break;
                }*/

            }            
        }    
}

void descontar_puntos_maldicion_cangrejo (int id_jugador_afectado, int vPJ1[], int vPJ2[], int valor_hitos[], int valor_dado){

    if(id_jugador_afectado == 0){
        vPJ1[6] = valor_dado;
    }else if(id_jugador_afectado == 1){
        vPJ2[6] = valor_dado;
    }

}

void descontar_puntos_maldicion_hormiga (int id_jugador_afectado, int vPJ1[], int vPJ2[], int valor_hitos[], int valor_dado){

    if(id_jugador_afectado == 0){
        vPJ1[7] = valor_dado;
    }else if(id_jugador_afectado == 1){
        vPJ2[7] = valor_dado;
    }

}

void limpiar_puntaje ( int puntaje_jugadores[8][2], int vPJ1[8],int vPJ2[8],int contador_estatuillas_seleccionadas[5][2]){

    int i, j;

    for(i=0; i<8; i++){
        vPJ1[i] = {};
        vPJ2[i] = {};
        for(j=0; j<2; j++){
            puntaje_jugadores[i][j] = {};
            contador_estatuillas_seleccionadas[i][j] = {};
        }
    }

}