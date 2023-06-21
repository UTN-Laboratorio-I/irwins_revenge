#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

/*lanzamientoManualDados unicamente simula el hecho de
"tirar" dados, al apretar la tecla ENTER*/
void lanzamientoManualDados(int turno, string turnos[]){
    string lanzar;
    string jugador = turnos[turno];
    cout << jugador <<": PRESIONA ENTER PARA LANZAR DADOS!" <<endl;
    getch();
}


// esta funcion lanza dados en funcion de los parametros del juego que se le pase, sirve para lanzar en cualquier momento
//la misma afecta a las variables declaradas en main
int valorAleatorio(int caras){
    return rand() % caras + 1;
}

void lanzarDados(bool& modo_admin, int caras, bool salamandra, int dados[], bool primer_turno)
{
    //!AÑADIR AL FINAL DE LA FUNCIÓN LA VISUALIZACIÓN
    //! DE LOS DADOS QUE FUERON ARROJADOS.
    int i, tam = 5;
    //La variable primer_turno unicamente indica que los dados NO PUEDEN SER IGUALES:
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