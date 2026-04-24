#include"Integracion.h"
#include <iostream>
#include"Archivo.h"
#include"LZ78.h"
#include <fstream>
#include"RLE.h"
using namespace std;

void escribirArchivoChar(ofstream& archivo, const char* contenido1, const char* contenido2,
                         int tamanio, const char* comprimido) {
    if (!archivo) {
        cout << "Error al escribir en el archivo." << endl;
        return;
    }
    archivo<<"-----COMPRESIÓN-----\n";
    for(int i = 0; i<tamanio; i += 2){
        int indice = (unsigned char)comprimido[i];
        char caracter = comprimido[i+1];
        archivo << "(" << indice << ", '" << caracter << "')\n";
    }
    archivo <<"-----DESCOMPRESIÓN-----\n"<< contenido2<<"\n";
    archivo <<"-----ORIGINAL-----\n"<< contenido1<<"\n";

}
void compresionLz78(ifstream &archivo)
{
    try{
        ofstream resultados("compresionlz78.txt");
        if(!resultados){
            throw 1;
        }
        if (!archivo) {
            throw 2;
        }
        int numeroLinea = 0;

        while (!archivo.eof()) {
            try{
            char* linea = lecturachar(archivo);

            if (linea == nullptr || linea[0] == '\0') {
                if (linea != nullptr){
                delete[] linea;
                throw 3;
                }
                break;
            }

            numeroLinea++;
            resultados << "\n========== LÍNEA " << numeroLinea << " ==========\n";

            char* comprimido = new char[200];
            int tamanio = 0;
            char* lineaDes = nullptr;

            lineaDes = compressLZ78(linea, false, comprimido, tamanio);
            if(lineaDes==nullptr){
                throw 4;
            }
            escribirArchivoChar(resultados, linea, lineaDes, tamanio, comprimido);

                if (comparacion(lineaDes, linea, false)) {
                    resultados << "-----COMPARACIÓN-----\nSon iguales\n";
                } else {
                    resultados << "-----COMPARACIÓN-----\nNO son iguales\n";
                }
            delete[] comprimido;
            }
            catch (int excp) {
                switch (excp) {
                case 3:
                    cout << "Error: No se pudo leer la línea\n";
                    break;
                case 4:
                    cout << "Error: Fallo en la compresión\n";
                    break;
                default:
                    cout << "Error desconocido en procesamiento de línea\n";
                }
                continue;  // Continuar con la siguiente línea
            }
        }
        resultados.close();
    }
    catch (int excp) {
        switch (excp) {
        case 1:
            cout << "Error: No se pudo crear archivo de resultados\n";
            break;
        case 2:
            cout << "Error: No se pudo abrir archivo de entrada\n";
            break;
        default:
            cout << "Error desconocido\n";
        }
    }
    catch (...) {
        cout << "Excepción por defecto\n";
    }

}
void compresionrle(ifstream &archivo){
    try{
        ofstream resultados("compresionrle.txt");
        if (!archivo) {
            throw 1;
            return;
        }
        if(!resultados){
            throw 2;
        }
        string texto;
        cout<<texto<<endl;
        int numerolinea=0;
        while(getline(archivo,texto)){
            numerolinea++;
            resultados << "\n========== LÍNEA " << numerolinea << " ==========\n";
            resultados<<"--- ORIGINAL ---\n";
            resultados<<texto <<"\n\n";


            string comprimido = rleCompress(texto);
            resultados<< "--- COMPRIMIDO ---\n";
            resultados<< comprimido << "\n\n";


            string descomprimido = rleDecompress(comprimido);
            resultados<< "--- DESCOMPRIMIDO ---\n";
            resultados<< descomprimido<< "\n\n";

            if(compararString(texto,descomprimido)){
                resultados<<"La descompresion produjo exitosamente el texto inicial.\n";
            }
            else{
                resultados<<"La descompresion no es igual al texto original.\n";
            }
        }
        resultados.close();
    }
    catch (int excp) {
        switch (excp) {
        case 1:
            cout << "Error: No se pudo crear archivo de integrar.txt\n";
            break;
        case 2:
            cout<<"Error: No se pudo abrir el archivo de compresionrle.txt\n";
            break;
        default:
            cout << "Error desconocido\n";
        }
    }
    catch(...){
        cout << "Excepción por defecto\n";
    }
}

void metRle()
{
    ifstream archivoCompresion("integrar.txt");
    compresionrle(archivoCompresion);
}

void metLz78()
{
    ifstream archivoCompresion("integrar.txt");
    compresionLz78(archivoCompresion);
}
