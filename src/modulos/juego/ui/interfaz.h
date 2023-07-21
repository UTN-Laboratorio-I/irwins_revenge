#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// //SONIDOS:
// void sonidoMenuPrincipal(){
//     sndPlaySound("/src/assets/sounds/mixkit-arcade-mechanical-bling-210.wav", SND_ASYNC | SND_FILENAME | SND_LOOP);
//     std::this_thread::sleep_for(std::chrono::seconds(2));
// }



//LIMPIEZA DE LA CONSOLA:
void ClearConsole(bool delay=0) {
if(delay){
std::this_thread::sleep_for(std::chrono::seconds(3));
}
  cout << "\x1b[2J\x1b[H";
}

void mensajeConDelay(string mensaje){
    ClearConsole();
    cout << mensaje;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    ClearConsole();
}

void delaySinMensaje(int delay){
    std::this_thread::sleep_for(std::chrono::seconds(delay));
    ClearConsole();
}

void mostrarHeaderJuego(bool fase_exp, int ronda){
    string fase = fase_exp ? "FASE DE EXPEDICION" : "FASE FINAL";
    cout << "IRWIN'S REVENGE - " << fase<< "                    RONDA Nro: " << ronda<<endl;
    cout << "------------------------------------------------------------------------"<<endl;
    ;
}

string mostrarJugadorTurno(string nombre, string turnos[2], int turno){
    string juegaPrimero = "JUEGA PRIMERO";
    string juegaSegundo = "JUEGA SEGUNDO";
    if(nombre == turnos[turno]){
        return juegaPrimero;
    }else{
        return juegaSegundo;
    }
}


//VISUALIZACIÓN DE INFORMACIÓN BÁSICA:
void interfazGeneralJuego(
    bool fase_exp, 
    string jugadores[], 
    string estatuillas_jugadores[][2], 
    string turnos[], 
    int turno,
    int ronda,
    bool delay=0
    )
{
    //En caso de necesitarlo, aplicamos un delay:
    ClearConsole(delay);
    //Mostramos el header el juego:
    string estatuillas_jugador1, estatuillas_jugador2;
    string jug1=jugadores[0], jug2=jugadores[1];
    for(int i=0; i<5;i++){
        if (estatuillas_jugadores[i][0] !=""){
            estatuillas_jugador1 += " " + estatuillas_jugadores[i][0];
            if(i!=0 && estatuillas_jugadores[i+1][0] !=""){
                estatuillas_jugador1 += ", ";
            }
        }
        if (estatuillas_jugadores[i][1] !=""){
            estatuillas_jugador2 += " " + estatuillas_jugadores[i][1];
            if(i!=0 && estatuillas_jugadores[i+1][1] !=""){
                estatuillas_jugador2 += ", ";
            }
        }
    }
    mostrarHeaderJuego(fase_exp, ronda);
    cout << jugadores[0] << "                                             "<<mostrarJugadorTurno(jug1, turnos, turno) <<endl;
    cout << "Estatuillas: "<< estatuillas_jugador1 << endl;
    cout << "------------------------------------------------------------------------"<<endl;
    cout << jugadores[1] << "                                             "<<mostrarJugadorTurno(jug2, turnos, turno) <<endl;
    cout << "Estatuillas: "<< estatuillas_jugador2 << endl;
    cout << "------------------------------------------------------------------------"<<endl;
    cout << endl <<endl;
}

void mostrarMensajeCambioFase(){
    ClearConsole();
    cout << "IRWIN'S REVENGE  " << "                         " <<endl;
    cout << "------------------------------------------------------------------------"<<endl<<endl;
    cout << " - FINALIZA FASE DE EXPEDICION -" << endl;
     std::this_thread::sleep_for(std::chrono::seconds(2));
    ClearConsole();
    cout << "IRWIN'S REVENGE  " << "                         " <<endl;
    cout << "------------------------------------------------------------------------"<<endl<<endl;
    cout << " - COMIENZA FASE FINAL - JUGADORES PREPARENSE - " << endl;
     std::this_thread::sleep_for(std::chrono::seconds(3));
    ClearConsole();
}

string mensajeAleatorioVictoria(int num){
    switch(num){
        case 1:
            return ", los dados estan de tu lado! ";
            break;
        case 2:
            return ", steve te bendijo! ";
            break;
        case 3:
            return ", la fuerza es fuerte en ti! ";
            break;
        case 4:
            return ", increible jugada! ";
            break;
        case 5:
            return ", muy bien jugado! ";
            break;
    }
}

string mensajeAleatorioDerrota(int num){
    switch(num){
        case 1:
            return ", mejor suerte la proxima! ";
            break;
        case 2:
            return ", los dados no te beneficiaron! ";
            break;
        case 3:
            return ", intentalo nuevamente! ";
            break;
        case 4:
            return ", maldicion, no fue tu mejor jugada, ";
            break;
        case 5:
            return ", esa estatuilla no te pertenece! ";
            break;
    }
}

int format(string valor){
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

void mensajeEstatuillaAJugar(string turnos[], int turno, string estatuillas_seleccionadas[]){
    string estatuilla = estatuillas_seleccionadas[turno];
    string detalle;
    int valor_formateado = format(estatuillas_seleccionadas[turno]);

    switch(valor_formateado)
    {
        case 0:
            detalle=" - Uno de sus dados debe ser par y el otro impar -";
            break;
        case 1:
            detalle=" - Al menos dos dados deben ser menores a 5 - ";
            break;
        case 2:
            detalle=" - La suma de sus dados debe dar exactamente 7 - ";
            break;
        case 3:
            detalle=" - Dos de los dados lanzados deben devolver 1 y 10 - ";
            break;
        case 4:
            detalle= " - Los dados lanzados deberan ser consecutivos ascendentes - ";
            break;
        default:
            break;
    }
    cout << "Jugas por la estatuilla " << estatuilla <<endl;
    cout << detalle << endl<<endl;
}
#endif