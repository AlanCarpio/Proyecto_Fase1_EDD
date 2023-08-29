#include <iostream>
#include <windows.h>
#include<tuple>
#include "../view/modules.h"
#include "../model/Estructuras/Cola.h"
#include "../model/Estructuras/MatrizDisperza.h"
#include "../model/Estructuras/ListEnlaCircular.h"
#include "../model/Estructuras/ListaEnlazada.h"
#include "../model/ClasesObjet/Proyecto.h"
using namespace std;
void Crear_Proyecto_Controller(Cola* cola,Cola* Prioridad,Matriz_Dispersa* Matriz){
    tuple<string,char> proyecto_tuple = Crear_proyecto();
    Proyecto* proyecto = new Proyecto(get<0>(proyecto_tuple),get<1>(proyecto_tuple));
    ListaEnlazada* lista_tareas = new ListaEnlazada();
    proyecto->Set_Tarea_lista(lista_tareas); 
    Matriz->insertar_proyectos(proyecto);
    cola->Insertar_proyecto(proyecto);
    Prioridad->Insertar_proyecto(proyecto);
    system("cls");
    cout<<"Proyecto Creado Exitosamente...";
    Sleep(2000);
    
}
void Asignar_Proyecto_Controller(Matriz_Dispersa* Matriz,Cola* cola,ListaEnlazadaCircular* circular){
    Matriz->Graficar();
    tuple<string,string> proyecto_tuple = Asignar_proyecto();
    Matriz->Asignar_proyecto(get<0>(proyecto_tuple),get<1>(proyecto_tuple),cola,circular);
    Matriz->Graficar();     
}
//