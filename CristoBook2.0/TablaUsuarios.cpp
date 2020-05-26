#include <iostream>
#include <string>
#include <stdlib.h>
#include "TablaUsuarios.h"
#define RESTORE "\033[1;0m"
#define GREY "\033[1;30m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
using namespace std;

/*----- CONSTRUCTOR Y DESTRUCTOR -----*/

TablaUsuarios::TablaUsuarios(){
	TablaUsuarios *tabla = new TablaUsuarios;
    if (tabla == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }

	int tamanio = 0;
	setTotaltuplas(tamanio);
	tabla->punteroapuntero = new Usuario* [getTotaltuplas(tabla)];
    if (this->punteroapuntero == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
}

TablaUsuarios::~TablaUsuarios(){
    //Pongo a NULL todos los usuarios los cuales son apuntados por los punteros del vector de punteros de una tabla de usuarios
	for (int i = 0; i < getTotaltuplas(); i++){
		~Usuario(this->punteroapuntero[i]);
	}
	//Pongo a 0 las direcciones de memoria que tienen almacenadas los punteros del vector de punteros de una tabla de usuarios
	for (int i = 0; i < getTotaltuplas(); i++){
		(this->punteroapuntero[i]) = 0;
	}
	tabla->totaltuplas = 0;
}

/*----- SETS -----*/
void TablaUsuarios::setTotaltuplas(TablaUsuariosint totalTuplas){

	this->totaltuplas = totalTuplas;
}

/*----- GETS -----*/

int getTotaltuplas(){

    return this->totaltuplas;
}

/************************
** MODULOS DE UTILIDAD **
*************************/

void insertarUsuarioenTabla (Usuario *u, int pos){

	this->punteroapuntero[pos] = u;
}

void PrintTabla(){

bool interactua = true;
	if (getTotaltuplas() == 0){
		cout << RED << "LA TABLA NO EXISTE O HA SIDO BORRADA, POR FAVOR CREE UNA NUEVA TABLA" << RESTORE << endl;
	}
	else{
		//cout << RED << "DEBUG: " << "Entra en el printTabla" << RESTORE << endl;
		for (int i = 0; i < getTotaltuplas(); i++){
			cout << GREEN << "Login del usuario: " << getLogin(this->punteroapuntero[i]) << YELLOW << " --> " << PURPLE << "Nombre del usuario: " << getNombre(this->punteroapuntero[i]) << RESTORE << endl;
		}
		while(interactua == true){
		char c;
		cout << BLUE << "Quieres imprimir más datos de los usuarios pulsa [s]->SI | [n]->NO " << RESTORE << endl;
		cin >> c;
	
			switch(c) {

			case 's':
				for (int i = 0; i < getTotaltuplas(); i++){
					cout << GREEN << "Nombre del usuario: " << getNombre(this->punteroapuntero[i]) << YELLOW << " --> " << PURPLE << "Apellidos del usuario: " << getApellido(this->punteroapuntero[i]) << YELLOW << " --> " << CYAN << "Perfil de usuario: " << getPerfil_usuario(this->punteroapuntero[i]) << YELLOW << " --> " << GREY << "Numero de fotos en perfil: " << getTotalFotosUsuario(this->punteroapuntero[i]) << RESTORE << endl;
				}
				interactua = false;
				break;
			case 'n':
				cout << RED << "Se ha pulsado NO, dejando de imprimir datos de usuario..." << RESTORE << endl;
				interactua = false;
				break;
			default:
				cout << RED << "Has pulsado una tecla que no es valida, vuelve a intentarlo haciendole caso al enunciado por favor ;)" << RESTORE << endl;
			}
		}
	}

}
