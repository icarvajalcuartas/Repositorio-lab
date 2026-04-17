#include"RLE.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string rleCompress(const string& input) {
    string result = "";
    int count = 1;

    for (int i = 0; i < input.length(); i++) {
        if (i + 1 < input.length() && input[i] == input[i + 1]) {
            count++;
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

    for (int i = 0; i < input.length(); i++) {
        char letra = input[i];
        string numero = "";

        i++;
        while (i < input.length() && isdigit(input[i])) {
            numero += input[i];
            i++;
        }

        i--;

        int count = stoi(numero);

        for (int j = 0; j < count; j++) {
            result += letra;
        }
    }

    return result;
}
