#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Función para simular la tirada de dados:
void lanzamientoManualDados(int& turno, string turnos[]){
    string lanzar;
    string jugador = turnos[turno];
    cout << jugador <<": PRESIONA ENTER PARA LANZAR DADOS!";
    cin >> lanzar;
}


// esta funcion lanza dados en funcion de los parametros del juego que se le pase, sirve para lanzar en cualquier momento
//la misma afecta a las variables declaradas en main
int valorAleatorio(int caras){
    return rand() % caras + 1;
}

void lanzarDados(bool& modo_admin, int caras, bool salamandra, int dados[], bool primer_turno)
{
    int i, tam = 5;
    if(primer_turno){
        bool distintos=0;
        do{
        for (i = 0; i < tam; i++)
        {
            dados[i] = valorAleatorio(caras);
        }
    //Si los dados son distintos, los tomamos y finalizamos la iteración:
        distintos = dados[0] == dados[1] ? 1 : 0;
        }while(distintos);
    //Pasamos a false el primer turno:
    }else{
    if (modo_admin == false)
    {
        for (i = 0; i < tam; i++)
        {
            dados[i] = rand() % caras + 1;
        }
    }
    else
    {
        cout << "ingrese los dados manualmente: " << endl;
        for (i = 0; i < tam; i++)
        {
            cin >> dados[i];
        }
    }
    }
}