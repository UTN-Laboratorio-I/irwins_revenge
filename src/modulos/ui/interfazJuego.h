#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


//LIMPIEZA DE LA CONSOLA:
void ClearConsole() {
  cout << "\x1b[2J\x1b[H";
}

//VISUALIZACIÓN DE INFORMACIÓN BÁSICA:
void basicGameInfo(string player1, string player2){
    cout << "***** IRWIN'S REVENGE *****" << endl;
    cout << "***** " << player1 << "                                    " << "***** " << player2 <<endl;
    cout << "________________________________________________________________" <<endl <<endl;
}

void showMessageAndClear(int tipo_mensaje, string message)
{
    //0 : selección de estatuilla
    //1 : 
    switch(tipo_mensaje){
        case 0:
            cout << message << std::endl;
            this_thread::sleep_for(chrono::seconds(5));
            ClearConsole();
            break;
        default:
            break;
    }
}