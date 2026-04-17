#include <iostream>
#include "Archivo.h"
#include <fstream>
using namespace std;
string leerArchivo(const string& nombre) {
    ifstream archivo(nombre);

    string contenido = "", linea;

    while (getline(archivo, linea)) {
        contenido += linea;
    }

    archivo.close();
    return contenido;
}

void escribirArchivo(const string& nombre, const string& contenido) {
    ofstream archivo(nombre, ios::app);
    if (!archivo) {
        cout << "Error al crear el archivo: " << nombre << endl;
        return;
    }

    archivo << contenido;
    archivo.close();

    // cout << "Archivo creado: " << nombre << endl;

}
void limpiarArchivo(const string& nombre) {
    ofstream archivo(nombre, ios::trunc);
    archivo.close();
}

bool compararString(string a, string b)
{
    if (a==b){
        return true;
    }
    else{
        return false;
    }
}
