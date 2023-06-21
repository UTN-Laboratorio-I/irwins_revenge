#include <iostream>
using namespace std;

//Funcion que limpia los vectores de jugadores (ASIGNAR AL PRINCIPIO DEL JUEGO)
int contadores_jugadores_en_cero (int vPJ1[],int vPJ2 []);

//Vector que contiene los valores de los puntajes por HITO
int puntaje_de_hitos (int vec_puntos[6]);

//A esta funcion le pasamos los dos vectores de los 2 jugadores y nos retorna la matriz con los rusultados
int puntaje_jugadores( int vPJ1[],int vPJ2 [], int puntos_victoria[]);

/*//Funcion que contiene los contadores de los HITOS del jugador 1
int ganador_ronda_J1(int J1, int vPJ1[6]);

//Funcion que contiene los contadores de los HITOS del jugador 2
int ganador_ronda_J2(int J2, int vPJ2[6]);*/

//Funcion contabiliza la cantidad de estatuillas ganadas/perdidas (ASIGNAR EN ESTATUILLAS.H LINEA 107)
int cont_estatuilla(int vPJ1[], int vPJ2[], int pos);

//Funcion para fase final, descuenta 1 punto en el VEC[5] de cada jugador cada vez que lanza un dado (ASIGNAR EN LANZAMIENTO DE DADOS FASE FINAL)
//Falta determinar la variable posicion para que tome las posicion del jugador
int lanzamiento_fase_final (int vPJ1[], int vPJ2[], int pos);


//----------------------------------------------------------------------//

//REVISAR!!
int puntaje_jugadores(int vPJ1[],int vPJ2 [], int puntos_victoria[]){

    puntaje_de_hitos (puntos_victoria);

    int i;
    int puntaje_jugadores[6][2] = {{},{}};
    
    for(i=0;i<6;i++){
            puntaje_jugadores [i][0] = puntos_victoria [i] * vPJ1 [i];
            puntaje_jugadores [i][1] = puntos_victoria [i] * vPJ2 [i];    
    }


return puntaje_jugadores [6][2];
}


int puntaje_de_hitos (int vec_puntos[6]){
    vec_puntos [0] = 5;
    vec_puntos [1] = 10;
    vec_puntos [2] = 15;
    vec_puntos [3] = 50;
    vec_puntos [4] = -3;
    vec_puntos [5] = -1;

return vec_puntos[6];
}

int contadores_jugadores_en_cero (int vPJ1[],int vPJ2 []){
    int i;
        for (i=0;i<6;i++){
        vPJ1[i] = 0;
        vPJ2[i] = 0;
        }
    return vPJ1[6],vPJ2[6];
}

int cont_estatuilla(int vPJ1[], int vPJ2[], int pos){
    if (pos == 0){
        vPJ1[0] ++;
        vPJ2[4] ++;
    }else{
        vPJ1[4] ++;
        vPJ2[0] ++ ;
    }
return vPJ1[6], vPJ2[6];
}

int lanzamiento_fase_final (int vPJ1[], int vPJ2[], int pos){

    if (pos == 0){
        vPJ1[5] ++;
    }else{
        vPJ2[5] ++;
    }

return vPJ1[6], vPJ2[6];
}


/*int contador_puntaje_J1(int vPJ1[]){
    vPJ1[6] = {};
return vPJ1[6];
}

int contador_puntaje_J2(int vPJ2[]){
    vPJ2 [6] = {};
return vPJ2[6];
}*/