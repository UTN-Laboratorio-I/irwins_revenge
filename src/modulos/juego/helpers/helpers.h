#include <iostream>
using namespace std;

//Se solicita los nombres a los jugadores
void solicitarNombresJugadores(string jugadores[],bool& modo_admin ){
    int numeroJugador, max=2, i=0;
    for(i; i<max;i++){
    string nombre;
    string nombre_admin = "LAB1";
    cout << "JUGADOR " << i+1 << " - INGRESE SU NOMBRE: ";
    cin >> nombre;
    jugadores[i] = nombre;

    if(nombre == nombre_admin && i == 0){
    modo_admin = true;     //En caso de J1 ser LAB1, se habilita modo admin.
    }
    }
}