#include "../src/modulos/juego/turnos/turnos.h"
#include "../src/modulos/juego/estatuillas/estatuillas.h"
using namespace std;

int main(){
    int jugador1 = 1;
    int jugador2 = 2;
    int ronda = 0;
    asignarTurno(jugador1, jugador2);

    while(true){
        ronda = siguienteRonda(ronda);
        cout << ronda;
    }

    return 0;
}
