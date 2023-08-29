/*Lista para guardar proyectos*/
#include <iostream>
#include <fstream>
#include "../ClasesObjet/Proyecto.h"

#pragma once
using namespace std;
class Nodo1{
    public:
        Nodo1* siguiente;
        Proyecto* proyecto;
        int posicion;
        Nodo1(Proyecto* _proyecto){
            proyecto = _proyecto;
            siguiente = 0;

        }
        void Set_proyecto(Proyecto* proyecto){
            this->proyecto = proyecto;
        }
        Proyecto* Get_proyecto(){
            return this -> proyecto;
        }
        void Set_posicion(int posicion){
            this->posicion=posicion;
        }
        int Get_posicion(){
            return this->posicion;
        }
        
        
};
class Cola{
    private:
        Nodo1* Inicio;
        Nodo1* Final;
        int contado_ID = 100;
        string ID = "PY-";
        int contador = 0;
    public:
        Cola(){
            this->Inicio = 0;
            this->Final = 0;

        }
        void Insertar_proyecto(Proyecto* proyecto){
            Nodo1* NuevoNodo1 = new Nodo1(proyecto);
            string aux_ID = ID + to_string(contado_ID);
            if (Inicio == 0) {
                Inicio = Final = NuevoNodo1;
                NuevoNodo1->proyecto->Set_ID_proyecto(aux_ID);
                NuevoNodo1->Set_posicion(contador);
            }
            else{
                NuevoNodo1->proyecto->Set_ID_proyecto(aux_ID);
                NuevoNodo1->Set_posicion(contador);
                Final->siguiente = NuevoNodo1;
                Final = NuevoNodo1;
            }
            contado_ID += 1;
            contador += 1;
        }
        Nodo1* buscar_indice(int posicion){
            Nodo1* aux = Inicio;
            while (aux != 0){
                if (aux->Get_posicion() == posicion){
                    return aux;
                }
                aux = aux->siguiente;
            }
        }
        void cambio_de_lugar(Nodo1* proyecto1,Nodo1* proyecto2){
           Proyecto* aux = proyecto1->Get_proyecto();
           proyecto1->Set_proyecto(proyecto2->Get_proyecto());
           proyecto2->Set_proyecto(aux);
            
        }
        void ordenamiento(){
            bool swapped = true;
            while (swapped) {
                swapped = false;
                for (int i = 0; i < contador - 1; i++) {
                    if (buscar_indice(i)->Get_proyecto()->Get_Prioridad() > buscar_indice(i+1)->Get_proyecto()->Get_Prioridad()) {
                        cambio_de_lugar(buscar_indice(i),buscar_indice(i+1));
                        swapped = true;
                    }
                }
            }
        }
        void Graficar(){
            Nodo1* aux = Inicio;
            ofstream archivo;
            string nombre_archivo = "ColaPrioridad.dot";
            string nombre_imagen = "ColaPrioridad.jpg";
            archivo.open(nombre_archivo, ios::out);
            archivo << "digraph ColaPrioridad{ \n node[shape=box] \n rankdir=UD;\n";
            int group = 0;
            archivo << "{rank=same; \n";
            while(aux != 0){
                
                archivo << "nodo" << aux << "[label=\"" << aux->Get_proyecto()->Get_ID_proyecto() << "\\n" << aux->Get_proyecto()->Get_Prioridad() << "\" ,group=" << (group) << "]; \n";
                aux = aux->siguiente;
                group += 1;
                
            }
            archivo << "} \n";
            aux = Inicio;
            while(aux->siguiente != 0){
                archivo << "nodo" << aux << " -> " << "nodo" << aux->siguiente << " [dir=both];\n";
                aux = aux->siguiente;
            }
            archivo << "} \n";
            archivo.close();
            
            string codigo_cmd="dot -Tjpg ";
            codigo_cmd+=nombre_archivo;
            codigo_cmd+=" -o ";
            codigo_cmd+=nombre_imagen;
            char j[codigo_cmd.size()+1];
            strcpy(j,codigo_cmd.c_str());
            system(j);
            
        }
        void Json(){
            Nodo1* aux = Inicio;
            ofstream archivo_json;
            string nombre_archivo = "Proyectos.json";
            archivo_json.open(nombre_archivo, ios::out);
            archivo_json<< "{ \n";
            archivo_json<< "\"Proyectos\":[ \n";
            while(aux!=0){
                if (aux->siguiente != 0){
                    archivo_json<< "{ \n";
                    archivo_json<< "\"ID\""<<":"<<"\""<<aux->Get_proyecto()->Get_ID_proyecto()<<"\",\n";
                    archivo_json<< "\"Nombre\""<<":"<<"\""<<aux->Get_proyecto()->Get_Nombre()<<"\",\n";
                    archivo_json<< "\"Prioridad\""<<":"<<"\""<<aux->Get_proyecto()->Get_Prioridad()<<"\",\n";
                    archivo_json<< "\"Tareas\":[ \n";
                    archivo_json<< aux->Get_proyecto()->Get_Tarea_lista()->Iterar_Tareas();
                    archivo_json<< "]\n";
                    archivo_json<< "},\n";
                }
                else{
                    archivo_json<< "{ \n";
                    archivo_json<< "\"ID\""<<":"<<"\""<<aux->Get_proyecto()->Get_ID_proyecto()<<"\",\n";
                    archivo_json<< "\"Nombre\""<<":"<<"\""<<aux->Get_proyecto()->Get_Nombre()<<"\",\n";
                    archivo_json<< "\"Prioridad\""<<":"<<"\""<<aux->Get_proyecto()->Get_Prioridad()<<"\",\n";
                    archivo_json<< "\"Tareas\":[ \n";
                    archivo_json<< aux->Get_proyecto()->Get_Tarea_lista()->Iterar_Tareas();
                    archivo_json<< "]\n";
                    archivo_json<< "}\n";
                }
                
                aux = aux->siguiente;
            }
            archivo_json<< "]\n";
            archivo_json<< "}\n";
            archivo_json.close();
        }
        bool busqueda(string ID_proyecto){
            Nodo1* aux = Inicio;
            while(aux != 0){
                if(aux->Get_proyecto()->Get_ID_proyecto() == ID_proyecto){
                    return false;
                }
                aux = aux->siguiente;

            }
            return true;
        }
        Proyecto* busqueda_proyecto_tarea(string ID_proyecto){
            Nodo1* aux = Inicio;
            while(aux != 0){
                if(aux->Get_proyecto()->Get_ID_proyecto() == ID_proyecto){
                    return aux->Get_proyecto();
                }
                aux = aux->siguiente;

            }
            return 0;
        }
};
