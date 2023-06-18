#include <iostream>
using namespace std;

//Función para simular la tirada de dados:
void lanzarDados(int turno, string turnos[]){
    string lanzar;
    string jugador = turnos[turno];
    cout << jugador <<": PRESIONA ENTER PARA LANZAR DADOS!";
    cin >> lanzar;
}