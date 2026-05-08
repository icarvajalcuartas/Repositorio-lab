#include"Red.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <climits>


void Red::dijkstra(Enrutador *fuente)
{
    fuente->reiniciarTabla();

    for (auto* r:enrutadores)
        if (r!=fuente)
            fuente->actualizarTabla(r, UINT_MAX, nullptr);

    priority_queue<pair<int, Enrutador*>> cola;
    cola.push({0, fuente});

    while (!cola.empty()) {
        Enrutador* actual=cola.top().second;
        int costoActual=-cola.top().first;
        cola.pop();

        if ((unsigned int)costoActual > fuente->getCostoA(actual->getIdentificador()))
            continue;

        for (int i=0; i<(int)actual->getVecinos().size(); i++) {
            Enrutador* vecino=actual->getVecinos()[i].first;
            int costoArista=actual->getVecinos()[i].second;
            unsigned int nuevoCosto =costoActual+costoArista;

            if (nuevoCosto<fuente->getCostoA(vecino->getIdentificador())) {
                Enrutador* salto;
                if (actual==fuente)
                    salto=vecino;
                else
                    salto=fuente->getSaltoA(actual->getIdentificador());

                fuente->actualizarTabla(vecino, nuevoCosto, salto);
                cola.push({-nuevoCosto, vecino});
            }
        }
    }
}

Red::Red()
{
    enrutadores.clear();
    conexiones.clear();
}

void Red::agregarEnrutador(char id)
{
    enrutadores.push_back(new Enrutador(id));
}

void Red::agregarConexion(char origen, char destino, int costo)
{
    Enrutador* o=buscar(origen);
    Enrutador* d=buscar(destino);
    if(!o||!d){
        cout<<"Enrutador no encontrado \n";
        return;
    }
    o->nuevoVecino(d,costo);
    d->nuevoVecino(o,costo);
    conexiones.push_back({o,d,costo});

}

void Red::eliminarConexion(char origen, char destino)
{
    Enrutador* o = buscar(origen);
    Enrutador* d = buscar(destino);
    if (!o || !d) return;

    for (auto it=conexiones.begin();it!=conexiones.end();++it) {
        if ((it->origen==o && it->destino==d) ||
            (it->origen==d && it->destino==o)) {
            conexiones.erase(it);
            break;
        }
    }

    for (auto* r:enrutadores)
        r->limpiarVecinos();

    for (int i=0; i<(int)conexiones.size(); i++) {
        conexiones[i].origen->nuevoVecino(conexiones[i].destino, conexiones[i].costo);
        conexiones[i].destino->nuevoVecino(conexiones[i].origen, conexiones[i].costo);
    }
    calcularTablas();
}

void Red::calcularTablas()
{
    for (auto* r:enrutadores)
        dijkstra(r);
}

void Red::imprimirTablas() const
{
    vector<char> ids;
    for (auto* r:enrutadores)
        ids.push_back(r->getIdentificador());

    cout<<"=== Tabla de costos ===\n";


    cout<<"     ";
    for (char id:ids)
        cout<<"[" << std::setw(3) << id << "]";
    cout<<"\n";

    for (auto* r:enrutadores)
        r->imprimirFilaTabla(ids);

    cout<<endl;
}

void Red::imprimirTopologia() const
{
    cout<<"=== Topologia de la red ===\n";
    cout<<"Enrutadores: ";
    for (auto* r : enrutadores)
        cout<<r->getIdentificador()<<" ";

    cout<<"\nConexiones:\n";

    for (auto& c:conexiones)
    cout<<"  "<<c.origen->getIdentificador()
        <<" <--> "<<c.destino->getIdentificador()
        <<"  costo: "<<c.costo<<"\n";
    cout << "\n";
}

void Red::imprimirCamino(char origen, char destino) const
{
    Enrutador* ori= buscar(origen);
    Enrutador* dst= buscar(destino);
    if (!ori || !dst) {
        cout << "Enrutador no encontrado\n";
        return;
    }
    if (ori->getCostoA(destino) == UINT_MAX) {
        cout<<"No hay camino entre " <<origen<<" y "<< destino<< "\n";
        return;
    }


    cout << "Camino "<<origen<<" -> "<<destino
              <<" (costo: "<<ori->getCostoA(destino)<<"): ";

    vector<char> camino;
    camino.push_back(origen);

    Enrutador* actual=ori;
    while (actual->getIdentificador()!=destino) {
        Enrutador* salto= actual->getSaltoA(destino);
        if (!salto) break;
        camino.push_back(salto->getIdentificador());
        actual= salto;
    }

    for (int i=0; i<(int)camino.size();i++) {
        if (i> 0) cout<<" -> ";
        cout << camino[i];
    }
    cout << endl;
}

Enrutador *Red::buscar(char id) const
{
    for(auto *r:enrutadores){
        if(r->getIdentificador()==id){
            return r;
        }
    }
    return nullptr;
}

Red::~Red()
{
    for (auto* r:enrutadores)
        delete r;
}

