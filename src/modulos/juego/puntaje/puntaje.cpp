#include <iostream>
using namespace std;

int main (){


    const int puntos_victoria [6] = {5, 10, 15, 50,-3,-1};

    int acu_estatuilla = 0;
    int acu_estatuilla_primer_intento = 0;
    int acu_ganador = 0;
    int acu_ganador_sin_estatuillas = 0;
    int acu_rival_estatuilla = 0;
    int acu_lanzamiento = 0;
    int jugador1 = 0;
    int jugador2 = 0;
    int acu_puntajeJ1 = 0, acu_puntajeJ2 = 0;
    
    // acumula puntaje si gana 1 estatuilla en la ronda (falta incluir en estadistica)
    if (jugador1 == 1)
    {
        acu_puntajeJ1 += puntos_victoria[0];
        jugador1 = 0;
    }else{
        acu_puntajeJ2 += puntos_victoria[0];
    }

    // acumula puntaje si gana 1 estatuilla en el primer intento
    if (jugador1 == 1)
    {
        acu_puntajeJ1 += puntos_victoria[1];
        jugador1 = 0;
    }else{
        acu_puntajeJ2 += puntos_victoria[1];
    }

    // ganador fase final
    if (jugador1 == 1)
    {
        acu_puntajeJ1 += puntos_victoria[2];
        jugador1 = 0;
    }else{
        acu_puntajeJ2 += puntos_victoria[2];
    }

    // Ganador de la Fase Final sin estatuillas
    if (jugador1 == 1)
    {
        acu_puntajeJ1 += puntos_victoria[3];
    }else{
        acu_puntajeJ2 += puntos_victoria[3];
    }

    // Rival obtiene una estatuilla (- 3 puntos)
    if (jugador1 == 1)
    {
        acu_puntajeJ1 += puntos_victoria[4];
        jugador1 = 0;
    }else{
        acu_puntajeJ2 += puntos_victoria[4];
    }

    // Lanzamiento en la fase final (- 1 punto)
    if (jugador1 == 1)
    {
        acu_puntajeJ1 += puntos_victoria[4];
        jugador1 = 0;
    }else{
        acu_puntajeJ2 += puntos_victoria[4];
    }

    


    return 0;
}