#include <iostream>
#include "Red.h"

int main() {
    Red red;

    red.agregarEnrutador('A');
    red.agregarEnrutador('B');
    red.agregarEnrutador('C');
    red.agregarEnrutador('D');

    red.agregarConexion('A', 'B', 4);
    red.agregarConexion('A', 'C', 10);
    red.agregarConexion('A', 'D', 5);
    red.agregarConexion('B', 'D', 1);
    red.agregarConexion('C', 'D', 2);

    red.calcularTablas();

    red.imprimirTopologia();
    red.imprimirTablas();

    red.imprimirCamino('A', 'B');
    red.imprimirCamino('A', 'C');
    red.imprimirCamino('A', 'D');

    cout << "\n--- Eliminando conexion A-C ---\n\n";
    red.eliminarConexion('A', 'C');
    red.imprimirTopologia();
    red.imprimirTablas();
    red.imprimirCamino('A', 'C');

    return 0;
}
