#include <iostream>
#include <string>
#include <stdlib.h>
#include "Foto.h"
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

Foto::Foto(){
	if(this->getdebug() == true){
		cout << RED << "CREANDO FOTO... " RESTORE << endl;
	}
	this->ruta;
	this->tipo;
	this->tamanio;	
	this->debug;
}
Foto::~Foto(){
	if(this->getdebug() == true){
		cout << RED << "ELIMINANDO FOTO... " RESTORE << endl;
	}
    //Pongo a NULL todos los miembros de una variable de tipo Foto
    this->ruta = " ";
    this->tipo = " ";
    this->tamanio = -1;
}
/*----- SETS -----*/

void Foto::setRuta(string ruta){

	this->ruta = ruta;
}
void Foto::setTipo(string tipo){

	this->tipo = tipo;
}
void Foto::setTamanio(int tamanio){

	this->tamanio = tamanio;
}

/*----- GETS -----*/
bool Foto::getdebug(){
	return this->debug;
}
string Foto::getRuta(){

    return this->ruta;
}
string Foto::getTipo(){

    return this->tipo;
}
unsigned long int Foto::getTamanio(){

	return this->tamanio;
}

void Foto::setDebug(bool debug){
	this->debug = debug;
}
/************************
** MODULOS DE UTILIDAD **
*************************/

void Foto::PrintFoto(){
	if(this->getdebug() == true){
		cout << RED << "MOSTRANDO FOTO... " RESTORE << endl;
	}
	cout << YELLOW << "Ruta de la foto --> " << CYAN << getRuta() << "." << getTipo() << RESTORE << endl;
	cout << YELLOW << "Tamaño de la foto --> " << CYAN << getTamanio() << " B " << RESTORE << endl;

}
void Foto::borrarFoto(){
/**
* @brief Modulo en el cual vamos a borrar el contenido de  una variable de tipo Foto
* @post Cuando este modulo finalice el contenido de una variable de tipo Foto debe de estar a reseteado.
*/
	if(this->getdebug() == true){
		cout << RED << "BORRANDO FOTO DESDE BORRARFOTO... " RESTORE << endl;
	}
    //Pongo a NULL todos los miembros de una variable de tipo Foto
    this->ruta = " ";
    this->tipo = " ";
    this->tamanio = -1;

}

