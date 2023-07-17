#include <iostream>
#include "../ui/interfaz.h"
using namespace std;

//Se solicita los nombres a los jugadores
void solicitarNombresJugadores(string jugadores[],bool& modo_admin ){
    int numeroJugador, max=2, i=0;
    cout << "IRWIN'S REVENGE  " << "                        NUEVA PARTIDA " <<endl;
    cout << "------------------------------------------------------------------------"<<endl;
    for(i; i<max;i++){
    string nombre;
    string nombre_admin = "LAB1";
    string variante_nombre_admin = "lab1";
    cout << "JUGADOR " << i+1 << " - INGRESE SU NOMBRE: ";
    cin >> nombre;
    jugadores[i] = nombre;

    if(nombre == nombre_admin && i == 0 || nombre == variante_nombre_admin && i==0){
        modo_admin = true;     //En caso de J1 ser LAB1, se habilita modo admin.
        string mensaje = "- MODO ADMIN ACTIVADO -  (Puede cargar los dados manualmente)";
        mensajeConDelay(mensaje);
    }
    }
}
//Se utiliza para poder utilizar el valor string en un switch:
int formatearAInt(string valor){
    int id_estatuilla;

    if(valor == "CANGREJO"){
        id_estatuilla=0;
    }else if(valor == "HORMIGA"){
        id_estatuilla=1;
    }else if(valor=="MEDUSA"){
        id_estatuilla=2;
    }else if(valor=="AGUILA"){
        id_estatuilla=3;
    }else if(valor=="SALAMANDRA"){
        id_estatuilla=4;
    }
    return id_estatuilla;
}

