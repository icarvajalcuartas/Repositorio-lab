#include"Integracion.h"
#include <iostream>
#include"Archivo.h"
#include"LZ78.h"
#include <fstream>
using namespace std;

void escribirArchivoChar(ofstream& archivo, const char* contenido1, const char* contenido2) {
    if (!archivo) {
        cout << "Error al escribir en el archivo." << endl;
        return;
    }
    archivo<<"Compresion:\n"<< contenido1<<"\n";
    archivo <<"Decompresion:\n"<< contenido2<<"\n";

}
void compresionLz78(ifstream &archivo)
{
    ofstream resultados("compresionlz78.txt");
    char* linea,*lineaDes;
    linea=lecturachar(archivo);
    if (linea!=nullptr){
        lineaDes=compressLZ78(linea,false);
        escribirArchivoChar(resultados,linea,lineaDes);
        if(comparacion(lineaDes,linea,false)){
            cout<<"Son iguales"<<endl;
        }
    }
}

void metodoCompresion(bool rle)
{
    ifstream archivoCompresion("integrar.txt");
    if(!rle){
        compresionLz78(archivoCompresion);
    }
}
