#include <iostream>
using namespace std;

/*//Funcion que limpia los vectores de jugadores (ASIGNAR AL PRINCIPIO DEL JUEGO)
int contadores_jugadores_en_cero (int vPJ1[6],int vPJ2[6]);*/

//Vector que contiene los valores de los puntajes por HITO
void puntaje_de_hitos (int vec_puntos[6]);

//A esta funcion le pasamos los dos vectores de los 2 jugadores y nos retorna la matriz con los rusultados
void puntaje_jugadores_final( int vPJ1[6],int vPJ2 [6], int puntos_victoria[6], int puntaje_jugadores[6][2]);

//Funcion contabiliza la cantidad de estatuillas ganadas/perdidas
void contador_obetener_estatuilla(int vPJ1[6], int vPJ2[6], string estatuillas_jugadores[5][2]);

//Funcion que retorna el puntaje del jugador en fase final a su vector correspondiente (falta variable para determinarla en el MAIN)
void ganador_fase_final(string ganador_fase_final, int vPJ1[6],int vPJ2[6], string jugadores[2]);

//Funcion que usa un for para encontrar si el array estatuillas_jugadores esta vacio, suma puntos al jugador correspondiente
void ganador_fase_final_sin_estatuillas(int vPJ1[6],int vPJ2[6], string estatuillas_jugadores[5][2],string jugadores[2], string ganador_fase_final);

//Funcion que cuenta los lanzamientos en la fase final.
void puntaje_lanzamiento_fase_final(bool &fase_final, string jugadores[2], int vPJ1[6], int vPJ2[6], string turnos[2]);

//Funcion que retorna el puntaje correspondiente a obtener estatuilla en el primer intento
void puntaje_estatuilla_primer_intento(int vPJ1[6], int vPJ2[6], int contador_estatuillas_seleccionadas[5][2]);

//Funcion que cuenta la cantidad de veces que se selecciono una estatuilla
void contador_seleccion_estatuilla(string estatuillas_seleccionadas[2], string estatuillas_jugadores[5][2], int contador_estatuillas_seleccionadas[5][2], string turnos[2], string jugadores[2]);



//----------------------------------------------------------------------//

//REVISAR!!
void puntaje_jugadores_final(int vPJ1[6],int vPJ2 [6], int puntos_victoria[6], int puntaje_jugadores[6][2]){
//1 +5 Estatuilla Obtenerunaestatuilla
//2 +10 Estatuilla++ Obtieneunaestatuillaenelprimerintentoporobtenerla
//3 +15 Ganador GanadordelaFaseFinal
//4 +50 Ganador++ GanadordelaFaseFinalsinestatuillas
//5 -3 Estatuilla-- Rivalobtieneunaestatuilla
//6 -1 Lanzamiento Lanzamientoenlafasefinal


    int i;
    
    for(i=0;i<6;i++){
            puntaje_jugadores [i][0] = puntos_victoria [i] * vPJ1 [i];
            puntaje_jugadores [i][1] = puntos_victoria [i] * vPJ2 [i];    
    }


}


void puntaje_de_hitos (int vec_puntos[6]){
    vec_puntos [0] = 5;
    vec_puntos [1] = 10;
    vec_puntos [2] = 15;
    vec_puntos [3] = 50;
    vec_puntos [4] = -3;
    vec_puntos [5] = -1;

}

/*int contadores_jugadores_en_cero (int vPJ1[6],int vPJ2 [6]){
    int i;
        for (i=0;i<6;i++){
        vPJ1[i] = 0;
        vPJ2[i] = 0;
        }
    return vPJ1[6],vPJ2[6];
}*/

void contador_obetener_estatuilla(int vPJ1[6], int vPJ2[6], string estatuillas_jugadores[5][2])
{

    int i, j;

    for (i = 0; i < 5; i++)
    {
        if (estatuillas_jugadores[i][0] != "")
        {
            vPJ1[0]++;
            vPJ2[4]++;
        }
        if (estatuillas_jugadores[i][1] != "")
        {
            vPJ1[4]++;
            vPJ2[0]++;
        }
    }
}

void ganador_fase_final (string ganador_fase_final, int vPJ1[6],int vPJ2[6], string jugadores[2]){

    if (ganador_fase_final == jugadores[0]){
        vPJ1[2] ++;
    }else{
        vPJ2[2] ++;
    }

}

void ganador_fase_final_sin_estatuillas(int vPJ1[6],int vPJ2[6], string estatuillas_jugadores[5][2],string jugadores[2], string ganador_fase_final){

    int i;
    int contador_J1 = 0;
    int contador_J2 = 0;

    for(i=0;i<5;i++){
        if(estatuillas_jugadores[i][0] == "" && jugadores[0] == ganador_fase_final){
            contador_J1 ++;
        }else if(estatuillas_jugadores[i][1] == "" && jugadores[1] == ganador_fase_final){
            contador_J2 ++;
        }
    }

    if(contador_J1>0){
        vPJ1[3]++;
    }else if(contador_J2>0){
        vPJ2[3]++;
    }

}

void puntaje_lanzamiento_fase_final(bool &fase_final, string jugadores[2], int vPJ1[6], int vPJ2[6], string turnos[2]){

    if (fase_final == true){
        if(turnos[0] == jugadores[0]){
            vPJ1[5] ++;
        }else{
            vPJ2[5] ++;
        }
    }

}


void puntaje_estatuilla_primer_intento(int vPJ1[6], int vPJ2[6], int contador_estatuillas_seleccionadas[5][2])
{

    int i;

    for (i = 0; i < 5; i++)
    {

        if (contador_estatuillas_seleccionadas[i][0] == 1)
        {
            vPJ1[1]++;
        }
        if (contador_estatuillas_seleccionadas[i][1] == 1)
        {
            vPJ2[1]++;
        }
    }
}




void contador_seleccion_estatuilla(string estatuillas_seleccionadas[2], string estatuillas_jugadores[5][2], int contador_estatuillas_seleccionadas[5][2], string turnos[2], string jugadores[2])
{

    int i, j;

    for (i = 0; i < 5; i++)
    {

        if (estatuillas_seleccionadas[0] == estatuillas_jugadores[i][0] && jugadores[0] == turnos[0])
        {
            contador_estatuillas_seleccionadas[i][0]++;
        }
        else if (estatuillas_seleccionadas[1] == estatuillas_jugadores[i][1] && jugadores[1] == turnos[0])
        {
            contador_estatuillas_seleccionadas[i][1]++;
        }

        if (estatuillas_seleccionadas[0] == estatuillas_jugadores[i][0] && jugadores[0] == turnos[1])
        {
            contador_estatuillas_seleccionadas[i][0]++;
        }
        else if (estatuillas_seleccionadas[1] == estatuillas_jugadores[i][1] && jugadores[1] == turnos[1])
        {
            contador_estatuillas_seleccionadas[i][1]++;
        }
    }
}

