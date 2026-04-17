#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>
using namespace std;

string leerArchivo(const string& nombre);
void escribirArchivo(const string& nombre, const string& contenido);
void limpiarArchivo(const string& nombre);
bool compararString(string a, string b);

#endif // ARCHIVO_H
