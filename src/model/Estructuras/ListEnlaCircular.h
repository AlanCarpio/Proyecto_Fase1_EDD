// Lista para el Equipo de trabajo
#include <iostream>
#pragma once
#include "../ClasesObjet/Empleados.h"
using namespace std;

class Nodo3{
       
    public:
        /* Objeto Equipo Trabajo*/
        Nodo3* siguiente;
        Nodo3* anterior;
        Empleados* empleado;
        int contador;
        Nodo3(Empleados* _empleado){
            empleado = _empleado;
            siguiente=0;
            anterior=0;
        }
        void Set_contador(int contador){
            this->contador = contador;
        }
        int Get_contador(){
            return this->contador;
        }
};

class ListaEnlazadaCircular{
    private:
        Nodo3* Inicio;
        Nodo3* Fin;
        int contador;
    public:
        ListaEnlazadaCircular(){
            Inicio = 0;
            Fin = 0;
            contador = 0;
           
        }
        void Agregar_Empleado(Empleados* empleado){
            Nodo3* nuevoNodo = new Nodo3(empleado);
            if (Inicio == 0) {
               Inicio = Fin = nuevoNodo;
               nuevoNodo->Set_contador(contador);

            }
            else{
                nuevoNodo->Set_contador(contador);
                nuevoNodo->anterior = Fin;
                Fin->siguiente = nuevoNodo;
                nuevoNodo->siguiente = Inicio;
                Inicio->anterior = nuevoNodo;
                Fin = nuevoNodo;
                
            }
            contador += 1;
            
        }
        void imprimir(){
            Nodo3* aux = Inicio;
            
        }
        
        
};