#include <iostream>
#include <string>
#include <stdlib.h>
#include "Usuario.h"
#define RESTORE "\033[1;0m"
#define GREY "\033[1;30m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
using namespace std;

Usuario::Usuario(){
	this->login = " ";
	this->nombre = " ";
	this->apellido = " ";
	this->perfil_usuario = " ";
}

Usuario::~Usuario(){
	cout << RED << "DEBUG: BORRANDO USUARIO... " << RESTORE << endl;
}
/*----- SETS -----*/

void Usuario::setLogin(string login){

	this->login = login;
}
void Usuario::setNombre(string nombre){

	this->nombre = nombre;
}
void Usuario::setApellido(string apellido){

	this->apellido = apellido;
}
void Usuario::setPerfil_usuario(string perfil_usuario){

	this->perfil_usuario = perfil_usuario;
}
/*----- GETS -----*/

string Usuario::getLogin(){

    return this->login;
}
string Usuario::getNombre(){

    return this->nombre;
}
string Usuario::getApellido(){

    return u->apellido;
}
string Usuario::getPerfil_usuario(){

    return this->perfil_usuario;
}

void Usuario::borrarUsuario(Usuario *u){

    //Pongo a NULL todos los miembros de una variable de tipo Usuario
    u->login = "";
    u->nombre = "";
    u->apellido = "";
    u->perfil_usuario = "";
	for (int i = 0; i < getTotalFotosUsuario(u); i++){
    	borrarFoto(getV_fotos(u, i));
	}
    u->dim_vfotos = -1;
    u->totalFotosUsuario = -1;
    //Borro el fragmento de memoria
    delete u;
    //elimino la dirección que referenciaba al fragmento de memoria
    u = 0;
}

void Usuario::PrintUsuario(Usuario *u){
	cout << GREEN << "Login del usuario: " << getLogin() << YELLOW << " --> " << PURPLE << "Nombre del usuario: " << getNombre() << RESTORE << endl;
}

/*--------------------------- ADMIN ---------------------------*/

Admin::Admin(){

}
