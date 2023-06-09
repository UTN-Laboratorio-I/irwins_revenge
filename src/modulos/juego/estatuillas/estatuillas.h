#include <iostream>
using namespace std;

//Selección de la estatuilla que jugará el jugador:
    //parámetros: número de jugador, nombre de jugador, estatuillas disponibles.
    string seleccionarEstatuilla(int jugador, string jugador_nombre, string* estatuillas_disponibles){
        int i =0;
        int temp =0;
        const int estatuillas_totales = 5;
        int estatuilla_seleccionada;
        string listado_seleccion_temp[estatuillas_totales]={};

        //Jugador que selecciona:
        cout << "JUGADOR " << jugador << " - " << jugador_nombre <<endl;
       
        //Cargamos el array temporal con las estatuillas disponibles:
        for(i; i < estatuillas_totales; i++ ){
            if(estatuillas_disponibles[i] != ""){
                listado_seleccion_temp[temp] = estatuillas_disponibles[i];
                cout << temp <<") " << estatuillas_disponibles[i] <<endl;
                temp++;
            }
        }

        //Selecciona y muestra estatuilla:
        cout << "Selecciona la estatuilla por la que jugarás: " <<endl <<endl;
        cin >> estatuilla_seleccionada;
        cout << "Seleccionaste " << listado_seleccion_temp[estatuilla_seleccionada] <<endl <<endl;
        cout << "###################" <<endl <<endl;;

        //Retornamos la estatuilla que fue seleccionada:
        return listado_seleccion_temp[estatuilla_seleccionada];
    }