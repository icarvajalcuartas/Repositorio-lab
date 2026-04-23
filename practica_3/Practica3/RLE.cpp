#include"RLE.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string rleCompress(const string& input) {
    string result = "";
    int count = 1;

    for (int i = 0; i <(int) input.length(); i++) {
        bool isDigitChar = isdigit(input[i]);
        if (i + 1 < (int)input.length() && input[i] == input[i + 1]) {
            count++;
            if (isDigitChar && count==9){
                result += input[i];
                result += '9';
                count = 0;
            }
        } else {
            result += input[i];
            result += to_string(count);
            count = 1;
            }
    }
    return result;
}
string rleDecompress(const string& input) {
    string result = "";
    int count=0;
    for (int i = 0; i < (int)input.length(); i++) {
        char letra = input[i];
        string numero = "";
        if(isdigit(letra)){
            if(i+1<(int)input.length() && isdigit(input[i+1])){
                count= input[i+1]-'0';
                i++;
            }
        }
        else{
            i++;
            while (i < (int)input.length() && isdigit(input[i])) {
                numero += input[i];
                i++;
            }

            i--;
            count = stoi(numero);
        }

        for (int j = 0; j < count; j++) {
            result += letra;
        }
    }

    return result;
}
