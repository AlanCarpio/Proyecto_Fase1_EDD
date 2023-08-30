#include <iostream>
#include <windows.h>
#include <tuple>
using namespace std;
#include "../model/Estructuras/ListEnlaCircular.h"
#include "../model/Estructuras/Cola.h"
#include "../model/Estructuras/ListaEnlazada.h"
#include "../view/modules.h"
#include "Empleado_Controller.h"
#include "Proyecto_Controller.h"
#include "Tareas_Controller.h"

int Cargar_Empleado_Start(ListaEnlazadaCircular* listacircular,Matriz_Dispersa* Matriz){
    //system("cls");
    int result = Cargar_Empleado();
    if (result == 1){
        system("cls");
        tuple<string,string> tuple01 = Carga_Manual();
        Carga_Manual_Controller(get<0>(tuple01),get<1>(tuple01),listacircular,Matriz);
        cout << "Creado Exitosamente"<<endl;
        Sleep(2000);
        system("cls");
        Cargar_Empleado_Start(listacircular,Matriz);
    }
    else if(result == 2){
        int result_1 = Carga_Masiva_Controller(Carga_Masiva(),listacircular,Matriz);
        //system("cls");
        if (result_1 == 1){
            cout<<"Carga Exitosa"<<endl;
        }
        else{
            cout << "No se pudo abrir el archivo." <<endl;
        }
        Sleep(2000);
        Cargar_Empleado_Start(listacircular,Matriz);
    }              
    else if(result == 3){
        system("cls");
        cout << "Regresando al Main Menu..."<<endl;
        Sleep(2000);
        return 0;
        Cargar_Empleado_Start(listacircular,Matriz);
    } 
    else{
        system("cls");
        cout << "Ingrese un Numero Valido"<<endl;
        Sleep(2000);
        Cargar_Empleado_Start(listacircular,Matriz);
    }             
}

int Start(){
    string archivo;
    bool Estado = true;
    Cola* Cola_Ordenada = new Cola();
    ListaEnlazadaCircular* listacircular = new ListaEnlazadaCircular(); // Almacena Tareas
    Matriz_Dispersa* Matriz = new Matriz_Dispersa();// Proyecto vs Empleado
    Cola* Cola_proyectos = new Cola();//Almacena Proyectos
    ListaEnlazada* listaTarea = new ListaEnlazada();

    while (Estado){
        //system("cls");
        switch (Main_Menu()){
        case 1:
            system("cls");
            Cargar_Empleado_Start(listacircular,Matriz);
            system("cls");
            break;
        case 2:
            system("cls");
            Crear_Proyecto_Controller(Cola_proyectos,Cola_Ordenada,Matriz);
            break;
        case 3:
            system("cls");
            Cola_Ordenada->ordenamiento();
            Cola_Ordenada->Graficar();
            Crear_Tarea_Controller(Cola_proyectos);
            break;
        case 4:
            system("cls");
            //Cola_proyectos->Json();
            Asignar_Tarea_controller(listaTarea);
            break;
        case 5:
            system("cls");
            Asignar_Proyecto_Controller(Matriz,Cola_proyectos,listacircular);
            break;
        case 6:
            system("cls");
            Estado = false;
            delete listacircular;
            delete Matriz;
            delete Cola_proyectos;
            break;
        default:
            system("cls");
            cout<<"Ingrese un numero valido"<<endl;

            break;
        }
        
    }
}