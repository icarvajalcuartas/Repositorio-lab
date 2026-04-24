#include <iostream>
#include"Archivo.h"
#include"RLE.h"
#include"OperacionB.h"
#include"LZ78.h"
#include"Integracion.h"
using namespace std;

int main()
{
    int metodo;
    cout << "(1) Compresion y decompresion con RLE.\n"
            "(2) Compresion y ddecompresin con ZL78 donde se elige la cadena de caracteres.\n"
            "(3) Compresion y decompresion con ZL78 donde se escogen 2 cadenas predeterminadas (pruebas)\n"
            "(4) Encriptacion y desencriptacion con operaciones binarias.\n"
            "(5) Compresion y decompresion de un archivo con RLE\n";
    cout<<"(6) Compresion y descompresion de un archivo con LZ78\n"<<endl;
    cout << "Ingrese un numero para seleccionar el metodo a utilizar:" << endl;
    cin>>metodo;
    cin.ignore();
    while(metodo>0){
        switch(metodo){
        case (1):{
            string texto;
            cout << "Ingrese texto: ";
                getline(cin, texto);
                string nombreArchivo = "resultado.txt";
                limpiarArchivo("resultado.txt");


                escribirArchivo(nombreArchivo, "--- ORIGINAL ---\n");
                escribirArchivo(nombreArchivo, texto + "\n\n");


                string comprimido = rleCompress(texto);
                escribirArchivo(nombreArchivo, "--- COMPRIMIDO ---\n");
                escribirArchivo(nombreArchivo, comprimido + "\n\n");


                string descomprimido = rleDecompress(comprimido);
                escribirArchivo(nombreArchivo, "--- DESCOMPRIMIDO ---\n");
                escribirArchivo(nombreArchivo, descomprimido + "\n\n");

                if(compararString(texto,descomprimido)){
                    cout<<"La descompresion produjo exitosamente el texto inicial."<<endl;
                }
                else{
                    cout<<"La descompresion no es igual al texto original"<<endl;
                }

                cout << "Proceso completado" << endl;
                break;
        }
        case (4):{
            char palabra[100]="";
            int n;
            cout<<"Ingrese la cadena que desea comprimir usando operadores binarios:"<<endl;
            cin.getline(palabra,100);
            cout<<"Ingrese un numero n para realizar la rotacion entre 0 y 7:"<<endl;
            cin>>n;
            if (n>=0&&n<=7){
                xorCipherPtr(palabra,'k',n,true);
                cout<<"\nEncriptado: "<<palabra<<endl;
                xorCipherPtr(palabra,'k',n,false);
                cout<<"Desencriptado: "<<palabra<<endl;
            }

            break;
        }
        case(2):{
            char text1[200]="";
            char* comprimido = nullptr;
            int x;
            cout<<"Ingrese el texto que desea encriptar:"<<endl;
            cin.getline(text1,200);
            compressLZ78(text1,true,comprimido,x);
            break;
        }
        case (3):{
            char texta[]="ABRACADABRARABARABARA";
            char textb[]="ABAABABAABBBBBBBBB";
            char sel;
            char* comprimido = nullptr;
            int x;
            cout<<"Escoja el texto que desea encriptar:"<<endl;
            cout<<"A: ABRACADABRARABARABARA"<<endl;
            cout<<"B: ABAABABAABBBBBBBBB"<<endl;
            cin>>sel;
            if(sel=='A'||sel=='a'){
                compressLZ78(texta,true,comprimido,x);
            }
            else if(sel=='B'||sel=='b'){
                compressLZ78(textb,true,comprimido,x);
            }
            break;
        }
        case(5):{
            metRle();
        }
        case(6):{
            metLz78();
            break;
        }
        default:
            break;
        }
        cout << "Ingrese un numero para seleccionar el metodo a utilizar:" << endl;
        cin>>metodo;
        cin.ignore();
    }
    return 0;
}
