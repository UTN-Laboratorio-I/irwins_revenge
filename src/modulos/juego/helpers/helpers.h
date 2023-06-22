#include <iostream>
using namespace std;

// Se solicita los nombres a los jugadores
void solicitarNombresJugadores(string jugadores[], bool &modo_admin)
{
    int max = 2, i = 0;
    for (i; i < max; i++)
    {
        string nombre;
        string nombre_admin = "LAB1";
        cout << "JUGADOR " << i + 1 << " - INGRESE SU NOMBRE: ";
        cin >> nombre;
        jugadores[i] = nombre;

        if (nombre == nombre_admin && i == 0)
        {
            modo_admin = true; // En caso de J1 ser LAB1, se habilita modo admin.
        }
    }
}
// Se utiliza para poder utilizar el valor string en un switch:
int formatearAInt(string valor)
{
    int valor_entero;

    if (valor == "CANGREJO")
    {
        valor_entero = 0;
    }
    else if (valor == "HORMIGA")
    {
        valor_entero = 1;
    }
    else if (valor == "MEDUSA")
    {
        valor_entero = 2;
    }
    else if (valor == "AGUILA")
    {
        valor_entero = 3;
    }
    else if (valor == "SALAMANDRA")
    {
        valor_entero = 4;
    }
    return valor_entero;
}