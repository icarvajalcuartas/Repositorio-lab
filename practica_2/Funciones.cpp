#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Funciones.h"
using namespace std;

char mayus(){
    return 'A'+rand()%26;
}

int prob_2(unsigned int n){
    int cont[26] = {0};
    int *pcont = cont;

    cout << "El arreglo es: " << endl;

    for (unsigned int i = 0; i < n; i++){
        char m_al = mayus();
        cout << m_al;

        (*(pcont + (m_al - 'A')))++;
    }

    cout << endl;

    for(int i = 0; i < 26; i++){
        if(*(pcont + i) > 0){
            cout << char('A' + i) << ":" << *(pcont + i) << endl;
        }
    }

    return 0;
}
int prob_4(string numeros){
    int num=1;
    int valor=0;
    bool negativo=false;
    char *ptr=&numeros[0];
    long long unsigned int n=numeros.length();

    for (long long unsigned int i=0;i<n;i++){

        if(*(ptr+i)=='-'){
            negativo=true;
        }
        else {
            valor=*(ptr+i)-'0';
            if(negativo){
                num=valor*(-1);
                negativo=false;
            }
            else{
                num=valor;
            }
            cout<<num;
        }
    }
    cout<<' '<<endl;
    return 0;
}

int prob_8(string separar)
{
    string letras="";
    string numeros="";
    long long unsigned int n=separar.length();
    char *ptr=&separar[0];

    for (long long unsigned int i=0;i<n;i++){
        if (*(ptr+i)>='0'&&*(ptr+i)<='9'){
            numeros+=*(ptr+i);
        }
        else if ((*(ptr+i)>='a'&&*(ptr+i)<='z')||(*(ptr+i)>='A'&&*(ptr+i)<='Z')){
            letras+=*(ptr+i);
        }
    }
    cout<<"original: "<<separar<<endl;
    cout<<"Letras: "<<letras<<endl;
    cout<<"Numeros: "<<numeros<<endl;
    return 0;
}

void prob_14()
{
    unsigned short int matriz[5][5];
    unsigned short int *ptr=&matriz[0][0];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        *(ptr+i*5+j)=i*5+j+1;
    }
    cout<<"Matriz original:"<<endl;
    for (int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<*(ptr+i*5+j)<<" ";
        }
        cout<<endl;
    }
    cout<<"Matriz rotada 90 grados: "<<endl;
    for(int j=0;j<5;j++){
        for(int i=4;i>=0;i--){
            cout<<*(ptr+i*5+j)<<" ";
        }
        cout<<endl;
    }
    cout<<"Matriz rotada 180 grados:"<<endl;
    for(int i=4;i>=0;i--){
        for(int j=4;j>=0;j--){
            cout<<*(ptr+i*5+j)<<" ";
        }
        cout<<endl;
    }
    cout<<"Matriz rotada a 270 grados:"<<endl;
    for (int j=4;j>=0;j--){
        for(int i=0;i<5;i++){
            cout<<*(ptr+i*5+j)<<" ";
        }
        cout<<endl;
    }
}


void prob_12(int n) {

    if (n <= 0 || n > 10) {
        cout << "Tamaño invalido"<<endl;
        return;
    }

    int matriz[n][n];
    int *ptr = &matriz[0][0];

    for (int i = 0; i < n*n; i++) {
        cout << "Ingrese valor " << i << ": ";
        cin >> *(ptr + i);
    }

    int suma_base = 0;

    for (int j = 0; j < n; j++) {
        suma_base += *(ptr + j);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<*(ptr+i*n+j)<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < n; i++) {
        int suma = 0;
        for (int j = 0; j < n; j++) { 
            suma += *(ptr + i*n + j);
        }
        if (suma != suma_base) {
            cout << "No es cuadrado magico"<<endl;
            return;
        }
    }


    for (int j = 0; j < n; j++) {
        int suma = 0;
        for (int i = 0; i < n; i++) {
            suma += *(ptr + i*n + j);
        }
        if (suma != suma_base) {
            cout << "No es cuadrado magico"<<endl;
            return;
        }
    }

    int diag1 = 0;
    int diag2 = 0;

    for (int i = 0; i < n; i++) {
        diag1 += *(ptr + i*n + i);
        diag2 += *(ptr + i*n + (n-1-i));
    }

    if (diag1 == suma_base && diag2 == suma_base) {
        cout << "Es cuadrado magico"<<endl;
    } else {
        cout << "No es cuadrado magico"<<endl;
    }
}

void prob_16(int mat)
{
    int matriz[50][50];


    int (*p)[50] = matriz;


    for (int i = 0; i <= mat; i++) {
        *(*(p + i) + 0) = 1;
        *(*(p + 0) + i) = 1;
    }


    for (int i = 1; i <= mat; i++) {
        for (int j = 1; j <= mat; j++) {
            *(*(p + i) + j) = *(*(p + (i-1)) + j) + *(*(p + i) + (j-1));
        }
    }

    cout<<"Para una malla de "<<mat<<"x"<<mat<<" puntos hay "<< *(*(p + mat) + mat)<<" caminos"<<endl;
    return;
}

void prob_18(long long n)
{
    int digitos[10];
    int usados[10] = {0};
    int factorial[11];


    for (int i = 0; i < 10; i++) {
        digitos[i] = i;
    }

    factorial[0] = 1;
    for (int i = 1; i <= 10; i++) {
        factorial[i] = factorial[i-1] * i;
    }

    n--;

    int *f = factorial;
    int *u = usados;
    int *d = digitos;

    for (int i = 9; i >= 0; i--) {
        int pos = n / *(f + i);
        n = n % *(f + i);

        int contador = -1;


        for (int j = 0; j < 10; j++) {
            if (*(u + j) == 0) {
                contador++;
            }

            if (contador == pos) {
                cout << *(d + j);
                *(u + j) = 1;
                break;
            }
        }
    }

    cout << endl;
}

int valor(char c) {
    if (c == 'I'||c=='i') return 1;
    if (c == 'V'||c=='v') return 5;
    if (c == 'X'||c=='x') return 10;
    if (c == 'L'||c=='l') return 50;
    if (c == 'C'||c=='c') return 100;
    if (c == 'D'||c=='d') return 500;
    if (c == 'M'||c=='m') return 1000;
    return 0;
}


int prob_10(char *romano)
{
    int total = 0;

    for (int i = 0; *(romano + i) != '\0'; i++) {
        int actual = valor(*(romano + i));
        int siguiente = valor(*(romano + i + 1));

        if (actual < siguiente) {
            total -= actual;
        } else {
            total += actual;
        }
    }

    return total;
}

void prob_6(string &cadena)
{
    char *p = &cadena[0];

    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
        p++;
    }
}
