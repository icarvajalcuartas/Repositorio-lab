#include <iostream>
#include "Red.h"
#include"Gestor.h"
int main() {
    cout<<"************MENU PARA ENRUTADORES Y REDES************"<<endl;
    unsigned short int opt;
    cout<<"Indique la opcion que desea realizar:"<<endl;
    cout<<"1:Creacion de una red por consola"
         <<"\n2:Creacion de una red a partir de un archivo"
         <<"\n0:Para finalizar"<<endl;
    cin>>opt;
    while(opt!=0){
        switch(opt){
            case(1):{
                Red redCon;
                unsigned short int n;
                cout<<"Ingrese que desea realizar con la red:"
                     <<"\n 1:Agregar enrutador"
                     <<"\n 2:Agregar conexion"
                     <<"\n 3:Imprimir Topologia"
                     <<"\n 4:Imprimir tabla de costos"
                     <<"\n 5:Eliminar conexion"
                     <<"\n 6:Imprimir camino entre 2 enrutadores"
                     <<"\n 0:Volver al menu principal"<<endl;
                cin>>n;
                if(n==0)break;
                while (n!=0){
                    switch(n){
                        case(1):{
                            char enrutid;
                            cout<<"Ingrese el identificador del "
                                 <<"enrutador que desea agregar:"<<endl;
                            cin>>enrutid;
                            redCon.agregarEnrutador(enrutid);
                            break;
                        }case(2):{
                            char con1,con2;
                            int costo;
                            cout<<"==========AGREGAR CONEXION==========="<<endl;
                            cout<<"Ingrese el identificador del enrutador 1:"<<endl;
                            cin>>con1;
                            cout<<"Ingrese el identificador del enrutador 2:"<<endl;
                            cin>>con2;
                            cout<<"Ingrese el costo de la conexion: "<<endl;
                            cin>>costo;
                            redCon.agregarConexion(con1,con2,costo);
                            break;
                        }case(3):{
                            redCon.imprimirTopologia();
                            break;
                        }case(4):{
                            redCon.imprimirTablas();
                            break;
                        }case(5):{
                            char eli1,eli2;
                            cout<<"===========ELIMINAR CONEXION=========="<<endl;
                            cout<<"Ingrese el identificador del enrutador 1:"<<endl;
                            cin>>eli1;
                            cout<<"Ingrese el identificador del enrutador 2:"<<endl;
                            cin>>eli2;
                            redCon.eliminarConexion(eli1,eli2);
                            break;
                        }case(6):{
                            char cam1,cam2;
                            cout<<"===========IMPRIMIR CAMINO=========="<<endl;
                            cout<<"Ingrese el identificador del enrutador 1:"<<endl;
                            cin>>cam1;
                            cout<<"Ingrese el identificador del enrutador 2:"<<endl;
                            cin>>cam2;
                            redCon.imprimirCamino(cam1,cam2);
                            break;
                        }default:
                            cout<<"Opcion invalida"<<endl;
                            break;
                }
                    cout<<"Ingrese que desea realizar con la red:"
                         <<"\n 1:Agregar enrutador"
                         <<"\n 2:Agregar conexion"
                         <<"\n 3:Imprimir Topologia"
                         <<"\n 4:Imprimir tabla de costos"
                         <<"\n 5:Eliminar conexion"
                         <<"\n 6:Imprimir camino entre 2 enrutadores"
                         <<"\n 0:Volver al menu principal"<<endl;
                    cin>>n;
            }
                break;
        }case(2):{
            cout<<"********Haciendo calculo por archivo.*******"<<endl;
            Gestor gestor;
            gestor.cargarDesdeArchivo("redes.txt");
            gestor.imprimir();
            break;
        }default:
            break;
        }
        cout<<"Indique la opcion que desea realizar:"<<endl;
        cout<<"1:Creacion de una red por consola"
             <<"\n2:Creacion de una red a partir de un archivo"
             <<"\n0:Para finalizar"<<endl;

        cin>>opt;
    }
    cout<<"************FIN DEL PROGRAMA************"<<endl;
    return 0;
}
