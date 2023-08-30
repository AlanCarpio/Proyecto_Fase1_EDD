#include <iostream>
#pragma once
using namespace std;
#include "../Estructuras/ListaEnlazada.h"
#include "Tarea.h"

class Proyecto{
    private:
       string ID_proyecto;
       string ID_empleado;
       string Nombre;
       char Prioridad;
       ListaEnlazada* tarea;
      
    public:
        Proyecto(string _Nombre){
            this->Nombre=_Nombre;
        }
        Proyecto(string _Nombre,char _Prioridad){
            this->Nombre=_Nombre;
            this->Prioridad=_Prioridad;
            this->tarea = new ListaEnlazada();
        }
        Proyecto(string ID_proyecto,string ID_empleado){
            this->ID_proyecto=ID_proyecto;
            this->ID_empleado = ID_empleado;
        }
        // ID_empleado
        string Get_ID_empleado(){
            return ID_empleado;
        }
        //----------Prioridad
        char Get_Prioridad(){
            return (this->Prioridad);
        }
        void Set_Prioridad(char prioridad){
            this->Prioridad = prioridad;
        }
        //----------- ID proyecto
        string Get_ID_proyecto(){
            return ID_proyecto;
        }
        void Set_ID_proyecto(string ID_proyecto){
            this->ID_proyecto = ID_proyecto;
        }
        //----------- Nombre
        string Get_Nombre(){
            return Nombre;
        }
        void Set_Nombre(string Nombre){
            this->Nombre = Nombre;
        }
        //-------Tarea -------
        
        ListaEnlazada* Get_Tarea_lista(){
            return tarea;
        }
        
        
    
};
