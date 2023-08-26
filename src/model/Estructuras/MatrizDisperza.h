//lista para guardar los empleados y a los proyectos que se les asignara
using namespace std;
#pragma once
#include <iostream>
#include <string.h>
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
        int contadorF = 000;
        int contadorB = 000;
        int contadorQ = 000;
        int x;
        int y;
        int x_1 = 0;
        int y_1 = 0;
    public:
        
        Matriz_Dispersa(){
            int x = 0;
            int y = 0;
            int n = 5;
            int m = 5;
            bool wasp = true;
            bool wasp2 = true;
            Nod4* inicio = new Nod4();  // Nodo inicial sin valor
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
            cout<<posicion_empleado<<endl;
            bool asd = true;
            int asd_2 = 0;
            while(asd){
                Aux_proyecto = Aux_proyecto->Abajo;
                asd_2 += 1;
                cout<<asd_2<<endl;
                if(asd_2 == posicion_empleado){
                    cout<<asd_2<<endl;
                    Proyecto* proyecto = new Proyecto(ID_proyecto,Aux_empleado->Get_empleado()->Get_ID_empleado());
                    Aux_proyecto->Set_proyecto(proyecto);
                    asd = false;
                }
                    
            }
            cout<<"Proyecto asignado"<<endl;
        }
        void Asignar_proyecto(string nombre,string ID_proyecto){
            string puesto;
            string aux_puesto;
            bool asd = true;
            int respuesta;
            if (buscar_empleado(nombre)->Get_empleado()->Get_ID_empleado() == "vacio"){
                while(asd){
                    cout<<"Este empleado aun no tiene un Puesto Ingrese uno"<<endl;
                    cout<<"1.Frontend Developer(FDEV)"<<endl;
                    cout<<"2.Backend Developer(BDEV)"<<endl;
                    cout<<"3.Quality Assurance(QA)"<<endl;
                    cout<<"Puesto: ";cin>>respuesta;
                    if(respuesta == 1){
                        puesto = "FDEV-"+contadorF;
                        contadorF += 1;
                        asd = false;
                        buscar_empleado(nombre)->Get_empleado()->Set_ID_empleado(puesto);
                    }
                    else if(respuesta == 2){
                        puesto = "BDEV-"+contadorB;
                        contadorB += 1;
                        asd = false;
                        buscar_empleado(nombre)->Get_empleado()->Set_ID_empleado(puesto);
                    }
                    else if(respuesta == 3){
                        puesto = "QA-"+contadorQ;
                        contadorQ += 1;
                        asd = false;
                        buscar_empleado(nombre)->Get_empleado()->Set_ID_empleado(puesto);
                    }
                    else{
                        cout<<"Ingrese una opcion Valida"<<endl;
                    }
                    
                }
                Asignacion_Algoritmo(nombre,ID_proyecto); 
            }
            else{
                Asignacion_Algoritmo(nombre,ID_proyecto);
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
};