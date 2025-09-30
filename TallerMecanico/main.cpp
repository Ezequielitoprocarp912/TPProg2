#include <iostream>
#include "clsVehiculo.h"
#include "clsGestorVehiculo.h"

using namespace std;

int main()
{
    clsVehiculo vehiculo;
    clsGestorVehiculo gestorVehiculo;
    gestorVehiculo.cargarUnVehiculo(vehiculo);
    gestorVehiculo.mostrarUnVehiculo(vehiculo);

    return 0;
}
