#include <iostream>
using namespace std;

struct Entry {
    int prefix;
    char c;
};

// Buscar si (prefijo, carácter) ya existe
int findEntry(Entry* dict, int size, int prefix, char c) {
    for (int i = 1; i < size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c) {
            return i;
        }
    }
    return -1;
}

void reconstruct(Entry* dict, int index, char* temp, int& pos) {
    if(index == 0) return;

    reconstruct(dict, dict[index].prefix, temp, pos);
    temp[pos++] = dict[index].c;
}

char* decompressLZ78(Entry* dict, int size) {
    static char resultado[1000];
    int r = 0;

    for(int i = 1; i < size; i++) {
        char temp[100];
        int pos = 0;

        reconstruct(dict, i, temp, pos);
        temp[pos] = '\0';

        for(int j = 0; j < pos; j++) {
            resultado[r++] = temp[j];
        }
    }
    resultado[r] = '\0';
    return resultado;
}
bool comparacion(char* descomprimido,const char *input,bool des){
    if(des){
            cout << "Texto: ";
        for(int i = 0; descomprimido[i] != '\0'; i++){
            cout << descomprimido[i];
        }
        cout << endl;
        bool iguales = true;

        for(int i = 0; ; i++){
            if(input[i] != descomprimido[i]){
                iguales = false;
                break;
            }
            if(input[i] == '\0') break;
        }

        if(iguales){
            cout << "Son iguales\n"<<endl;
            return true;
        }
        else{
            cout << "Son diferentes\n"<<endl;
            return false;
        }
    }
    else{
        bool iguales = true;

        for(int i = 0; ; i++){
            if(input[i] != descomprimido[i]){
                iguales = false;
                break;
            }
            if(input[i] == '\0') break;
        }

        if(iguales){
            return true;
        }
        else{
            return false;
        }
    }
}
char* compressLZ78(const char* input, bool des) {
    Entry* dict = new Entry[1000]; // tamaño fijo simple
    int dictSize = 1; // índice 0 vacío

    int currentPrefix = 0;

    cout << "Salida (indice, caracter):\n";

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        int index = findEntry(dict, dictSize, currentPrefix, c);

        if (index != -1) {
            currentPrefix = index;
        } else {
            cout << "(" << currentPrefix << ", " << c << ")\n";

            dict[dictSize].prefix = currentPrefix;
            dict[dictSize].c = c;
            dictSize++;

            currentPrefix = 0;
        }
    }
    if(currentPrefix != 0){
        dict[dictSize] = dict[currentPrefix];
        dictSize++;
    }

    char* descomprimido;
    cout<<dictSize<<endl;
    descomprimido=decompressLZ78(dict,dictSize);
    if(des){
        comparacion(descomprimido,input,des);
        delete[] dict;
        return nullptr;
    }
    else{
        delete[]dict;
        return descomprimido;
    }

}
