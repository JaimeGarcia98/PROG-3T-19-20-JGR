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
	if(this->getdebug() == true){
		cout << RED << "CREANDO USUARIO... " RESTORE << endl;
	}
	this->login = " ";
	this->nombre = " ";
	this->apellido = " ";
	this->perfil_usuario = " ";
}

Usuario::~Usuario(){
	if(this->getdebug() == true){
		cout << RED << "BORRANDO USUARIO... " RESTORE << endl;
	}
}
/*----- SETS -----*/

void Usuario::setDebug(bool debug){
	this->debug = debug;
}
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
bool Usuario::getdebug(){
	return this->debug;
}
string Usuario::getLogin(){

    return this->login;
}
string Usuario::getNombre(){

    return this->nombre;
}
string Usuario::getApellido(){

    return this->apellido;
}
string Usuario::getPerfil_usuario(){

    return this->perfil_usuario;
}
void Usuario::Filtro(){

	cin.clear();
	cin.ignore(256, '\n');
}
void Usuario::RellenarUsuario(){
	//int posicion = 0;
	string login;
	string nombre;
	string apellido;
	string perfil;	

	if(this->getdebug() == true){
		cout << RED << "RELLENANDO USUARIO... " RESTORE << endl;
	}
	cout << GREY << "A continuación se va a proceder a crear un usuario, por favor rellene los siguientes campos acorde con lo mostrado... " << RESTORE << endl;
	cout << GREEN << "INTRODUCE EL LOGIN DEL USUARIO A CREAR, DEBE DE EMPEZAR POR '@': " << RESTORE << endl;

	Filtro();
	getline(cin,login);
	this->setLogin(login);
	//cout << getLogin(u) << endl;
	cout << GREEN << "INTRODUCE EL NOMBRE DEL USUARIO A CREAR: " << RESTORE << endl;
	getline(cin,nombre);
	this->setNombre(nombre);
	//cout << getNombre(u) << endl;
	cout << GREEN << "INTRODUCE EL PRIMER APELLIDO DEL USUARIO A CREAR: " << RESTORE << endl;
	getline(cin,apellido);
	this->setApellido(apellido);
	//cout << getApellido(u) << endl;
	cout << GREEN << "INTRODUCE EL NOMBRE PARA QUE APAREZCA EN EL PERFIL DEL USUARIO A CREAR: " << RESTORE << endl;
	getline(cin, perfil);
	this->setPerfil_usuario(perfil);
	//cout << getPerfil_usuario(u) << endl;
	if(this->getdebug() == true){
		cout << RED << "USUARIO RELLENO CORRECTAMENTE... " RESTORE << endl;
	}
}

void Usuario::PrintUsuario(){
	if(this->getdebug() == true){
		cout << RED << "MOSTRANDO USUARIO... " RESTORE << endl;
	}
	cout << GREEN << "Login del usuario: " << getLogin() << YELLOW << " --> " << PURPLE << "Nombre del usuario: " << getNombre() << RESTORE << endl;
}

/*--------------------------- ADMIN ---------------------------*/

Admin::Admin(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: CREANDO USUARIO ADMINISTRADOR... " << RESTORE << endl;
	}
	this->login = " ";
	this->nombre = " ";
	this->apellido = " ";
	this->perfil_usuario = " ";
	this->total_consultas = 0;
}
Admin::~Admin(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: BORRANDO USUARIO ADMINISTRADOR... " << RESTORE << endl;
	}
}
void Admin::setDebug(bool debug){
	this->debug = debug;
}

int Admin::getTotalconsultas(){
	return this->total_consultas;
}
bool Admin::getdebug(){
	return this->debug;
}
void Admin::setTotalConsultas(int total){
	this->total_consultas = total;
}
void Admin::RellenarUsuario(){
	int numero;
	if(this->getdebug() == true){
		cout << RED << "RELLENANDO USURARIO ADMINISTRADOR... " RESTORE << endl;
	}
	this->Usuario::RellenarUsuario();
	cout << GREEN << "INTRODUCE EL NUMERO DE CONSULTAS: " << RESTORE << endl;
	cin >> numero;
	while(!cin){
		cout << RED << "No introduzcas letras, intentalo de nuevo" << RESTORE << endl;	
		Filtro();
		cin >> numero;
	}
	if(this->getdebug() == true){
		cout << RED << "USUARIO ADMINISTRADOR RELLENO... " RESTORE << endl;
	}
}
void Admin::PrintUsuario(){
	if(this->getdebug() == true){
		cout << RED << "MOSTRANDO USUARIO ADMINISTRADOR... " RESTORE << endl;
	}
	cout << GREEN << "Login del usuario ADMIN: " << getLogin() << YELLOW << " --> " << PURPLE << "Nombre del usuario: " << getNombre() << RESTORE << endl;
	cout << RED << "Consultas: " << getTotalconsultas() << RESTORE << endl;
}

/*--------------------------- NORMAL ---------------------------*/

Normal::Normal(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: CREANDO USUARIO NORMAL... " << RESTORE << endl;
	}
	int totalfotos = 0;
	int dim_fotos = 3;
	
	this->v_fotos = new Foto [dim_fotos];
    if (this->v_fotos == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
	setDimFotos(dim_fotos);
	setTotalFotosUsuario(totalfotos);
}

Normal::~Normal(){
	if(this->getdebug() == true){
		cout << RED << "ELIMINANDO USUARIO NORMAL... " << RESTORE << endl;
	}
	delete [] this->v_fotos;
	v_fotos = 0;
    this->dim_fotos = 0;
    this->totalFotosUsuario = 0;
	

}
void Normal::setDebug(bool debug){
	this->debug = debug;
	for(int i = 0; i < this->getTotalFotosUsuario(); i++){
		this->v_fotos[i].setDebug(debug);
	}
}

void Normal::setTotalFotosUsuario(int totalfotos){
	this->totalFotosUsuario = totalfotos;
}
int Normal::getTotalFotosUsuario(){
	return this->totalFotosUsuario;
}
bool Normal::getdebug(){
	return this->debug;
}
void Normal::setDimFotos(int dim){
	this->dim_fotos = dim;
}
int Normal::getDimFotos(){
	return this->dim_fotos;
}
void Normal::InsertarFotoEnUsuario(Foto f){
	this->v_fotos[this->getTotalFotosUsuario()] = f;
	this->setTotalFotosUsuario(this->getTotalFotosUsuario() + 1);	
}
void Normal::ResizeAumentarVectorFotos(int dim_nueva){
	if(this->getdebug() == true){
		cout << RED << "AUMENTANDO VECTOR DE FOTOS... " RESTORE << endl;
	}
	Foto* vectorfotos_ampliado;
	//1) Creo el vector de punteros nuevo con una dimensión 1 unidad mayor.
	vectorfotos_ampliado = new Foto [dim_nueva];
    	if (vectorfotos_ampliado == 0){
        	cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        	exit(-1);
    	}
		//1)Copio el vector antiguo en el vector nuevo
		for (int i = 0; i < this->getTotalFotosUsuario(); i++){
			vectorfotos_ampliado[i] = this->v_fotos[i];
		}
		//2)Borro el vector antiguo
		delete [] this->v_fotos;
		this->v_fotos = 0;
		//3)Asigno al miembro v_fotos del usuario el nuevo vector de fotos con 1 unidad más de tamaño
		this->v_fotos = vectorfotos_ampliado;
		//4)Cambio los miembros dim_vfotos(dimension del vector) y totalfotosusuario(utiles del vector)
		setDimFotos(dim_nueva);
		setTotalFotosUsuario(dim_nueva - 1);
	if(this->getdebug() == true){
		cout << RED << "VECTOR DE FOTOS AUMENTADO... " RESTORE << endl;
	}
}
void Normal::EliminarFotoUsuario(int pos){
	if(this->getdebug() == true){
		cout << RED << "ELIMINANDO FOTO DE USUARIO " RESTORE << endl;
	}
	this->v_fotos[pos] = this->v_fotos[pos - 1];
	this->setTotalFotosUsuario(this->getTotalFotosUsuario() - 1);
	if(this->getdebug() == true){
		cout << RED << "FOTO DE USUARIO ELIMINADA... " RESTORE << endl;
	}
}
void Normal::RellenarUsuario(){
	int saldo;
	if(this->getdebug() == true){
		cout << RED << "RELLENANDO USUARIO NORMAL... " RESTORE << endl;
	}
	this->Usuario::RellenarUsuario();
	cout << GREEN << "INTRODUCE EL SALDO: " << RESTORE << endl;
	cin >> saldo;
	while(!cin){
		cout << RED << "No introduzcas letras, intentalo de nuevo" << RESTORE << endl;	
		Filtro();
		cin >> saldo;
	}
	if(this->getdebug() == true){
		cout << RED << "USUARIO NORMAL RELLENADO CORRECTAMENTE... " RESTORE << endl;
	}
}
void Normal::PrintUsuario(){
	if(this->getdebug() == true){
		cout << RED << "MOSTRANDO USUARIO NORMAL... " RESTORE << endl;
	}
	this->Usuario::PrintUsuario();
	if ((getTotalFotosUsuario()) == 0){
			cout << RED << "EL USUARIO NO TIENE FOTOS, POR FAVOR ASEGURESE DE QUE EL USUARIO ELEGIDO TENGA AL MENOS UNA FOTO PARA PODER SER MOSTRADA... " << RESTORE << endl;
	}			
	else{
		cout << GREEN << "IMPRIMENDO FOTOS DEL USUARIO " << RESTORE << endl;
		for(int i = 0; i < getTotalFotosUsuario(); i++){
			cout << RED << "Nº " << i + 1 << RESTORE << endl; 
			this->v_fotos[i].PrintFoto();
		}
	}
}


