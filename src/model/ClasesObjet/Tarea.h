#include <iostream>
#pragma once
using namespace std;
//#include "../Estructuras/ListaEnlazada.h"
class Tarea{
    private:
        string Nombre_Tarea;
        string nombre_empleado;

        
    public:
        Tarea(string Nombre_tarea){
            this->Nombre_Tarea = Nombre_Tarea;

        };
        string Get_Nombre(){
            return this->Nombre_Tarea;
        }
        
        
};

