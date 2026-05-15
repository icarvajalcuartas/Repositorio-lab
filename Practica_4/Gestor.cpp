#include "Gestor.h"
#include <fstream>
#include <iostream>

Gestor::Gestor(){}

void Gestor::integrarBloque(const string &tipologia, const vector<string> &lineas)
{
    Red* red=new Red();

    for(int i=0;i<(int)lineas.size();i++){
        string linea=lineas[i];
        vector<string> partes;
        string actual="";

        for(int j=0;j<(int)linea.size();j++){
            if (linea[j]==';'){
                partes.push_back(actual);
                actual="";
            }else{
                actual +=linea[j];
            }
        }
        partes.push_back(actual);
        if((int)partes.size()!=3) continue;
        char origen=partes[0][0];
        char destino=partes[1][0];
        while (!partes[2].empty() && (partes[2].back()=='\r'||partes[2].back()==' ')) {
            partes[2].pop_back();
        }
        int costo=stoi(partes[2]);

        if(!red->buscar(origen)){
            red->agregarEnrutador(origen);
        }
        if(!red->buscar(destino)){
            red->agregarEnrutador(destino);
        }
        red->agregarConexion(origen,destino,costo);
    }
    RedTipologia rt;
    rt.tipologia=tipologia;
    rt.red=red;
    redes.push_back(rt);
}


void Gestor::cargarDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);

    if(!archivo.is_open()){
        cout<<"No se pudo abrir el archivo: "<<nombreArchivo<<endl;
        return;
    }
    string linea;
    string tipologiaActual="";
    vector<string> lineasBloque;

    while(getline(archivo,linea)){
        if (!linea.empty() && linea.back()=='\r') {
            linea.pop_back();
        }
        if(linea.empty()) continue;

        bool esEncabezado=true;
        for(int i=0;i<(int)linea.size();i++){
            if(linea[i]==';'){
                esEncabezado=false;
                break;
            }
        }
        if(esEncabezado){
            if(tipologiaActual!=""){
                integrarBloque(tipologiaActual,lineasBloque);
            }
            tipologiaActual=linea;
            lineasBloque.clear();
        }else{
            lineasBloque.push_back(linea);
        }
    }
    if(tipologiaActual!=""){
        integrarBloque(tipologiaActual,lineasBloque);
    }
    archivo.close();

}

void Gestor::imprimir() const
{
    for(int i=0;i<(int)redes.size();i++) {
        cout << "=== Topologia: " <<redes[i].tipologia<<"==="<<endl;
        redes[i].red->imprimirTopologia();
        redes[i].red->imprimirTablas();
    }
}

Gestor::~Gestor()
{
    for (int i=0;i<(int)redes.size();i++) {
        delete redes[i].red;
    }
}
