#ifndef RED_H
#define RED_H
#include<iostream>
#include"Enrutador.h"
#include <vector>
using namespace std;

class Red{
private:
    struct Conexion{
        Enrutador* origen;
        Enrutador* destino;
        int costo;
    };
    vector<Enrutador*> enrutadores;
    vector <Conexion> conexiones;
    void dijkstra(Enrutador* fuente);
public:
    Red();

    void agregarEnrutador(char id);
    void agregarConexion(char origen, char destino, int costo);
    void eliminarConexion(char origen, char destino);
    void calcularTablas();
    void imprimirTablas()const;
    void imprimirTopologia() const;
    void imprimirCamino(char origen, char destino) const;
    Enrutador* buscar(char id) const;
    ~Red();

};

#endif // RED_H
