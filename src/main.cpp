#include <iostream>
#include "modulos/juego/turnos/turnos.h"
#include "modulos/menu/menu.h"
using namespace std;

int main(){

    bool juego_activo = 1;
    
//Ejecutamos el programa mientras el juego esté activo:
    do{         
    mostrar_menu();
    }while(juego_activo);

    return 0;
}
