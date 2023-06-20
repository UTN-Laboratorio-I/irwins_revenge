#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Función para simular la tirada de dados:
void lanzarDados(int turno, string turnos[]){
    string lanzar;
    string jugador = turnos[turno];
    cout << jugador <<": PRESIONA ENTER PARA LANZAR DADOS!";
    cin >> lanzar;
}


// esta funcion lanza dados en funcion de los parametros del juego que se le pase, sirve para lanzar en cualquier momento
//la misma afecta a las variables declaradas en main

void lanzarDados(bool admin, int fase, int caras,bool salamadra, int &dado1, int &dado2, int &dado3, int &dado4, int &dado5)
{

    if (admin == false)
    {
        if (fase == 0)
        {
            do
            {
                dado1 = rand() % caras + 1;
                dado2 = rand() % caras + 1;
            } while (dado1 == dado2);
        }

        if (fase == 1)
        {
            if (salamadra == true)
            {
                dado1 = rand() % caras + 1;
                dado2 = rand() % caras + 1;
                dado3 = rand() % caras + 1;
            }
            else
            {
                dado1 = rand() % caras + 1;
                dado2 = rand() % caras + 1;
            }
        }

        if (fase == 2)
        {
            dado1 = rand() % caras + 1;
            dado2 = rand() % caras + 1;
            dado3 = rand() % caras + 1;
            dado4 = rand() % caras + 1;
            dado5 = rand() % caras + 1;
        }
    }
    else
    {
        if (fase == 0)
        {
            cout << "ingrese 2 dados: " << endl;
            cin >> dado1;
            cin >> dado2;
        }

        if (fase == 1)
        {
            if (salamadra == true)
            {
                cout << " (Maldicion salamandra) ingrese 3 dados: " << endl;
                cin >> dado1;
                cin >> dado2;
                cin >> dado3;
            }
            else
            {
                cout << "ingrese 2 dados: " << endl;
                cin >> dado1;
                cin >> dado2;
            }
        }

        if (fase == 2)
        {
            cout << "ingrese 5 dados: " << endl;
            cin >> dado1;
            cin >> dado2;
            cin >> dado3;
            cin >> dado5;
            cin >> dado5;
        }
    }
}