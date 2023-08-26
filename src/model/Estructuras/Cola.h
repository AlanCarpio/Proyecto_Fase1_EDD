/*Lista para guardar proyectos*/
#include <iostream>
#include "../ClasesObjet/Proyecto.h"
#pragma once
using namespace std;
class Nodo1{
    public:
        Nodo1* siguiente;
        Proyecto* proyecto;
        int posicion;
        Nodo1(Proyecto* _proyecto){
            proyecto = _proyecto;
            siguiente = 0;

        }
        void Set_proyecto(Proyecto* proyecto){
            this->proyecto = proyecto;
        }
        Proyecto* Get_proyecto(){
            return this -> proyecto;
        }
        void Set_posicion(int posicion){
            this->posicion=posicion;
        }
        int Get_posicion(){
            return this->posicion;
        }
        
        
};
class Cola{
    private:
        Nodo1* Inicio;
        Nodo1* Final;
        int contado_ID = 100;
        string ID = "PY-";
        int contador = 0;
    public:
        Cola(){
            this->Inicio = 0;
            this->Final = 0;

        }
        void Insertar_proyecto(Proyecto* proyecto){
            Nodo1* NuevoNodo1 = new Nodo1(proyecto);
            string aux_ID = ID + to_string(contado_ID);
            if (Inicio == 0) {
                Inicio = Final = NuevoNodo1;
                NuevoNodo1->proyecto->Set_ID_proyecto(aux_ID);
                NuevoNodo1->Set_posicion(contador);
            }
            else{
                NuevoNodo1->proyecto->Set_ID_proyecto(aux_ID);
                NuevoNodo1->Set_posicion(contador);
                Final->siguiente = NuevoNodo1;
                Final = NuevoNodo1;
            }
            contado_ID += 1;
            contador += 1;
        }
        Nodo1* buscar_indice(int posicion){
            Nodo1* aux = Inicio;
            while (aux != 0){
                if (aux->Get_posicion() == posicion){
                    return aux;
                }
                aux = aux->siguiente;
            }
        }
        void cambio_de_lugar(Nodo1* proyecto1,Nodo1* proyecto2){
           Proyecto* aux = proyecto1->Get_proyecto();
           proyecto1->Set_proyecto(proyecto2->Get_proyecto());
           proyecto2->Set_proyecto(aux);
            
        }
        void ordenamiento(){
            bool swapped = true;
            while (swapped) {
                swapped = false;
                for (int i = 0; i < contador - 1; i++) {
                    if (buscar_indice(i)->Get_proyecto()->Get_Prioridad() > buscar_indice(i+1)->Get_proyecto()->Get_Prioridad()) {
                        cambio_de_lugar(buscar_indice(i),buscar_indice(i+1));
                        swapped = true;
                    }
                }
            }
        }
        void imprimir(){
            Nodo1* aux = Inicio;
            while (aux != 0){
                cout<<aux->proyecto->Get_ID_proyecto()<<',';
                cout<<aux->proyecto->Get_Nombre()<<',';
                cout<<aux->proyecto->Get_Prioridad()<<endl;
                aux = aux->siguiente;
            }
            
        }
};
