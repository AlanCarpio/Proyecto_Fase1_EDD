#include <iostream>
#pragma once
using namespace std;

class Empleados{
    private:
        string Nombre;
        string Password;
        string ID_empleado;
    public:
        Empleados(string _Nombre,string _Password){
            Nombre = _Nombre;
            Password= _Password;
            this->ID_empleado = "vacio";
        }
        string Get_Nombre(){
            return Nombre;
        }
        string Get_ID_empleado(){
            return ID_empleado;
        }
        void Set_ID_empleado(string ID){
            this->ID_empleado = ID;
        }
        
};

