#include "Enrutador.h"
#include<iostream>
#include <vector>
#include <queue>
Enrutador::Enrutador(char id):identificador(id){}

void Enrutador::nuevoVecino(Enrutador *vecino, int costo)
{
    vecinos.emplace_back(vecino, costo);
}

void Enrutador::actualizarTabla(Enrutador *destino, unsigned int costo, Enrutador *salto)
{
    tablaDeEnrutamiento[destino->getIdentificador()]={costo,salto};
}

void Enrutador::reiniciarTabla()
{
    tablaDeEnrutamiento.clear();
    tablaDeEnrutamiento[identificador]={0,nullptr};
}

void Enrutador::imprimirFilaTabla(const vector<char> &destinos) const
{
    cout<<" "<<identificador<<" ";
    for(char dest:destinos){
        unsigned int costo= getCostoA(dest);
        if(costo==UINT_MAX){
            cout<<"[INF]";
        }
        else{
            cout<<"["<<setw(3)<<costo<<"]";
        }
    }
     cout<<endl;
}

void Enrutador::limpiarVecinos()
{
    vecinos.clear();
}

bool Enrutador::actualizarCostoVecino(Enrutador *vecino, int nuevoCosto)
{
    for (auto& par:vecinos) {
        if (par.first==vecino) {
            par.second=nuevoCosto;
            return true;
        }
    }
    return false;
}


char Enrutador::getIdentificador() const
{
    return identificador;
}

unsigned int Enrutador::getCostoA(char destino) const
{
    auto it=tablaDeEnrutamiento.find(destino);
    if(it!=tablaDeEnrutamiento.end()){
        return it->second.costo;
    }
    return UINT_MAX;
}

Enrutador *Enrutador::getSaltoA(char destino) const
{
    auto it=tablaDeEnrutamiento.find(destino);
    if(it!=tablaDeEnrutamiento.end()){
        return it->second.siguienteSalto;
    }
    return nullptr;
}

const vector<pair<Enrutador *, int> > &Enrutador::getVecinos() const
{
    return vecinos;
}

const map<char, Enrutador::EntradaTabla> &Enrutador::getTabla() const
{
    return tablaDeEnrutamiento;
}

