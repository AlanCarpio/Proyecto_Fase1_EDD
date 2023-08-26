#include <iostream>
#include <windows.h>
#include<tuple>
#include "../view/modules.h"
#include "../model/Estructuras/Cola.h"
#include "../model/Estructuras/MatrizDisperza.h"
#include "../model/ClasesObjet/Proyecto.h"
using namespace std;
void Crear_Proyecto_Controller(Cola* cola,Matriz_Dispersa* Matriz){
    tuple<string,char> proyecto_tuple = Crear_proyecto();
    Proyecto* proyecto = new Proyecto(get<0>(proyecto_tuple),get<1>(proyecto_tuple));
    Matriz->insertar_proyectos(proyecto);
    cola->Insertar_proyecto(proyecto);
    system("cls");
    cout<<"Proyecto Creado Exitosamente...";
    Sleep(2000);
    
}
void Asignar_Proyecto_Controller(Matriz_Dispersa* Matriz){
    tuple<string,string> proyecto_tuple = Asignar_proyecto();
    Matriz->Asignar_proyecto(get<0>(proyecto_tuple),get<1>(proyecto_tuple));     
}
//