#ifndef INTEGRACION_H
#define INTEGRACION_H
#include <fstream>

void escribirArchivoChar(std::ofstream& archivo, const char* contenido1, const char* contenido2,
                         int tamanio, const char* comprimido);
void metRle();
void metLz78();
#endif // INTEGRACION_H
