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

	int totalusuarios = 0;
	setTotalUsuarios(totalusuarios);
	this->punteroapuntero = new Usuario* [getTotalUsuarios()];
    if (this->punteroapuntero == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
}

TablaUsuarios::~TablaUsuarios(){
    //Pongo a NULL todos los usuarios los cuales son apuntados por los punteros del vector de punteros de una tabla de usuarios
	for (int i = 0; i < getTotalUsuarios(); i++){
		borrarUsuario(this->punteroapuntero[i]);
	}
	//Pongo a 0 las direcciones de memoria que tienen almacenadas los punteros del vector de punteros de una tabla de usuarios
	for (int i = 0; i < getTotalUsuarios(); i++){
		(this->punteroapuntero[i]) = 0;
	}
	this->totalusuarios = 0;
}

/*----- SETS -----*/
void TablaUsuarios::setTotalUsuarios(int totalusuarios){

	this->totalusuarios = totalusuarios;
}

/*----- GETS -----*/

int TablaUsuarios::getTotalUsuarios(){

    return this->totalusuarios;
}

/************************
** MODULOS DE UTILIDAD **
*************************/

void TablaUsuarios::insertarUsuarioenTabla (Usuario *u, int pos){

	this->punteroapuntero[pos] = u;
}

void TablaUsuarios::PrintTabla(){

bool interactua = true;
	if (getTotalUsuarios() == 0){
		cout << RED << "LA TABLA NO EXISTE O HA SIDO BORRADA, POR FAVOR CREE UNA NUEVA TABLA" << RESTORE << endl;
	}
	else{
		//cout << RED << "DEBUG: " << "Entra en el printTabla" << RESTORE << endl;
		for (int i = 0; i < getTotalUsuarios(); i++){
			PrintUsuario(this->punteroapuntero[i]);
		}
	}
}
