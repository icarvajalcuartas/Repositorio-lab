#ifndef GESTOR_H
#define GESTOR_H
#include "Red.h"
#include <string>
#include<vector>

struct RedTipologia{
    string tipologia;
    Red* red;
};
class Gestor{
private:
    vector <RedTipologia> redes;
    void integrarBloque(const string& tipologia, const vector<string>& lineas);
public:
    Gestor();
    void cargarDesdeArchivo(const string& nombreArchivo);
    void imprimir() const;
    ~Gestor();
};

#endif // GESTOR_H
