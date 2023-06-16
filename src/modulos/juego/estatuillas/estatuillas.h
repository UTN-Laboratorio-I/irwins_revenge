#include <iostream>
using namespace std;

//Función para acomodar el array con las estatuillas disponibles:
    void reordenarEstatuillas(string ESTATUILLAS){
        
    }

//Selección de la estatuilla que jugará el jugador:
    //parámetros: número de jugador, nombre de jugador, estatuillas disponibles.
    string seleccionarEstatuilla(string jugadores[], string estatuillas_disponibles[]){
        int i =0;
        int temp =0;
        const int estatuillas_totales = 5;
        int estatuilla_seleccionada;
        string listado_seleccion_temp[estatuillas_totales]={};

        //Jugador que selecciona:
        // cout << "JUGADOR " << jugador << " - " << jugador_nombre <<endl;
       
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
        cout << "###################" <<endl <<endl;

        //Retornamos la estatuilla que fue seleccionada:
        return listado_seleccion_temp[estatuilla_seleccionada];
    }
    
    //Guardamos la estatuilla y la eliminamos del array gral.
    void guardarYEliminarEstatuilla(){

    }

//Asignamos la estatuilla al jugador que la ganó:
    void asignarEstatuillaAdquirida(string estatuilla, string jugadores[], string jug){
        int pos;
        for(int i =0; i<2;i++){                 //Buscamos la posición del jugador en el array de jug.
            if(jugadores[i]==jug){
                pos=i;                          //Asignamos la posición a la variable.
            }
        }

        switch(pos){                            
            case 0:
                break;
            case 1:
                break;
            default:
                break;
        }
    }

//VARIABLES PARA MAIN.CPP:
//CANGREJO:
    void obtener_cangrejo(int tirada_dados_10_caras[], int turno, string turnos[], string jugadores[]){
        string estatuilla = "CANGREJO";
        bool par=0;
        bool impar=0;
        int i = 0;
        for(i; i<2; i++){
            if (tirada_dados_10_caras[i]%2 == 0){
                par = true;
            }else{
                impar=true;
            }
        }
        if(par && impar){
            string jug = turnos[turno];
            asignarEstatuillaAdquirida(estatuilla, jugadores, jug);
        }
    }