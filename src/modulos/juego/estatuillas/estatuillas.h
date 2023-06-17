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

    void asignarEstatuillaAJugador(int pos, string estatuilla){

    }
    //Guardamos la estatuilla y la eliminamos del array gral.
    void eliminarEstatuilla(string estatuilla, string estatuillas_disponibles[]){
            // for(int i = 0; i<5; i++){
        //         cout << estatuillas_disponibles[i] <<endl;

        // }
        int i = 0, max=5;
        bool reemplazada = 0;
        for(i; i<max; i++){
            if(estatuillas_disponibles[i]==estatuilla){
                estatuillas_disponibles[i] = estatuillas_disponibles[i+1];
                reemplazada=true;
            }else if(reemplazada==1 && i !=max-1){
                estatuillas_disponibles[i]=estatuillas_disponibles[i+1];
            }
            estatuillas_disponibles[i] = (i == max-1)? "" : estatuillas_disponibles[i];
        }
        cout << endl<<endl;
        // for(int i = 0; i<5; i++){
        // cout << estatuillas_disponibles[i]<<endl;
        // }
    }

//Asignamos la estatuilla al jugador que la ganó:
    void asignarEstatuillaAdquirida(string estatuilla, string jugadores[], string jug, string estatuillas_disponibles[]){
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
    //Eliminamos la estatuilla del array de disponibles.
    eliminarEstatuilla(estatuilla,estatuillas_disponibles);
    }

//VARIABLES PARA MAIN.CPP:
//CANGREJO:
    void obtener_cangrejo(int tirada_dados_10_caras[], int turno, string turnos[], string jugadores[], string estatuillas_disponibles[]){
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
            asignarEstatuillaAdquirida(estatuilla, jugadores, jug, estatuillas_disponibles);
        }
    }