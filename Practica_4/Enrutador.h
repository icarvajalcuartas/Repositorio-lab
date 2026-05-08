#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include<iostream>
#include <vector>
#include <map>
#include <climits>
#include <iomanip>
using namespace std;
class Enrutador{

public:
    struct EntradaTabla{
        unsigned int costo;
        Enrutador* siguienteSalto;
    };
    Enrutador(char id);
    void nuevoVecino(Enrutador* vecino, int costo);
    void actualizarTabla(Enrutador* destino, unsigned int costo, Enrutador* salto);
    void reiniciarTabla();
    void imprimirFilaTabla(const vector<char>& destinos)const;
    void limpiarVecinos();

    char getIdentificador() const;
    unsigned int getCostoA(char destino) const;
    Enrutador* getSaltoA(char destino) const;
    const vector<pair<Enrutador*, int>>& getVecinos() const;
    const map<char, EntradaTabla>& getTabla() const;
private:
    char identificador;
    vector<pair<Enrutador*,int>> vecinos;
    map<char, EntradaTabla> tablaDeEnrutamiento;


};

#endif // ENRUTADOR_H
