#include <iostream>
#include <windows.h>
#include<tuple>
#pragma once
using namespace std;
#include "../view/modules.h"
//#include "../model/ClasesObjet/Tarea.h"
#include "../model/Estructuras/Cola.h"
#include "../model/Estructuras/ListaEnlazada.h"
void Crear_Tarea_Controller(Cola* cola){
    tuple<string,string> Tarea_tuple = Crear_tarea();
    
    Proyecto* proyecto = cola->busqueda_proyecto_tarea(get<0>(Tarea_tuple));
    if (proyecto == 0){
        cout<<"Ese proyecto no existe en nuestra base de datos";
        Sleep(2000);
    }
    else{
        proyecto->Get_Tarea_lista()->Agregar_Tarea(get<1>(Tarea_tuple));
        cout<<"Tarea creada Exitosamente";
        proyecto->Get_Tarea_lista()->Tareas();
        
    }
}
void Asignar_Tarea_controller(){

}
    