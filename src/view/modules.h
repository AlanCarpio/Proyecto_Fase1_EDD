#include <iostream>
using namespace std;
#pragma once
#include <tuple>
string _username = "PM-202000869";
string _password = "password";
BOOLEAN Login(){
    string username = "";
    string password = "";
    cout << "Enter your Username: "; cin >>username ;
    cout <<"Enter Password :";cin>>password;
    if(username == _username && password== _password)
        return false;
    else
    {
        cout<<"Password o UserName incorrecto"<<endl;
        return true;
    }
}
int Main_Menu(){
    int resultado = 0;
    cout << "*********    EDD Proyect Phase 1    *********"<<endl;
    cout << "*********    Bienvenido :" << _username << "    *********"<<endl;
    cout << "1. Cargar Empleados "<<endl;
    cout << "2. Crear Proyecto "<<endl;
    cout << "3. Crear Tareas "<<endl;
    cout << "4. Asignar Tareas "<<endl;
    cout << "5. Asignar Proyecto"<<endl;
    cout << "6. Salir"<<endl;
    cout << "Elige una Opcion: "; cin >> resultado;
    return resultado;
        
}
//*********************************** Empledos **************************************
int Cargar_Empleado(){
    int resultado = 0;
    cout << "*********    Bienvenido " << _username << "    *********"<<endl;
    cout << "*********    EDD Proyect Phase 1    *********"<<endl;
    cout << "*********    Menu Carga Empledos    *********"<<endl;
    cout << "1. Carga Manual"<<endl;
    cout << "2. Carga Masiva"<<endl;
    cout << "3. Main Menu"<<endl;
    cout << "Elige una Opcion: "; cin >> resultado;
    return resultado;
}
tuple<string,string> Carga_Manual(){
    string nombre;
    string password;
    cout << "Nombre: "; cin >> nombre;
    cout << "Password: "; cin >> password;
    return make_tuple(nombre,password);

}
string Carga_Masiva(){
    string archivo;
    cout << "Nombre Archivo: "; cin >> archivo;
    return archivo;
}
//**************************** Proyecto ******************************
tuple<string,char> Crear_proyecto(){
    string nombre;
    char Prioridad;
    cout << "*********    EDD Proyect Phase 1    *********"<<endl;
    cout << "*********    Bienvenido " << _username << "    *********"<<endl;
    cout << "*********    Menu Crear Proyecto    *********"<<endl;
    cout << "Ingresa el Nombre del proyecto:";cin>>nombre;
    cout <<"Ingresa la prioridad de tu proyecto (A/B/C):"; cin>>Prioridad;
    return make_tuple(nombre,Prioridad );

}
tuple<string,string> Asignar_proyecto(){
    string nombre;
    string ID_proyecto;
    cout << "*********    EDD Proyect Phase 1    *********"<<endl;
    cout << "*********    Bienvenido " << _username << "    *********"<<endl;
    cout << "*********    Asginar Proyecto       *********"<<endl;
    cout << "Ingresa el Nombre del Empleado: ";cin>>nombre;
    cout << "Ingrese el ID proyecto: "; cin>>ID_proyecto;
    return make_tuple(nombre,ID_proyecto);
}
//**************************** Tareas **********************************
tuple<string,string> Crear_tarea(/* Lista de Proyectos*/ ){
    string ID_proyecto;
    string Nombre_tarea;
    cout << "*********    EDD Proyect Phase 1    *********"<<endl;
    cout << "*********    Bienvenido " << _username << "    *********"<<endl;
    cout << "*********    Menu Tareas            *********"<<endl;
   cout << "Elije un proyecto(ID): ";cin >> ID_proyecto;
   cout << "Nombre Tarea: ";cin >> Nombre_tarea;
   return make_tuple(ID_proyecto ,Nombre_tarea) ;
}
tuple<string,string> Asignar_Tarea(/* Lista de Proyectos*/ ){
    string ID_proyecto;
    string Nombre_tarea;
    cout << "*********    EDD Proyect Phase 1    *********";
    cout << "*********    Bienvenido " << _username << "    *********";
    cout << "*********    Menu Tareas            *********";
   cout << "Elije un proyecto: ";cin >> ID_proyecto;
   cout << "Nombre Tarea: ";cin >> Nombre_tarea;
   return make_tuple(ID_proyecto ,Nombre_tarea) ;
}
