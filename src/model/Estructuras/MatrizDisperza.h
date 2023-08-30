//lista para guardar los empleados y a los proyectos que se les asignara
using namespace std;
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include "Cola.h"
#include "ListEnlaCircular.h"
#include "../ClasesObjet/Proyecto.h"
#include "../ClasesObjet/Empleados.h"
class Nod4{
    public:
        Nod4* Siguiente;
        Nod4* Anterior;
        Nod4* Arriba;
        Nod4* Abajo;
        int x;
        int y;
        Proyecto* proyecto;
        Empleados* empleado;
        Nod4(){
            this->x = 0;
            this->y = 0;
            this->proyecto = 0;
            this->empleado = 0;
            Siguiente = 0;
            Anterior =  0;
            Arriba = 0;
            Abajo = 0;
        }
        void Set_proyecto(Proyecto* proyecto){
            this->proyecto = proyecto;
        }
        Proyecto* Get_proyecto(){
            return this->proyecto;
        }
        void Set_empleado(Empleados* empleado){
            this->empleado = empleado;
        }
        Empleados* Get_empleado(){
            return this->empleado;
        }
        int Get_y(){
            return this->y;
        }
        int Get_x(){
            return this->x;
        }
        void Set_x(int x){
            this->x = x;
        }
        void Set_y(int y){
            this->y = y;
        }

};
class Matriz_Dispersa{
    private:
        Nod4* Raiz;
        Nod4* Aux;
        Nod4* Aux2;
        ofstream archivo;
        int contadorF = 0;
        int contadorB = 0;
        int contadorQ = 0;
        int x;
        int y;
        int x_1 = 0;
        int y_1 = 0;
    public:
        
        Matriz_Dispersa(){
            int x = 0;
            int y = 0;
            int n = 11;
            int m = 10;
            bool wasp = true;
            bool wasp2 = true;
            Proyecto* proyecto = new Proyecto("Raiz");
            Nod4* inicio = new Nod4();  // Nodo inicial sin valor
            inicio->Set_proyecto(proyecto);
            inicio->Set_x(0);
            inicio->Set_y(0);
            Raiz = inicio;
            Aux = Aux2 = Raiz;
            Nod4* aux = Raiz;//almacena la fila siguiente
            Nod4* aux1 = 0;// almacena la fila actual
            while (wasp) { // Filas
                bool wasp2 = true;
                x = 0;
                if (y > 0){
                    Nod4* nuevoNodo = new Nod4();
                    aux->Abajo = nuevoNodo;
                    nuevoNodo->Arriba = aux;
                    aux = nuevoNodo;
                }
                while (wasp2) { // Columnas
                    if(y > 0){
                        Nod4* nuevoNodo = new Nod4();
                        aux->Siguiente = nuevoNodo;
                        nuevoNodo->Anterior = aux;
                        aux = nuevoNodo;
                        aux1 = aux1->Siguiente;
                        aux->Arriba = aux1;
                        aux1->Abajo = aux;
                        
                    }
                    else{
                        Nod4* nuevoNodo = new Nod4();
                        aux->Siguiente = nuevoNodo;
                        nuevoNodo->Anterior = aux;
                        aux = nuevoNodo;
                    }
                    x += 1;
                    if (x == m){
                        wasp2 = false;
                        while(aux->Anterior != 0){
                            aux = aux->Anterior;
                        }
                        aux1 = aux;  
                    }
                }
                y += 1;
                if (y == n){
                    wasp = false;
                }
            }
            }
        Nod4* buscar_empleado(string nombre){
            Nod4* aux = Raiz;
            while (aux !=0){
                if(aux->Get_empleado() != 0){
                    if (aux->Get_empleado()->Get_Nombre() == nombre){
                        return aux;
                    }
                }
                
                aux = aux->Abajo;
            }   
        }  
        Nod4* buscar_proyecto(string ID_proyecto){
            Nod4* aux = Raiz;
            while (aux !=0){
                if (aux->Get_proyecto() != 0){
                    if (aux->Get_proyecto()->Get_ID_proyecto() == ID_proyecto){
                        return aux;
                    }
                }
                
                aux = aux->Siguiente;
            }   
        }
        void insertar_proyectos(Proyecto* proyecto){ // Insertar de forma Horinzontal los ID de los proyectos creados
            x_1 += 1;
            Aux->Siguiente->Set_x(x_1);
            Aux->Siguiente->Set_proyecto(proyecto);
            Empleados* empleado = new Empleados("vacio");
            Aux->Siguiente->Set_empleado(empleado);
            Aux = Aux->Siguiente;
             
        }
        void insertar_empleados(Empleados* empleado){
            y_1 += 1;
            Aux2->Abajo->Set_y(y_1);
            Aux2->Abajo->Set_empleado(empleado);
            Aux2 = Aux2->Abajo;
        }
        void Asignacion_Algoritmo(string nombre,string ID_proyecto){
            Nod4* Aux_empleado = buscar_empleado(nombre);
            Nod4* Aux_proyecto = buscar_proyecto(ID_proyecto);
            int posicion_proyecto = Aux_proyecto->Get_x();
            int posicion_empleado = Aux_empleado->Get_y();
            bool asd = true;
            int asd_2 = 0;
            while(asd){
                Aux_proyecto = Aux_proyecto->Abajo;
                asd_2 += 1;
                if(asd_2 == posicion_empleado){
                    Proyecto* proyecto = new Proyecto(ID_proyecto,Aux_empleado->Get_empleado()->Get_ID_empleado());
                    Aux_proyecto->Set_proyecto(proyecto);
                    asd = false;
                } 
            }
            system("cls");
            cout<<"Proyecto asignado"<<endl;
            Sleep(2000);
            system("cls");
        }
        void Asignar_proyecto(string nombre,string ID_proyecto,Cola* cola,ListaEnlazadaCircular* circular){
            string puesto;
            string aux_puesto;
            bool asd = true;
            int respuesta;
            if (circular->buscar_emplado(nombre)){
                system("cls");
                cout<<"No existe ese empleado en la base de datos"<<endl;
                Sleep(2000);
                system("cls");
            }
            else if (cola->busqueda(ID_proyecto)){
                system("cls");
                cout<<"No existe ese ID de proyecto en la base de datos"<<endl;
                Sleep(2000);
                system("cls");
            }
            else{
                if (buscar_empleado(nombre)->Get_empleado()->Get_ID_empleado() == "vacio"){
                while(asd){
                    cout<<"Este empleado aun no tiene un Puesto Ingrese uno"<<endl;
                    cout<<"1.Frontend Developer(FDEV)"<<endl;
                    cout<<"2.Backend Developer(BDEV)"<<endl;
                    cout<<"3.Quality Assurance(QA)"<<endl;
                    cout<<"Puesto: ";cin>>respuesta;
                    if(respuesta == 1){
                        contadorF += 1;
                        string fdev = "FDEV-00";
                        if(contadorF > 9){
                            fdev = "FDEV-0";
                        }
                        puesto = fdev+to_string(contadorF);
                        
                        asd = false;
                        buscar_empleado(nombre)->Get_empleado()->Set_ID_empleado(puesto);
                    }
                    else if(respuesta == 2){
                        contadorB += 1;
                        string fdev = "BDEV-00";
                        if(contadorF > 9){
                            fdev = "BDEV-0";
                        }
                        puesto = fdev+to_string(contadorB);
                        
                        asd = false;
                        buscar_empleado(nombre)->Get_empleado()->Set_ID_empleado(puesto);
                    }
                    else if(respuesta == 3){
                        contadorQ += 1;
                        string fdev = "QA-00";
                        if(contadorF > 9){
                            fdev = "QA-0";
                        }
                        puesto = fdev+to_string(contadorQ);
                        
                        asd = false;
                        buscar_empleado(nombre)->Get_empleado()->Set_ID_empleado(puesto);
                    }
                    else{
                        system("cls");
                        cout<<"Ingrese una opcion Valida"<<endl;
                        Sleep(2000);
                    }
                    
                }
                Asignacion_Algoritmo(nombre,ID_proyecto); 
            }
                else{
                    Asignacion_Algoritmo(nombre,ID_proyecto);
                }
            }
            
            }
        void imprimir(){
            Nod4* aux = Raiz;
            Nod4* aux2;
            while (aux != 0){
                if (aux->Get_empleado() != 0){
                    //cout<<aux->Get_empleado()->Get_Nombre();
                    cout<<aux->Get_y();
                }
                else{
                    cout<<"-";
                }
                aux2 = aux->Siguiente;
                while(aux2 != 0){
                    if (aux2->Get_proyecto() != 0 && aux2->Get_empleado() == 0){
                        cout<<aux2->Get_proyecto()->Get_ID_proyecto();
                        //cout<<aux2->Get_x();
                    }
                    else{
                        cout<<"-";
                    }
                    aux2 = aux2->Siguiente;
                }
                cout<<""<<endl;
                aux = aux->Abajo;
            }
            
        }
        // Busquedas grafricar conecxion de nodos
        int arriba(Nod4* nodo){
            Nod4* nodo_actual = nodo;
            while (nodo->Arriba != 0){
                nodo = nodo->Arriba;
                if (nodo != 0){
                    if(nodo->Get_proyecto() != 0){
                        archivo << "nodo" << nodo << " -> " << "nodo" << nodo_actual << " [dir=both];\n";
                        return 0;
                    }
                    else if(nodo->Get_empleado() != 0){
                        archivo << "nodo" << nodo << " -> " << "nodo" << nodo_actual << " [dir=both];\n";
                        return 0;
                    }
                    else if(nodo->Get_empleado() != 0 && nodo->Get_proyecto() != 0){
                        archivo << "nodo" << nodo << " -> " << "nodo" << nodo_actual << " [dir=both];\n";
                        return 0;
                    }
                }
            }  
        }
        int siguiente(Nod4* nodo){
            Nod4* nodo_actual = nodo;
            while (nodo->Siguiente != 0){
                nodo = nodo->Siguiente;
                if (nodo != 0){
                    if(nodo->Get_proyecto() != 0){
                        archivo << "nodo" << nodo_actual << " -> " << "nodo" << nodo << " [dir=both];\n";
                        return 0;
                    }
                    else if(nodo->Get_empleado() != 0){
                        archivo << "nodo" << nodo_actual << " -> " << "nodo" << nodo << " [dir=both];\n";
                        return 0;
                    }
                    else if(nodo->Get_empleado() != 0 && nodo->Get_proyecto() != 0){
                        archivo << "nodo" << nodo_actual << " -> " << "nodo" << nodo << " [dir=both];\n";
                        return 0;    
                    }
                }

            }
        }
        
        void Graficar(){
            string texto = "";
            string nombre_archivo = "matriz.dot";
            string nombre_imagen = "matriz.jpg";
            Nod4* aux1 = Raiz;
            Nod4* aux2 = Raiz;
            Nod4* aux3 = Raiz;
            archivo.open(nombre_archivo, ios::out);
            archivo << "digraph MatrizCapa{ \n node[shape=box] \n rankdir=UD;\n";
            while(aux1 != 0){
                archivo << "{rank=same; \n";
                if (aux1->Get_proyecto() != 0){
                    archivo << "nodo" << aux1 << "[label=\"" << aux1->Get_proyecto()->Get_Nombre() << "\" ,group=" << (0) << "]; \n";
                }
                if (aux1->Get_empleado() != 0){
                    archivo << "nodo" << aux1 << "[label=\"" << aux1->Get_empleado()->Get_Nombre() << "\" ,group=" << (0) << "]; \n";
                }
                aux2 = aux1->Siguiente;
                while(aux2 != 0){
                    if(aux2->Get_proyecto() != 0 && aux2->Get_empleado() != 0){
                        archivo << "nodo" << aux2 << "[label=\"" << aux2->Get_proyecto()->Get_ID_proyecto() << "\" ,group=" << (aux2->Get_x()) << "]; \n";
                    }
                    else if(aux2->Get_proyecto() != 0){
                        
                        archivo << "nodo" << aux2 << "[label=\"" << aux2->Get_proyecto()->Get_ID_proyecto() << "\\n" << aux2->Get_proyecto()->Get_ID_empleado() << "\" ,group=" << (buscar_proyecto(aux2->Get_proyecto()->Get_ID_proyecto())->Get_x()) << "]; \n";
                    }
                aux2 = aux2->Siguiente;
                }
                archivo << "} \n";
                aux1 = aux1->Abajo;
            }
            
            // Conecxion de los nodos;
            aux1 = Raiz;
            aux2 = 0;
            while (aux1 != 0){
                if (aux1->Get_empleado() != 0  ){
                    arriba(aux1);
                    siguiente(aux1);
                    
                }
                if(aux1->Get_proyecto() != 0){
                    arriba(aux1);
                    siguiente(aux1);
                }
                aux2 = aux1->Siguiente;
                while (aux2 != 0){
                    if (aux2->Get_empleado() != 0  ){
                        arriba(aux2);
                        siguiente(aux2); 
                    }
                    else if(aux2->Get_proyecto() != 0){
                        arriba(aux2);
                        siguiente(aux2); 
                    }
                    aux2 = aux2->Siguiente;
                }
                aux1 = aux1->Abajo;  
            }
            
            archivo << "} \n";
            archivo.close();
            
            string codigo_cmd="dot -Tjpg ";
            codigo_cmd+=nombre_archivo;
            codigo_cmd+=" -o ";
            codigo_cmd+=nombre_imagen;
            char j[codigo_cmd.size()+1];
            strcpy(j,codigo_cmd.c_str());
            system(j);

        }
};