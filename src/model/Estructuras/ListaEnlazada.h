// Lista para guardar tareas
#include <iostream>
#include "../ClasesObjet/Tarea.h"
#pragma once
using namespace std;
class Nodo2{
    public:
        Nodo2* siguiente;
        Nodo2* anterior;
        Tarea* tarea;
        Nodo2(Tarea* _tarea){
            tarea = _tarea;
            siguiente=0;
            anterior=0;
        }
};

class ListaEnlazada{
    private:
        Nodo2* Inicio;
        Nodo2* Fin;
    public:
        ListaEnlazada(){
            Inicio = 0;
            Fin = 0;
        }
        void Agregar_Tarea(Tarea* tarea){
            Nodo2* nuevoNodo2 = new Nodo2(tarea);
            if (Inicio == 0) {
               Inicio = Fin = nuevoNodo2;
            }
            else{
                nuevoNodo2->anterior = Fin;
                Fin->siguiente = nuevoNodo2;
                Fin = nuevoNodo2;
            }
        }
        
};
