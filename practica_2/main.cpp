#include <iostream>
#include "Funciones.h"
using namespace std;
int main()
{
    int num_ej=0;
    cout << "Ingrese el numero del ejercicio: " << endl;
    cin>>num_ej;
    while (num_ej>0){
        string cadena;
        string separar;
        string cuadrado;
        string palabra;
        switch(num_ej){
        case(2):
            unsigned short int n;
            cout<<"Ingrese un numero n para la formación de arreglo con contador por letras: "<<endl;
            cin>>n;
            prob_2(n);
        break;
        case(3):
            int z;
            cout<<"Ingrese un numero z: "<<endl;
            cin>>z;
            for (int i=0;i<z;i++){
                cout<<mayus()<<endl;
            }
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            break;
        case (4):
            cout<<"Ingrese una secuencia de numeros:"<<endl;
            cin>>cadena;
            prob_4(cadena);
            cout<<" "<<endl;
            break;
        case (8):
            cout<<"Ingrese una cadena de caracteres compuesta de numeros y letras para separar: "<<endl;
            cin>>separar;
            prob_8(separar);
            break;
        case(12):
            int m;
            cout << "Ingrese n referenciando a la matriz cuadrada: ";
            cin >> m;
            prob_12(m);
            break;
        case(14):
            cout<<"A continuación la matriz de 5x5: "<<endl;
            prob_14();
            break;
        case (16):
            int mat;
            cout<<"Ingrese un numero n para calcular la cantidad de caminos posibles en una matriz nxn: "<<endl;
            cin>>mat;
            prob_16(mat);
            break;
        case (18):
            long long perm;
            cout<<"Ingrese un numero n para hallar la permutación lexicografica en esa posición para digitos entre 0 y 9:"<<endl;
            cin>>perm;
            cout<< "la permutacion numero "<<perm<<" es:"<<endl;
            prob_18(perm);
            break;
        case(10):
            char romano[20];
            cout<<"Ingrese un numero romano para saber su representación arabiga: "<<endl;
            cin >> romano;
            cout<<' ';
            int resultado;
            resultado= prob_10(romano);
            cout << resultado<<endl;
            break;
        case(6):
            cout<<"Ingrese una palabra: "<<endl;
            cin >> palabra;
            cout<<"Original: "<<palabra<<endl;
            prob_6(palabra);
            cout << " En mayuscula: "<<palabra<<endl;
            break;
        }
        cout << "Ingrese el numero del ejercicio: " << endl;
        cin>>num_ej;
    }
    return 0;
}
