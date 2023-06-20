#include <iostream>
using namespace std;

//Selección de la estatuilla que jugará el jugador:
    void seleccionarEstatuilla(string turnos[], string estatuillas_disponibles[], string estatuillas_seleccionadas[]){
        int e=0, j=0;
        const int estatuillas_totales = 5, cant_jugadores=2;
        string listado_seleccion_temp[estatuillas_totales]={};

//Limpiamos la selección previa:
        for(e; e<2;e++){
            if(estatuillas_seleccionadas[e]!=""){
                estatuillas_seleccionadas[e]="";     
            }
        }

     

//Iteramos por cada jugador:
        for(j;j<cant_jugadores;j++){
        int temp =0;
        int estatuilla_seleccionada=0;
    //Mostramos el jugador que selecciona:
        cout << "----------------------------" <<endl;
        cout << "Jugador: " << turnos[j] <<endl;

   //Limpiamos el array temporal de estatuillas:
        for (int g = 0; g < 5; g++) {
        listado_seleccion_temp[g] = "";
        }
    //Cargamos el array temporal con las estatuillas disponibles:
        for(int i=0; i < estatuillas_totales; i++ ){
            if(estatuillas_disponibles[i] != ""){
                string valor = estatuillas_disponibles[i];
                listado_seleccion_temp[temp] = estatuillas_disponibles[i];
                cout << temp << ") " <<valor <<endl;
                temp++;
            }
        }

    //El jugador selecciona la estatuilla por la que jugará:
        cout << "Selecciona la estatuilla por la que jugarás: " <<endl <<endl;
        cin >> estatuilla_seleccionada;
        cout << "Seleccionaste " << listado_seleccion_temp[estatuilla_seleccionada] <<endl <<endl;

    //Asignamos la estuilla en el correspondiente array:
        estatuillas_seleccionadas[j]=listado_seleccion_temp[estatuilla_seleccionada];
       }
    }




    void agregar(string estatuillas_jugador1[], string estatuilla){
        int i =0, max=5;
        for(i;i<max;i++){
            if(estatuillas_jugador1[i] == ""){
                estatuillas_jugador1[i] == estatuilla;
                break;
            }
        }
    }

    void asignarEstatuillaAJugador(int pos, string estatuilla){
       
        // switch(pos){
        //         case 0:
        //             agregar(estatuillas_jugador1, estatuilla);
        //             break;
        //         case 1:
        //             agregar(estatuillas_jugador1, estatuilla);
        //             break;
        //         default:
        //             break;
        //     }
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
    asignarEstatuillaAJugador(pos,estatuilla);
    //Eliminamos la estatuilla del array de disponibles.
    eliminarEstatuilla(estatuilla,estatuillas_disponibles);
    }

//VARIABLES PARA MAIN.CPP:

//Objetivo: Uno de sus dados debe ser par y el otro impar:
    void obtener_cangrejo(
    int tirada_dados_10_caras[], 
    int turno, string turnos[], 
    string jugadores[], 
    string estatuillas_disponibles[]){
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
            cout << "GANASTE CANGREJO";
            string jug = turnos[turno];
            asignarEstatuillaAdquirida(estatuilla, jugadores, jug, estatuillas_disponibles);
        }
    }

//Objetivo: Al menos dos dados deben ser menores a 5.
    void obtener_hormiga(
    int tirada_dados_10_caras[], 
    int turno, string turnos[], 
    string jugadores[], 
    string estatuillas_disponibles[]){
    string estatuilla = "HORMIGA";
        bool menores_a_cinco[2]={0,0};     //El array comienza con 2 falses.
        int i = 0;
        for(i; i<2; i++){
            if(tirada_dados_10_caras[i] < 5){
                menores_a_cinco[i]=1;
            }
        }
        if(menores_a_cinco[0] && menores_a_cinco[1]){
            cout << "GANASTE HORMIGA";
            string jug = turnos[turno];
            asignarEstatuillaAdquirida(estatuilla, jugadores, jug, estatuillas_disponibles);
        }
    }

//Objetivo: La suma de 2 de los dados lanzados debe dar exactamente 7.
    void obtener_medusa(
    int tirada_dados_10_caras[], 
    int turno, string turnos[], 
    string jugadores[], 
    string estatuillas_disponibles[]){
        string estatuilla = "MEDUSA";
        int resultado_esperado=7, suma=0;    //El array comienza con 2 falses.
        int i = 0;
        for(i; i<2; i++){
            suma+=tirada_dados_10_caras[i];
        }
        if(suma == resultado_esperado){
            cout << "GANASTE MEDUSA";
            string jug = turnos[turno];
            asignarEstatuillaAdquirida(estatuilla, jugadores, jug, estatuillas_disponibles);
        }
    }

//Objetivo: Dos de los dados lanzados deberán devolver los números 1 y 10:
    void obtener_aguila(
    int tirada_dados_10_caras[], 
    int turno, 
    string turnos[], 
    string jugadores[], 
    string estatuillas_disponibles[]){
       string estatuilla = "AGUILA";
        bool numero_uno=0, numero_diez=0;
        int i=0;
        for(i; i<2; i++){
            if(tirada_dados_10_caras[i]==1){
                numero_uno==1;
            }else if(tirada_dados_10_caras[i]==10){
                numero_diez==1;
            }
        }
        if(numero_uno && numero_diez){
            cout << "GANASTE AGUILA";
            string jug = turnos[turno];
            asignarEstatuillaAdquirida(estatuilla, jugadores, jug, estatuillas_disponibles);
        }
    }

//Objetivo: Los dados lanzados deben ser consecutivos. Por ejemplo (1,2), (2,3), (9,10);
    void obtener_salamandra(
    int tirada_dados_10_caras[], 
    int turno, string turnos[], 
    string jugadores[], 
    string estatuillas_disponibles[]){
        string estatuilla = "SALAMANDRA";
        bool numeros_consecutivos=0;
        int i=0, calc1=(tirada_dados_10_caras[0]*2+1), calc2=tirada_dados_10_caras[0]+tirada_dados_10_caras[1],calc3=tirada_dados_10_caras[0]-tirada_dados_10_caras[1];
        bool ecuacion1= calc1 == calc2, ecuacion2= calc3 == 1;
        
        if( ecuacion1 || ecuacion2){
            numeros_consecutivos=true;
        }

        if(numeros_consecutivos){
            cout << "GANASTE SALAMANDRA";
            string jug = turnos[turno];
            asignarEstatuillaAdquirida(estatuilla, jugadores, jug, estatuillas_disponibles);
        }
    }
