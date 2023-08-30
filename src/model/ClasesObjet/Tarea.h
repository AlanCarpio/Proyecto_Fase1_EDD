#pragma once
#include <iostream>

using namespace std;

class Tarea{
    private:
        string tarea;
        string nombre_empleado;
        //ListaEnlazada* Sucesor = 0;
        //ListaEnlazada* Antecesor = 0;
        //ListaEnlazada* Responsables = 0;
        
    public:
        Tarea(string Nombre_tarea){
            this->tarea = Nombre_tarea;
            //this->Sucesor = new ListaEnlazada();
            //this->Antecesor = new ListaEnlazada();
            //this->Responsables = new ListaEnlazada();
        };
        string Get_Nombre(){
            return this->tarea;
        }
        // constructor responsable
        /*
        Tarea(string Nombre,string empleado){
            this->Nombre_Tarea = Nombre;
            this->nombre_empleado = empleado;
        }
        //Asignar Tarea sucesores antesesores etc
        
        ListaEnlazada* Get_Sucesor(){
            return this->Sucesor;
        }
        ListaEnlazada* Get_Antecesor(){
            return this->Antecesor;
        }
        ListaEnlazada* Get_Responsables(){
            return this->Responsables;
        }
        */
        
};

