#include <iostream>
#include <fstream>
#include <sstream>

#include "../model/Estructuras/ListEnlaCircular.h"
#include "../model/Estructuras/MatrizDisperza.h"
#include "../model/ClasesObjet/Empleados.h"

using namespace std;

int Carga_Masiva_Controller(string dirrecion,ListaEnlazadaCircular* lista,Matriz_Dispersa* Matriz){
    
    ifstream archivo(dirrecion);
    if (!archivo.is_open()) {
        return 0;
    }
    string linea;
    getline(archivo,linea);
    while (getline(archivo, linea)) {
        stringstream stream(linea);
        string nombre, password;
        getline(stream,nombre,',');
        getline(stream,password,',');
        Empleados* empleado = new Empleados(nombre,password);
        Matriz->insertar_empleados(empleado);
        lista->Agregar_Empleado(empleado);
    }
    archivo.close();
    return 1;
}

void Carga_Manual_Controller(string nombre,string password,ListaEnlazadaCircular* listacircular,Matriz_Dispersa* Matriz){
    Empleados* empleado = new Empleados(nombre,password);
    Matriz->insertar_empleados(empleado);
    listacircular->Agregar_Empleado(empleado);
}
