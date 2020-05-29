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
		delete this->punteroapuntero[i];
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

void TablaUsuarios::resizeTablaUsuariosCrecer (int dim_nueva){
	cout << RED << "DEBUG: ENTRANDO EN RESIZE DE TABLAUSUARIOS +... " << RESTORE << endl;
	Usuario** vector_ampliado;
	//1) Creo el vector de punteros nuevo con una dimensión 1 unidad mayor.
	vector_ampliado = new Usuario* [dim_nueva];
    	if (vector_ampliado == 0){
        	cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        	exit(-1);
    	}
	cout << RED << "DEBUG: VECTOR AUXILIAR CREADO " << RESTORE << endl;
	//2)Copio el vector antiguo en el vector nuevo
	for (int i = 0; i < this->getTotalUsuarios(); i++){
		vector_ampliado[i] = this->punteroapuntero[i];
	}
	cout << RED << "DEBUG: COPIA DEL VECTOR REALIZADA " << RESTORE << endl;
	//3)Borro el vector antiguo
	delete [] this->punteroapuntero;
	this->punteroapuntero = 0;
	cout << RED << "DEBUG: VECTOR ANTIGUO ELIMINADO " << RESTORE << endl;
	//4)Asigno al miembro punteroapuntero de la tabla el nuevo vector de punteros con 1 unidad más de tamaño
	this->punteroapuntero = vector_ampliado;
	this->setTotalUsuarios(dim_nueva);
	cout << RED << "DEBUG: REASIGNACION REALIZADA, ACABANDO EL RESIZE... " << RESTORE << endl;
	
}
/*void TablaUsuarios::resizeTablaUsuariosDisminuir (int dim_nueva, int posicion){
	Usuario** vector_aux;
	//1) Creo el vector de punteros nuevo con la misma dimensión que la original.
	vector_aux = new Usuario* [this->getTotaltuplas()];
    	if (vector_aux == 0){
        	cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        	exit(-1);
    	}
	//2)Copio el vector antiguo en el vector nuevo
	for (int i = 0; i < this->getTotaltuplas(); i++){
		vector_aux[i] = this->punteroapuntero[i];
	}
	eliminarUsuarioenTabla (vector_aux, posicion, getTotaltuplas(tabla));
	//3)Borro el vector antiguo
	delete [] tabla->punteroapuntero;
	tabla->punteroapuntero = 0;
	//4)Asigno al miembro punteroapuntero de la tabla el nuevo vector de punteros con 1 unidad más de tamaño
	tabla->punteroapuntero = vector_aux;
	setTotalUsuarios(tabla, dim_nueva);
	
}*/
void TablaUsuarios::insertarUsuarioenTabla (Usuario *u, int pos){

	this->punteroapuntero[pos] = u;
}

void TablaUsuarios::TablaPorDefecto(){

	cout << YELLOW << "CREANDO TABLA POR DEFECTO... " << RESTORE << endl;
	Admin* Jaime = new Admin();
	Normal* Jose = new Normal();
	Admin* Juan = new Admin();
	Normal* Pepe = new Normal();
	Admin* Antonio = new Admin();
	Normal* Pablo = new Normal();
	Admin* Manuel = new Admin();
	Foto jose;
	Foto pepe;
	Foto pablo;
	
/*-----------------------------------------------*/
	cout << YELLOW << "INSERTANDO EL PRIMER USUARIO" << RESTORE << endl;
	Jaime->setLogin("@Champi");
	cout << YELLOW << "LOGIN INSERTADO" << RESTORE << endl;
	Jaime->setNombre("Jaime");
	cout << YELLOW << "NOMBRE INSERTADO" << RESTORE << endl;
	Jaime->setApellido("García");
	cout << YELLOW << "APELLIDO INSERTADO" << RESTORE << endl;
	Jaime->setPerfil_usuario("Pogramador León");
	cout << YELLOW << "PERFIL INSERTADO" << RESTORE << endl;
	insertarUsuarioenTabla (Jaime, 0);//Inserto el usuario 0 en la tabla
	cout << YELLOW << "USUARIO INSERTADO" << RESTORE << endl;
	Jaime->setTotalConsultas(0);
/*-----------------------------------------------*/
	
	Jose->setLogin("@JoseHenrique");
	Jose->setNombre("Jose Henrique");
	Jose->setApellido("Ortis");
	Jose->setPerfil_usuario("Waterpolista de alto riesgo");
	insertarUsuarioenTabla (Jose, 1);//Inserto el usuario 1 en la tabla
	jose.setRuta("../Escritorio/Imagenes/imagen1"); 
	jose.setTipo("png");
	jose.setTamanio(15);	
	Jose->InsertarFotoEnUsuario(jose);
	Jose->setTotalFotosUsuario(1);
	
/*-----------------------------------------------*/
	
	Juan->setLogin("@Juansiyo");
	Juan->setNombre("Juan");
	Juan->setApellido("López");
	Juan->setPerfil_usuario("Portador del COVID-19");
	insertarUsuarioenTabla (Juan, 2);//Inserto el usuario 2 en la tabla
	Juan->setTotalConsultas(0);

/*-----------------------------------------------*/
	
	Pepe->setLogin("@Pepiyo");
	Pepe->setNombre("Pepe");
	Pepe->setApellido("Heredia");
	Pepe->setPerfil_usuario("Pelador de cable profesional");
	insertarUsuarioenTabla (Pepe, 3);//Inserto el usuario 3 en la tabla
	pepe.setRuta("../Escritorio/cable1"); 
	pepe.setTipo("png");
	pepe.setTamanio(21);
	Pepe->InsertarFotoEnUsuario(pepe);
	Pepe->setTotalFotosUsuario(1);

/*-----------------------------------------------*/
	
	Antonio->setLogin("@Antoñin");
	Antonio->setNombre("Antonio");
	Antonio->setApellido("Hernández");
	Antonio->setPerfil_usuario("Jugador de parchís techado");
	insertarUsuarioenTabla (Antonio, 4);//Inserto el usuario 4 en la tabla
	Antonio->setTotalConsultas(0);

/*-----------------------------------------------*/
	
	Pablo->setLogin("@Pablisho");
	Pablo->setNombre("Pablo");
	Pablo->setApellido("Fernández");
	Pablo->setPerfil_usuario("Humano");
	insertarUsuarioenTabla (Pablo, 5);//Inserto el usuario 5 en la tabla
	pablo.setRuta("../Escritorio/Pablo/Fotos/ViajeGrecia/img2"); 
	pablo.setTipo("png");
	pablo.setTamanio(42);
	Pablo->InsertarFotoEnUsuario(pablo);
	Pablo->setTotalFotosUsuario(1);

/*-----------------------------------------------*/
	
	Manuel->setLogin("@Maolillo");
	Manuel->setNombre("Manuel");
	Manuel->setApellido("Agudo");
	Manuel->setPerfil_usuario("Apicultor");
	insertarUsuarioenTabla (Manuel, 6);//Inserto el usuario 6 en la tabla
	Manuel->setTotalConsultas(0);

	cout << YELLOW << "TABLA POR DEFECTO CREADA" << RESTORE << endl;
}
void TablaUsuarios::AnadirFotoUsuario(){
Foto f;
string login;
string ruta;
string extension;
int tamanio = 0;
int posicion = 0;
	cout << PURPLE "Introduce el login del usuario en el cual quieres introducir una foto..." << RESTORE << endl;
	cin >> login;
	posicion = BusquedaLogin(login);
	if (posicion == -1){
		cout << RED << "EL LOGIN INTRODUCIDO NO CORRESPONDE CON NINGUN USUARIO, NO SE PUEDE INTRODUCIR FOTO, VOLVIENDO AL MENÚ PRINCIPAL..." << RESTORE << endl;
	}
	else{
		Normal* us1;
		Normal* us2;
		if(us1 = dynamic_cast < Normal* > (this->punteroapuntero[posicion])){
			us2 = us1;
			cout << PURPLE << "INTRODUCE LA RUTA DE LA FOTO SIN EXTENSION (EJ: ..Desktop/Images/Image1 ) " << RESTORE << endl;
			cin >> ruta;
			f.setRuta(ruta); 
			cout << PURPLE << "INTRODUCE LA EXTENSION DE LA FOTO (EJ: jpg, png... ) " << RESTORE << endl;
			cin >> extension;
			f.setTipo(extension);
			cout << PURPLE << "INTRODUCE EL TAMAÑO DE LA FOT EN BYTES (EJ: 32, 22331... ) " << RESTORE << endl;
			cin >> tamanio;
			f.setTamanio(tamanio);
			cout << us2->getTotalFotosUsuario() << endl;
			cout << us2->getDimFotos() << endl;
			if(us2->getTotalFotosUsuario() >= us2->getDimFotos()){
				us2->ResizeAumentarVectorFotos(us2->getTotalFotosUsuario() + 1);
				cout << RED << "DEBUG: INTRODUCIENDO FOTO EN EL VECTOR DINAMICO DE FOTOS DE UN USUARIO... " << RESTORE << endl;
				us2->InsertarFotoEnUsuario(f);
				us2->setTotalFotosUsuario(us2->getTotalFotosUsuario() + 1);
				cout << GREEN << "FOTO INTRODUCIDA CORRECTAMENTE" << RESTORE << endl;
			}
			else{
				us2->InsertarFotoEnUsuario(f);
				us2->setTotalFotosUsuario(us2->getTotalFotosUsuario() + 1);
			}
		}
		else{
			cout << RED << "USUARIO NO VALIDO PARA GUARDAR FOTOS, VOLVIENDO AL MENU PRINCIPAL..." << RESTORE << endl;
		}
		
		//PrintFoto(tabla->punteroapuntero[posicion]->v_fotos[0]);
	}
	
}
void TablaUsuarios::ImprimirFotosUsuario(){
string login;
int posicion = 0;
	cout << PURPLE "Introduce el login del usuario el cual quieres imprimir sus fotos..." << RESTORE << endl;
	cin >> login;
	posicion = BusquedaLogin(login);
	if (posicion == -1){
		cout << RED << "EL LOGIN INTRODUCIDO NO CORRESPONDE CON NINGUN USUARIO, NO SE PUEDEN MOSTRAR LAS FOTOS, VOLVIENDO AL MENÚ PRINCIPAL..." << RESTORE << endl;
	}
	else{
		Normal* us1;
		Normal* us2;
		if(us1 = dynamic_cast < Normal* > (this->punteroapuntero[posicion])){
			us2 = us1;
			if ((us2->getTotalFotosUsuario()) == 0){
			cout << RED << "EL USUARIO NO TIENE FOTOS, POR FAVOR ASEGURESE DE QUE EL USUARIO ELEGIDO TENGA AL MENOS UNA FOTO PARA PODER SER MOSTRADA... " << RESTORE << endl;
			}			
			else{
				us2->PrintUsuario();
				}
		}
		else{
			cout << RED << "USUARIO NO VALIDO PARA MOSTRAR FOTOS, VOLVIENDO AL MENU PRINCIPAL..." << RESTORE << endl;
		}
	}
}
int TablaUsuarios::BusquedaLogin(string login){

	int pos_busq = -1;
	for (int i = 0; i < this->getTotalUsuarios(); i++){
		if((this->punteroapuntero[i])->getLogin() == login){
			pos_busq = i;
		}
	}
	return pos_busq;
}

void TablaUsuarios::BusquedayMuestraUsuarioPorLogin(){
string login;
int posicion = 0;
	cout << PURPLE "Introduce el login del usuario el cual quieres buscar..." << RESTORE << endl;
	cin >> login;
	posicion = this->BusquedaLogin(login);
	if (posicion == -1){
		cout << RED << "EL LOGIN INTRODUCIDO NO CORRESPONDE CON NINGUN USUARIO, NO SE MOSTRARÁ NINGÚN USUARIO, VOLVIENDO AL MENÚ PRINCIPAL..." << RESTORE << endl;
	}
	else{
		this->punteroapuntero[posicion]->PrintUsuario();
	}
}

void TablaUsuarios::FuncionalidadInsertarUsuario(){

	if (this->getTotalUsuarios() == 0){
		cout << RED << "DEBES DE CREAR ANTES UNA TABLA" << endl;
	}
	else{
		Admin* admin = new Admin();
		Normal* normal = new Normal();
		char a;
		cout << BLUE << "Elige que tipo de Usuario quieres crear" << RESTORE << endl;
		cout << BLUE << "Para Usuario Normal pulsa [n], para Usuario Administrados pulsa [a]" << RESTORE << endl;
		cin >> a;
		
		switch (a) {
	
			case 'n' :
					normal->RellenarUsuario();
					this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
					insertarUsuarioenTabla (normal, getTotalUsuarios() - 1);
				break;
	
			case 'a' :
					admin->RellenarUsuario();
					this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
					insertarUsuarioenTabla (admin, getTotalUsuarios() - 1);
				break;
		
			default :
			cout << RED << "Has pulsado una tecla que no es valida, volviendo al menu principal..." << RESTORE << endl;
		}
	}
}
void TablaUsuarios::PrintTabla(){

	if (getTotalUsuarios() == 0){
		cout << RED << "LA TABLA NO EXISTE O HA SIDO BORRADA, POR FAVOR CREE UNA NUEVA TABLA" << RESTORE << endl;
	}
	else{
		//cout << RED << "DEBUG: " << "Entra en el printTabla" << RESTORE << endl;
		for (int i = 0; i < getTotalUsuarios(); i++){
			this->punteroapuntero[i]->PrintUsuario();
		}
	}
}
