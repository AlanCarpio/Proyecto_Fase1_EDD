#include <iostream>
using namespace std;
#include <tuple>
string _username = "PM-202000869";
string _password = "password";
int Login(){
    string username = "";
    string password = "";
    cout << "Enter your Username: "; cin >>username ;
    cout <<"Enter Password :";cin>>password;
    if(username == _username && password== _password)
        return 1;
    else
    {
        return 0;
    }
}
int Main_Menu(){
    int resultado = 0;
    cout << "*********    EDD Proyect Phase 1    *********";
    cout << "*********    Bienvenido :" << _username << "    *********";
    cout << "1. Cargar Empleados ";
    cout << "2. Cargar Proyecto ";
    cout << "3. Crear Tareas ";
    cout << "4. Asignar Tareas ";
    cout << "Elige una Opcion: "; cin >> resultado;
    return resultado;
        
}
//*********************************** Empledos **************************************
int Cargar_Empleado(){
    int resultado = 0;
    cout << "*********    EDD Proyect Phase 1    *********";
    cout << "*********    Bienvenido " << _username << "    *********";
    cout << "*********    Menu Carga Empledos    *********";
    cout << "1. Carga Manual";
    cout << "2. Carga Masiva";
    cout << "Elige una Opcion: "; cin >> resultado;
    return resultado;
}
tuple<string,string,int> Carga_Manual(){
    string nombre;
    string password;
    int resultado = 0;
    cout << "Nombre: "; cin >> nombre;
    cout << "Password: "; cin >> password;
    cout << "Puestos Disponibles";
    cout << "1. Developer Frontend";
    cout << "2. Developer BackEnd";
    cout << "3. Quality Assurance";
    cout << "Elige una Opcion: "; cin >> resultado;
    return make_tuple(nombre,password,resultado);

}
string Carga_Masiva(){
    string archivo;
    cout << "Nombre Archivo"; cin >> archivo;
    return archivo;
}
//**************************** Proyecto ******************************
tuple<string,string> Crear_proyecto(){
    string nombre;
    string Prioridad;
    cout << "*********    EDD Proyect Phase 1    *********";
    cout << "*********    Bienvenido " << _username << "    *********";
    cout << "*********    Menu Crear Proyecto    *********";
    cout << "Ingresa el Nombre del proyecto:";cin>>nombre;
    cout <<"Ingresa la prioridad de tu proyecto (A/B/C):"; cin>>Prioridad;
    return make_tuple(nombre,Prioridad );

}
//**************************** Tareas **********************************
tuple<string,string> Crear_tarea(/* Lista de Proyectos*/ ){
    string ID_proyecto;
    string Nombre_tarea;
    cout << "*********    EDD Proyect Phase 1    *********";
    cout << "*********    Bienvenido " << _username << "    *********";
    cout << "*********    Menu Tareas            *********";
    /*
    Iteracion de proyectos.
    */
   cout << "Elije un proyecto: ";cin >> ID_proyecto;
   cout << "Nombre Tarea: ";cin >> Nombre_tarea;
   return make_tuple(ID_proyecto ,Nombre_tarea) ;
}