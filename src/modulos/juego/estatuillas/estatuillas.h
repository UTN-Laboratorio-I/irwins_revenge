#include <iostream>
#include <string>
#include "../dados/dados.h"
#include "../puntaje/puntaje.h"
using namespace std;

// Selección de la estatuilla que jugará el jugador:
void seleccionarEstatuilla(
    string jugadores[],
    string turnos[], // Los turnos con los nombres de los jugadores.
    string estatuillas_disponibles[],
    string estatuillas_seleccionadas[],
    bool reseleccion_estatuilla = false, // Inicializamos en false por defecto
    string jugador = ""                  // Inicializamos "" por defecto.
)
{
    const int estatuillas_totales = 5, cant_jugadores = 2;
    int estatuilla_seleccionada = 0;

    // Si no es reselección de estatuilla, seleccionan ambos jugadores:
    if (!reseleccion_estatuilla)
    {
        int e = 0, j = 0;
        // Limpiamos la selección previa de estatuillas de cada jugador:
        for (e; e < 2; e++)
        {
            if (estatuillas_seleccionadas[e] != "")
            {
                estatuillas_seleccionadas[e] = "";
            }
        }

        // Iteramos por cada jugador:
        for (j; j < cant_jugadores; j++)
        {
            int temp = 0;
            // Mostramos el jugador que selecciona:
            cout << "----------------------------" << endl;
            cout << "Jugador: " << turnos[j] << endl;

            // Cargamos el array temporal con las estatuillas disponibles:
            for (int i = 0; i < estatuillas_totales; i++)
            {
                if (estatuillas_disponibles[i] != "")
                {
                    cout << i << ") " << estatuillas_disponibles[i] << endl;
                }
            }

            // El jugador selecciona la estatuilla por la que jugará:
            cout << "Selecciona la estatuilla por la que jugarás: " << endl
                 << endl;
            cin >> estatuilla_seleccionada;
            cout << "Seleccionaste " << estatuillas_disponibles[estatuilla_seleccionada] << endl
                 << endl;

            // Asignamos la estuilla en el correspondiente array:
            estatuillas_seleccionadas[j] = estatuillas_disponibles[estatuilla_seleccionada];
            jugador = turnos[j];
        //Esta funcion cuenta la cantidad de veces que el jugador selecciona una estatuilla
        contador_seleccion_estatuilla(contador_estatuillas_seleccionadas, estatuillas_seleccionadas,estatuillas_disponibles, jugador ,turnos, jugadores);
        }
    }
    else
    {
        for (int i = 0; i < estatuillas_totales; i++)
        {
            if (estatuillas_disponibles[i] != "")
            {
                cout << i << ") " << estatuillas_disponibles[i] << endl;
            }
        }
        // El jugador selecciona la estatuilla por la que jugará:
        cout << "Selecciona una nueva estatuilla: " << endl
             << endl;
        cin >> estatuilla_seleccionada;
        cout << "Seleccionaste " << estatuillas_disponibles[estatuilla_seleccionada] << endl
             << endl;

        // Asignamos la estuilla al jugador que re-seleccionó
        estatuillas_seleccionadas[1] = estatuillas_disponibles[estatuilla_seleccionada];
        //Esta funcion cuenta la cantidad de veces que el jugador selecciona una estatuilla
        contador_seleccion_estatuilla(contador_estatuillas_seleccionadas, estatuillas_seleccionadas,estatuillas_disponibles, jugador ,turnos, jugadores);
    }
}

void agregar(
    string estatuillas_jugador1[],
    string estatuilla)
{
    int i = 0, max = 5;
    for (i; i < max; i++)
    {
        if (estatuillas_jugador1[i] == "")
        {
            estatuillas_jugador1[i] == estatuilla;
            break;
        }
    }
}

void asignarEstatuillaAJugador(int id_jugador, string estatuilla, string estatuillas_jugadores[5][2], int vPJ1[], int vPJ2[], int contador_estatuillas_seleccionadas[][2])
{
    // i --> filas (estatuillas);
    // j --> utilizamos el id_jugador;
    int i = 0, max_filas = 5;

    /*Accedemos a las estatuillas del jugador:
        Si encontramos un espacio vacío, asignamos la
        estatuilla y salimos del iterador con break;
    */
    for (i; i < max_filas; i++)
    {
        if (estatuillas_jugadores[i][id_jugador] == "")
        {
            estatuillas_jugadores[i][id_jugador] = estatuilla;
            break;
        }
    }
    //Esta funcion suma puntos cada vez que un jugador gana una estatuilla y descuenta puntos al rival
    contador_obtener_estatuilla(vPJ1, vPJ2, estatuillas_jugadores,id_jugador, estatuilla);
}


// Guardamos la estatuilla y la eliminamos del array gral.
void eliminarEstatuilla(
    string estatuilla,
    string estatuillas_disponibles[])
{
    int i = 0, max = 5;
    bool reemplazada = 0;
    for (i; i < max; i++)
    {
        if (estatuillas_disponibles[i] == estatuilla)
        {
            estatuillas_disponibles[i] = estatuillas_disponibles[i + 1];
            reemplazada = true;
        }
        else if (reemplazada == 1 && i != max - 1)
        {
            estatuillas_disponibles[i] = estatuillas_disponibles[i + 1];
        }
        // Si llega al máximo del array [5], reemplaza por "" y no por el siguiente (Ya que sería [6]):
        estatuillas_disponibles[i] = (i == max - 1) ? "" : estatuillas_disponibles[i];
    }
    cout << endl
         << endl;
}

// Asignamos la estatuilla a jugador, y la eliminamos de disponibles:
void accionesEstatuillaGanada(
    string jugadores[],
    string estatuilla,
    string jug,
    string estatuillas_disponibles[],
    string estatuillas_jugadores[5][2],
    string ordenEstatuillas[])
{
    // id_jugador: La posición del jug. en el array jugadores; (Ex variable pos)
    int id_jugador;

    // Buscamos la posición del jugador en el array de jug.
    for (int i = 0; i < 2; i++)
    {
        if (jugadores[i] == jug)
        {
            id_jugador = i;
        }
    }
    asignarEstatuillaAJugador(id_jugador, estatuilla, estatuillas_jugadores, vPJ1, vPJ2, contador_estatuillas_seleccionadas);
    // Eliminamos la estatuilla del array de disponibles.
    eliminarEstatuilla(estatuilla, estatuillas_disponibles);

    for (int i = 0; i < 5; i++)
    {
        if (ordenEstatuillas[i] == "")
        {
            ordenEstatuillas[i] = estatuilla;
        }
    }
}

// Parametros para las funciones de "obtener_{nombre estatuilla}":

// Objetivo: Uno de sus dados debe ser par y el otro impar:
void obtener_cangrejo(
    string jugadores[],
    bool modo_admin,
    int turno,
    string turnos[],
    string estatuillas_disponibles[],
    int dados[],
    string estatuillas_jugadores[5][2],
    string ordenEstatuillas[])
{
    string estatuilla = "CANGREJO";
    // Banderas para chequear par/impar:
    bool par = 0;
    bool impar = 0;
    int i = 0;

    lanzarDados(modo_admin, 10, false, dados, false, true);

    for (i; i < 2; i++)
    {
        if (dados[i] % 2 == 0)
        {
            par = true;
        }
        else
        {
            impar = true;
        }
    }
    if (par && impar)
    {
        cout << "GANASTE CANGREJO";
        string jug = turnos[turno]; // Nombre del jugador del turno que ganó.
        accionesEstatuillaGanada(jugadores, estatuilla, jug, estatuillas_disponibles, estatuillas_jugadores, ordenEstatuillas);
    }
}

// Objetivo: Al menos dos dados deben ser menores a 5.
void obtener_hormiga(
    string jugadores[],
    bool modo_admin,
    int turno,
    string turnos[],
    string estatuillas_disponibles[],
    int dados[],
    string estatuillas_jugadores[5][2],
    string ordenEstatuillas[])
{
    string estatuilla = "HORMIGA";
    //
    bool menores_a_cinco[2] = {0, 0}; // El array comienza con 2 falses.
    int i = 0;
    lanzarDados(modo_admin, 10, false, dados, false, true);

    // Acá definimos cuantos dados vamos a utilizar:
    for (i; i < 2; i++)
    {
        if (dados[i] < 5)
        {
            menores_a_cinco[i] = 1;
        }
    }
    if (menores_a_cinco[0] && menores_a_cinco[1])
    {
        cout << "GANASTE HORMIGA";
        string jug = turnos[turno];
        accionesEstatuillaGanada(jugadores, estatuilla, jug, estatuillas_disponibles, estatuillas_jugadores, ordenEstatuillas);
    }
}

// Objetivo: La suma de 2 de los dados lanzados debe dar exactamente 7.
void obtener_medusa(
    string jugadores[],
    bool modo_admin,
    int turno,
    string turnos[],
    string estatuillas_disponibles[],
    int dados[],
    string estatuillas_jugadores[5][2],
    string ordenEstatuillas[])
{
    string estatuilla = "MEDUSA";
    int resultado_esperado = 7, suma = 0; // El array comienza con 2 falses.
    int i = 0;
    lanzarDados(modo_admin, 10, false, dados, false, true);

    for (i; i < 2; i++)
    {
        suma += dados[i];
    }
    if (suma == resultado_esperado)
    {
        cout << "GANASTE MEDUSA";
        string jug = turnos[turno];
        accionesEstatuillaGanada(jugadores, estatuilla, jug, estatuillas_disponibles, estatuillas_jugadores, ordenEstatuillas);
    }
}

// Objetivo: Dos de los dados lanzados deberán devolver los números 1 y 10:
void obtener_aguila(
    string jugadores[],
    bool modo_admin,
    int turno,
    string turnos[],
    string estatuillas_disponibles[],
    int dados[],
    string estatuillas_jugadores[5][2],
    string ordenEstatuillas[])
{
    string estatuilla = "AGUILA";
    bool numero_uno = 0, numero_diez = 0;
    int i = 0;
    lanzarDados(modo_admin, 10, false, dados, false, true);

    for (i; i < 2; i++)
    {
        if (dados[i] == 1)
        {
            numero_uno = 1;
        }
        else if (dados[i] == 10)
        {
            numero_diez = 1;
        }
    }
    if (numero_uno && numero_diez)
    {
        cout << "GANASTE AGUILA";
        string jug = turnos[turno];
        accionesEstatuillaGanada(jugadores, estatuilla, jug, estatuillas_disponibles, estatuillas_jugadores, ordenEstatuillas);
    }
}

// Objetivo: Los dados lanzados deben ser consecutivos. Por ejemplo (1,2), (2,3), (9,10);
void obtener_salamandra(
    string jugadores[],
    bool modo_admin,
    int turno,
    string turnos[],
    string estatuillas_disponibles[],
    int dados[],
    string estatuillas_jugadores[5][2],
    string ordenEstatuillas[])
{
    string estatuilla = "SALAMANDRA";
    bool numeros_consecutivos = 0;
    lanzarDados(modo_admin, 10, false, dados, false, true);

    // calc1: Si el primer valor * 2 +1 es igual a la suma de los dos dados juntos, son consecutivos.
    int i = 0, calc1 = (dados[0] * 2 + 1), calc2 = dados[0] + dados[1];
    bool ecuacion1 = calc1 == calc2;

    if (ecuacion1)
    {
        numeros_consecutivos = true;
    }

    if (numeros_consecutivos)
    {
        cout << "GANASTE SALAMANDRA";
        string jug = turnos[turno];
        accionesEstatuillaGanada(jugadores, estatuilla, jug, estatuillas_disponibles, estatuillas_jugadores, ordenEstatuillas);
    }
}

// Función que administra el juego por una estatuilla:
void jugarPorEstatuilla(
    bool &modo_admin,
    string jugadores[],
    string turnos[],
    string estatuillas_seleccionadas[], // Las estatuillas que fueron seleccionadas por los jugadores.
    string estatuillas_jugadores[5][2], // Las estatuillas que ya ganaron los jugadores
    string estatuillas_disponibles[],
    string maldicion_pendiente[],
    string listado_estatuillas[],
    int dados[],
    string ordenEstatuillas[])
{
    // Declaramos la bandera de si los jugadores realizaron jugada:
    bool jugada_j1 = 0, jugada_j2 = 0;
    bool reseleccion_estatuilla = 0;
    int i = 0, max_jugadores = 2, max_estatuillas = 5, turnoActual = 0, valor_formateado = 0;

    string jugador = ""; // Este define cual es el jugador que le toca tirar dado (Se define en setearParametrosJugada)

    // Iteramos por cada jugador dentro del array de turnos:
    for (i; i < max_jugadores; i++)
    {
        // Si ambos jugadores eligieron la misma estatuilla, y uno de los 2 ya jugó
        // chequeamos que siga disponible.
        if (
            estatuillas_seleccionadas[0] == estatuillas_seleccionadas[1] // Si son iguales.
            &&                                                           // Y
            (jugada_j1 || jugada_j2)                                     // Si alguno de los 2 jugó.
        )
        {
            bool aun_disponible = false;
            int x = 0;
            for (x; x < max_estatuillas; x++)
            {
                // Buscamos si existe la estatuilla en el array de disponibles:
                if (estatuillas_disponibles[i] == estatuillas_seleccionadas[0])
                {
                    aun_disponible = true;
                }
            }
            if (!aun_disponible)
            {
                jugador = jugador == jugadores[0] ? jugadores[1] : jugadores[0];
                // Si no está disponible, es porque la ganó el otro jugador, tiene que seleccionar:
                cout << endl
                     << jugador << " debe re-seleccionar estatuilla:" << endl;

                seleccionarEstatuilla(
                    jugadores,
                    turnos,
                    estatuillas_disponibles,
                    estatuillas_seleccionadas,
                    reseleccion_estatuilla = 1,
                    jugador = turnos[1] // Le pasamos el jugador del 2do turno;
                );
            }
        }
        // Seteamos los parámetros según que jugador tenga turno:
        turnoActual = i;
        setearParametrosJugada(turnos, jugadores, jugada_j1, jugada_j2, jugador, turnoActual);

        /*simulamos acción lanzar dados (Apretar enter)*/
        lanzamientoManualDados(turnoActual, turnos);

        /**Valor_formateado es la representación en 'int' de
            cada estatuilla, para poder utilizar "string"
            dentro del switch, y ejecutar la jugada según
            la estatuilla seleccionada por el Jugador:
        */
        int valor_formateado = formatearAInt(estatuillas_seleccionadas[turnoActual]);

        switch (valor_formateado)
        {
        case 0:
            obtener_cangrejo(jugadores, modo_admin, turnoActual, turnos, estatuillas_disponibles, dados, estatuillas_jugadores, ordenEstatuillas);
            break;
        case 1:
            obtener_hormiga(jugadores, modo_admin, turnoActual, turnos, estatuillas_disponibles, dados, estatuillas_jugadores, ordenEstatuillas);
            break;
        case 2:
            obtener_medusa(jugadores, modo_admin, turnoActual, turnos, estatuillas_disponibles, dados, estatuillas_jugadores, ordenEstatuillas);
            break;
        case 3:
            obtener_aguila(jugadores, modo_admin, turnoActual, turnos, estatuillas_disponibles, dados, estatuillas_jugadores, ordenEstatuillas);
            break;
        case 4:
            obtener_salamandra(jugadores, modo_admin, turnoActual, turnos, estatuillas_disponibles, dados, estatuillas_jugadores, ordenEstatuillas);
            break;
        }
    }
}