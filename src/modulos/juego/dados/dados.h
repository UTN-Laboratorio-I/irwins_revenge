#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

/*lanzamientoManualDados unicamente simula el hecho de
"tirar" dados, al apretar la tecla ENTER*/
void lanzamientoManualDados(int turno, string turnos[])
{
    string lanzar;
    string jugador = turnos[turno];
    cout << jugador << ": PRESIONA ENTER PARA LANZAR DADOS!" << endl;
    getch();
}

// esta funcion lanza dados en funcion de los parametros del juego que se le pase, sirve para lanzar en cualquier momento
// la misma afecta a las variables declaradas en main
int valorAleatorio(int caras)
{
    return rand() % caras + 1;
}

void lanzarDados(bool &modo_admin, 
                int caras,
                bool salamandra,
                int dados[],
                bool primer_turno, 
                bool fase_exp)
{

    int i, cant_dados=2;
    
    //Definimos la cantidad de dados a utilizar:
    if(primer_turno){
        cant_dados=2;
    }
    else if(!fase_exp){
        cant_dados=5;
    }else if(salamandra){
        cant_dados=3;
    }

    // La variable primer_turno unicamente indica que los dados NO PUEDEN SER IGUALES:
    if (primer_turno)
    {
        bool distintos = 0;
        do
        {
            cout << "Lanzamiento de dados por el 1er turno:" <<endl;

            if(modo_admin==false){
                for (i = 0; i < cant_dados; i++)
                {
                    dados[i] = valorAleatorio(caras);
                }
            }else{
            cout << "Ingrese los "<<cant_dados<< " dados manualmente: " << endl;
                for (i = 0; i < cant_dados; i++)
                {
                    cin >> dados[i];
                }
            }
            // Si los dados son distintos, los tomamos y finalizamos la iteración:
            distintos = dados[0] == dados[1] ? 1 : 0;
        } while (distintos);
        // Pasamos a false el primer turno:
    }
    else
    {
        if (modo_admin == false)
        {
            for (i = 0; i < cant_dados; i++)
            {
                dados[i] = rand() % caras + 1;
            }
        }
        else
        {
            cout << "Ingrese los "<<cant_dados<< " dados manualmente: " << endl;
            for (i = 0; i < cant_dados; i++)
            {
                cin >> dados[i];
            }
        }
    //Mostramos los dados que corresponden mostrar:

    cout << endl;
    cout << "Sus dados: " << endl;
    for (i = 0; i < cant_dados; i++)
    {
        cout << dados[i];
        if(i != cant_dados-1){
            cout <<" - ";
        }        
    }
    cout << endl;
    }

}