#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

// Esta funcion muestra el menu principal de juego

void mostrar_menu()
{
    cout << endl;
    cout << "IRWIN'S REVENGE" << endl;
    cout << "----------------------------" << endl;
    cout << " 1 - JUGAR" << endl;
    cout << " 2 - ESTADISTICAS" << endl;
    cout << " 3 - CREDITOS" << endl;
    cout << "----------------------------" << endl;
    cout << " 0 - SALIR" << endl << endl;
}

int seleccionarOpcionMenu(){
    int valor;
    cin >> valor;

    if(valor == 1 || valor == 2 || valor == 3 || valor ==0){
        return valor;
    }
}


#endif