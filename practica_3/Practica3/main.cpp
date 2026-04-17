#include <iostream>
#include"Archivo.h"
#include"RLE.h"
#include"OperacionB.h"
#include"LZ78.h"
using namespace std;

int main()
{
    int metodo;
    cout << "(1) Compresion y decompresion con RLE.\n"
            "(2) Compresion y ddecompresin con ZL78 donde se elige la cadena de caracteres.\n"
            "(3) Compresion y decompresion con ZL78 donde se escogen 2 cadenas predeterminadas (pruebas)\n"
            "(4) Encriptacion y desencriptacion con operaciones binarias." << endl;
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
            unsigned short int des;
            cout<<"Ingrese el texto que desea encriptar:"<<endl;
            cin.getline(text1,200);
            cout<<"Ingrese 1 si desea desencriptar y validar con el original, de lo contrario orpima 0:"<<endl;
            cin>>des;
            if(des==1){
                compressLZ78(text1,true);
            }
            else if(des==0){
                compressLZ78(text1,false);
            }
            break;
        }
        case (3):{
            char texta[]="ABRACADABRARABARABARA";
            char textb[]="ABAABABAABBBBBBBBB";
            char sel;
            cout<<"Escoja el texto que desea encriptar:"<<endl;
            cout<<"A: ABRACADABRARABARABARA"<<endl;
            cout<<"B: ABAABABAABBBBBBBBB"<<endl;
            cin>>sel;
            if(sel=='A'||sel=='a'){
                compressLZ78(texta,true);
            }
            else if(sel=='B'||sel=='b'){
                compressLZ78(textb,true);
            }
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
