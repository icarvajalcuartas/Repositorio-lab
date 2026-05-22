#include <iostream>
#include "Red.h"
#include"Gestor.h"

void menuRed(Red& red) {
    unsigned short int n;
    cout <<"\nIngrese que desea realizar con la red:"
         <<"\n 1: Agregar enrutador"
         <<"\n 2: Agregar conexion"
         <<"\n 3: Imprimir topologia"
         <<"\n 4: Imprimir tabla de costos"
         <<"\n 5: Eliminar conexion"
         <<"\n 6: Imprimir camino entre 2 enrutadores"
         <<"\n 0: Volver al menu principal\n";
    cin>>n;

    while (n!=0) {
        switch (n) {
        case 1: {
            char id;
            cout<<"Identificador del enrutador: ";
            cin>>id;
            red.agregarEnrutador(id);
            break;
        }
        case 2: {
            char c1, c2; int costo;
            cout<<"Enrutador origen: ";
            cin>>c1;
            cout<<"Enrutador destino: ";
            cin>>c2;
            cout<<"Costo: ";
            cin>>costo;
            red.agregarConexion(c1, c2, costo);
            break;
        }
        case 3:
            red.imprimirTopologia();
            break;
        case 4:
            red.imprimirTablas();
            break;
        case 5: {
            char e1, e2;
            cout<<"Enrutador origen: ";
            cin>>e1;
            cout<<"Enrutador destino: ";
            cin>>e2;
            red.eliminarConexion(e1, e2);
            break;
        }
        case 6: {
            char cam1, cam2;
            cout << "Enrutador origen: ";
            cin>>cam1;
            cout<<"Enrutador destino: ";
            cin>>cam2;
            red.imprimirCamino(cam1, cam2);
            break;
        }
        default:
            cout << "Opcion invalida\n";
            break;
        }

        cout << "\nIngrese que desea realizar con la red:"
             << "\n 1: Agregar enrutador"
             << "\n 2: Agregar conexion"
             << "\n 3: Imprimir topologia"
             << "\n 4: Imprimir tabla de costos"
             << "\n 5: Eliminar conexion"
             << "\n 6: Imprimir camino entre 2 enrutadores"
             << "\n 0: Volver al menu principal\n";
        cin >> n;
    }
}

int main() {
    unsigned short int opt;

    do {
        cout <<"\n*** MENU PRINCIPAL ***"
             <<"\n 1: Crear red en consola"
             <<"\n 2: Cargar red desde archivo"
             <<"\n 0: Salir\n";
        cin>>opt;

        switch (opt){
        case 1:{
            Red red;
            menuRed(red);
            break;
        }
        case 2: {
            string nombreArchivo;
            cout<<"Nombre del archivo: ";
            cin>>nombreArchivo;
            Gestor gestor;

            Red* red =gestor.cargarRedDesdeArchivo(nombreArchivo);
            if (red){
                cout << "Red cargada exitosamente.\n";
                red->imprimirTopologia();
                menuRed(*red);
                delete red;
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Opcion invalida\n";
            break;
        }
    }
    while(opt!=0);
    cout<<"************FIN DEL PROGRAMA************"<<endl;

    return 0;
}
