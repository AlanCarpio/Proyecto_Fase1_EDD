// Lista para guardar tareas
#include <iostream>
#pragma once
#include "../ClasesObjet/Tarea.h"
using namespace std;
class Nodo2{
    public:
        Nodo2* siguiente;
        Nodo2* anterior;
        Tarea* tarea;
        Nodo2(Tarea* tarea){
            this->tarea = tarea;
            this->siguiente=0;
            this->anterior=0;
        }
        Tarea* Get_Tarea(){
            return 	this->tarea;
        }
};

class ListaEnlazada{
    private:
        Nodo2* Inicio;
        Nodo2* Fin;
    public:
        ListaEnlazada(){
            this->Inicio = 0;
            this->Fin = 0;
        }
        void Agregar_Tarea(string nombre){
            Tarea* tarea = new Tarea(nombre);
            Nodo2* nuevoNodo = new Nodo2(tarea);
            if (Inicio == 0) {
                Inicio = Fin = nuevoNodo;
            }
            else{
                Fin->siguiente = nuevoNodo;
                nuevoNodo->anterior = Fin;
                Fin = nuevoNodo;
            }
        }
        string Iterar_Tareas(){
            Nodo2* aux = Inicio;
            string archivo;
            while(aux != 0){
                if(aux->siguiente != 0){
                    archivo = "{ \n ";
                    archivo = archivo + "\"Nombre\":";
                    archivo = archivo + "\"";
                    cout<<aux->tarea->Get_Nombre()<<endl;
                    archivo = archivo + aux->tarea->Get_Nombre();
                    archivo = archivo + "\" \n";
                    archivo = archivo + "},\n";
                }
                else{
                    archivo = "{ \n ";
                    archivo = archivo + "\"Nombre\":";
                    archivo = archivo + "\"";
                    archivo = archivo + aux->Get_Tarea()->Get_Nombre();
                    archivo = archivo + "\" \n";
                    archivo = archivo + "}\n";
                }
                aux = aux->siguiente;
            }
            return archivo;
        }
        void Tareas(){
            Nodo2* aux = Inicio;
            while(aux != 0){
                cout<<aux->Get_Tarea()->Get_Nombre();
                aux = aux->siguiente;
            }
        }
        
};
