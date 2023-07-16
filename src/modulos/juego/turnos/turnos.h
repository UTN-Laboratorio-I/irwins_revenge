#include <iostream>
#include <string>
using namespace std;

// Función que otorga turno inicial de los jugadores según tirada de dados:
void primerTurno(int dados[], string turnos[], string jugadores[], bool &fase_exp, bool &primer_turno)
{
    // Si el primer dado (J1) es menor al 2do (J2), arranca el J1, y visceversa:
    if (dados[0] < dados[1])
    {
        turnos[0] = jugadores[0];
        turnos[1] = jugadores[1];
    }
    else
    {
        turnos[0] = jugadores[1];
        turnos[1] = jugadores[0];
    }
    cout << "DADOS DE LOS JUGADORES:" << endl;
    cout << jugadores[0] << " ["<< dados[0] <<"] - ["<<dados[1]<<"]" << jugadores[1] << endl << endl;
    cout << "----------------------------" << endl;
    cout << "Primer turno: " << turnos[0] << endl;
    cout << "Segundo turno: " << turnos[1] << endl;
    fase_exp = 1;
    primer_turno = 0;
}

// Función que modifica la ronda a su subsiguiente:
void siguienteRonda(int &ronda)
{
    ronda++;
}

// Función que va rotando los turnos a medida que avanzan las rondas:
void asignarTurno(string turnos[])
{
    string jugador_temp = turnos[0];
    turnos[0] = turnos[1];
    turnos[1] = jugador_temp;
}
// Detenemos fase exp. en caso de no haber más estatuillas disponibles:
void checkFinFaseExpedicion(string estatuillas_disponibles[], bool &fase_exp)
{
    int i = 0, max = 5;
    fase_exp = false;
    for (i; i < max; i++)
    {
        if (estatuillas_disponibles[i] != "")
        {
            // Si el bucle encuentra contenido en el array, entonces continua la fase exp:
            fase_exp = true;
            break;
        }
    }
}

// Setea quien es el que va a jugar primero sus dados, si J1 o J2 según el turno:
void setearParametrosJugada(
    string turnos[],
    string jugadores[],
    bool &jugada_j1, // Define si el j1 jugó su mano.
    bool &jugada_j2, // Define si el j2 jugó su mano.
    string &jugador,
    int &turnoActual)
{
    // Si el nombre del jugador corresponde, y no jugó, se le otorga la tirada:
    // EJEMPLO:
    // turnos=["PABLO", "FELIPE"];
    // jugada_j1 = false;

    if (turnos[turnoActual] == jugadores[0] && !jugada_j1)
    {
        jugador = turnos[turnoActual];
        jugada_j1 = true;
    }
    else if (turnos[turnoActual] == jugadores[1] && !jugada_j2)
    {
        jugador = turnos[turnoActual];
        jugada_j2 = true;
    }
}

void setearParametrosJugadaFaseFinal(
    string turnos[],
    string jugadores[],
    bool &jugada_j1, // Define si el j1 jugó su mano.
    bool &jugada_j2, // Define si el j2 jugó su mano.
    string &jugador,
    int &turnoActual,
    int &id_jugador)
{
    // Si el nombre del jugador corresponde, y no jugó, se le otorga la tirada:
    // EJEMPLO:
    // turnos=["PABLO", "FELIPE"];
    // jugada_j1 = false;

    if (turnos[turnoActual] == jugadores[0] && !jugada_j1)
    {
        jugador = turnos[turnoActual];
        jugada_j1 = true;
        id_jugador = 0;
    }
    else if (turnos[turnoActual] == jugadores[1] && !jugada_j2)
    {
        jugador = turnos[turnoActual];
        jugada_j2 = true;
        id_jugador = 1;
    }
}

void setearPrimerTurno(
    string turnos[],
    string jugadores[],
    bool primerTiroJugadores[],
    string &jugador,
    int &turnoActual)
{
    // convertimos en false el primero turno de la fase final de cada jugador, una vez jugada

    if (turnos[turnoActual] == jugadores[0] && primerTiroJugadores[0])
    {
        jugador = turnos[turnoActual];
        primerTiroJugadores[0] = false;
    }
    else if (turnos[turnoActual] == jugadores[1] && primerTiroJugadores[1])
    {
        jugador = turnos[turnoActual];
        primerTiroJugadores[1] = false;
    }
}