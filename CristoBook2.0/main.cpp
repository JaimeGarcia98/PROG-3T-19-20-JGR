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
class Vista {
	private:
	TablaUsuarios* t;
	bool debug;
	public:
	Vista();
	~Vista();
	void setDebug(bool debug);
	bool getdebug();
	/**
	* @brief Filtro para limpiar el buffer y que no se cuelgue
	* @pre Ninguna 
	* @param Ninguno
	* @return No devuelve nada es una funcion tipo void (procedimiento)
	* @post Ninguna
	*/
	void Filtro();
	/**
	* @brief 
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void MenuDebug();
	/**
	* @brief 
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void FuncionalidadEliminarUsuario();
	/**
	* @brief Modulo que pide al usuario una de las 2 opciones de ordenar la tabla, primero esta la opcion de ordenar alfabeticamentee por login y despues esta la opcion de ordenar de 			mayor a menor por el numero de fotos
	* @pre La tabla debe de contener al menos 2 usuarios para poder ver el funcionamiento de este modulo
	* @post La tabla debe de quedar ordenada segun lo especificado por el usuario
	*/
	void OrdenarTabla();
	/**
	* @brief 
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void FuncionalidadBuscarUsuario();
	/**
	* @brief 
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void FuncionalidadAnadirFoto();
	/**
	* @brief 
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void FuncionalidadEliminarFotoUsuario();
	/**
	* @brief 
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void FuncionalidadInsertarUsuarioC();
	void MostrarFotosUsuario();
	/**
	* @brief 
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void FunionalidadEliminarUsuariosMinFotos();
	void menu();
	void testing();
};

Vista::Vista(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: CREANDO TABLA DE USUARIOS... " << RESTORE << endl;
	}
	t = new TablaUsuarios;
	if (t == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
	
}
Vista::~Vista(){
	if(this->getdebug() == true){
		cout << RED << "ELIMINANDO VISTA... " RESTORE << endl;
	}
	delete [] t;
	t = 0;
}

void Vista::setDebug(bool debug){
	this->debug = debug;
	this->t->setDebug(debug);
}

bool Vista::getdebug(){
	return this->debug;
}

void Vista::Filtro(){
	cin.clear();
	cin.ignore(256, '\n');
}

void Vista::MenuDebug(){
int num;
bool opc;
	cout << BLUE << "Para activar debug pulsa [1], para desactivarlo pulsa [2] " << RESTORE << endl;
	cin >> num;
	while(!cin){
		cout << RED << "NO INTRODUZCAS LETRAS, POR FAVOR VUELVE A INTENTARLO..." << RESTORE << endl;
		Filtro();
		cin >> num;
	}
	switch (num) {
	
		case 1 :
			opc = true;
			this->setDebug(opc);
		break;
				
		case 2 :
			opc = false;
			this->setDebug(opc);
		break;
		default :
			cout << RED << "Has pulsado una tecla que no es valida, volviendo al menu principal..." << RESTORE << endl;
		}
}

void Vista::FuncionalidadInsertarUsuarioC(){
int a;
	cout << BLUE << "Elige que tipo de Usuario quieres crear" << RESTORE << endl;
	cout << BLUE << "Para Usuario Normal pulsa [1], para Usuario Administrados pulsa [2]" << RESTORE << endl;
	cin >> a;
	while(!cin){
		cout << RED << "No introduzcas letras, intentalo de nuevo" << RESTORE << endl;	
		Filtro();
		cin >> a;
	}
	this->t->FuncionalidadInsertarUsuario(a);
}

void Vista::FuncionalidadEliminarUsuario(){
string login;
	cout << PURPLE "Introduce el login del usuario el cual quieres eliminar..." << RESTORE << endl;
	cin >> login;
	this->t->EliminarUsuario(login);
}

void Vista::FuncionalidadBuscarUsuario(){
string login;
	cout << PURPLE "Introduce el login del usuario el cual quieres buscar..." << RESTORE << endl;
	cin >> login;
	this->t->BusquedayMuestraUsuarioPorLogin(login);
}

void Vista::OrdenarTabla(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: ENTRANDO EN ORDENAR TABLA " << RESTORE << endl;
	}
	int a;
	cout << BLUE << "Elige como quieres ordenar la tabla, 1.Por login | 2.Total de fotos " << RESTORE << endl;
	cin >> a;
	while(!cin){
		cout << RED << "NO INTRODUZCAS LETRAS, POR FAVOR VUELVE A INTENTARLO..." << RESTORE << endl;
		Filtro();
		cin >> a;
	}

		switch (a) {

		case 1 :
			this->t->OrdenarPorLogin ();
			break;
		case 2 :
			this->t->OrdenarPorTotalFotos();
			break;
		default :
			cout << RED << "Has pulsado una tecla que no es valida, vuelve a intentarlo haciendole caso al enunciado por favor ;)" << RESTORE << endl;
		}
	if(this->getdebug() == true){
		cout << RED << "DEBUG: TABLA ORDENADA " << RESTORE << endl;
	}
}

void Vista::FuncionalidadAnadirFoto(){
Foto f;
string login;
string ruta;
string extension;
int tamanio = 0;
	cout << PURPLE "Introduce el login del usuario en el cual quieres introducir una foto..." << RESTORE << endl;
	cin >> login;
	cout << GREEN << "A continuacion vamos a rellenar la foto que desea introducir... " << RESTORE << endl;
	cout << PURPLE << "INTRODUCE LA RUTA DE LA FOTO SIN EXTENSION (EJ: ..Desktop/Images/Image1 ) " << RESTORE << endl;
	cin >> ruta;
	f.setRuta(ruta); 
	cout << PURPLE << "INTRODUCE LA EXTENSION DE LA FOTO (EJ: jpg, png... ) " << RESTORE << endl;
	cin >> extension;
	f.setTipo(extension);
	cout << PURPLE << "INTRODUCE EL TAMAÑO DE LA FOT EN BYTES (EJ: 32, 22331... ) " << RESTORE << endl;
	cin >> tamanio;
	while(!cin){
		cout << RED << "No introduzcas letras, intentalo de nuevo" << RESTORE << endl;	
		Filtro();
		cin >> tamanio;
	}
	f.setTamanio(tamanio);
	
	this->t->AnadirFotoUsuario(login, f);
}

void Vista::FuncionalidadEliminarFotoUsuario(){
string login;
int elim = 0;
	cout << PURPLE << "Introduce el login del usuario en el cual quieres eliminar una foto..." << RESTORE << endl;
	cin >> login;
	cout << PURPLE << "A continuacion introduce el numero de la foto la cual quieres eliminar " << RESTORE << endl;
	cin >> elim;
	this->t->EliminarFoto(login, elim);
}

void Vista::MostrarFotosUsuario(){
string login;
	cout << PURPLE "Introduce el login del usuario el cual quieres imprimir sus fotos..." << RESTORE << endl;
	cin >> login;
	this->t->ImprimirFotosUsuario(login);
}

void Vista::FunionalidadEliminarUsuariosMinFotos(){
int fotos_min;
	cout << BLUE << "Introduce el numero minimo de fotos" << RESTORE << endl;
	cin >> fotos_min; 
	while(!cin){
		cout << RED << "No introduzcas letras, vuelve a intentarlo" << RESTORE << endl;
		Filtro();
		cin >> fotos_min;
	}
	this->t->EliminarUsuariosPorMinFotos(fotos_min);
}

void Vista::menu(){
	bool interactua = true;
	while (interactua == true){
	int a;
	cout << BLUE << "BIENVENIDO A CRISTOBOOK " << RESTORE << endl;
	cout << BLUE << "1.Activar/Desactivar modo debug." << RESTORE << endl;
	cout << BLUE << "2.Ejecutar testing automatico." << RESTORE << endl;
	cout << BLUE << "3.Crear tabla Usuarios." << RESTORE << endl;
	cout << BLUE << "4.Eliminar tabla Usuarios." << RESTORE << endl;
	cout << BLUE <<	"5.Imprimir tabla Usuarios." << RESTORE << endl;
	cout << BLUE << "6.Insertar Usuario en tabla Usuarios." << RESTORE << endl;
	cout << BLUE << "7.Eliminar Usuario en tabla Usuarios." << RESTORE << endl;
	cout << BLUE << "8.Buscar Usuario por Atributo Login en tabla Usuarios (utilizar la búsqueda secuencial)." << RESTORE << endl;
	cout << BLUE << "9.Ordenar tabla Usuarios por Atributo totalFotosUsuario y por atributo login." << RESTORE << endl;
	cout << BLUE << "10.Añadir Fotografía a Usuario." << RESTORE << endl;
	cout << BLUE << "11.Eliminar Fotografía de un Usuario." << RESTORE << endl;
	cout << BLUE << "12.Imprimir las Fotografías de un Usuario." << RESTORE << endl;
	cout << BLUE << "15.Eliminar todos los usuarios cuyo numero de fotos es inferior a fotos_min." << RESTORE << endl;
	cout << BLUE << "13.Salir." << RESTORE << endl;

	cin >> a;
	while(!cin){
		cout << RED << "NO INTRODUZCAS LETRAS, POR FAVOR VUELVE A INTENTARLO..." << RESTORE << endl;
		Filtro();
		cin >> a;
	}

	switch (a) {

		case 1 :
			this->MenuDebug();
			break;
		case 2 :
			this->t->Testing();
			break;
		case 3 :
			if(t->getTotalUsuarios() > 0){
				cout << RED << "YA HAY UNA TABLA CREADA " << RESTORE << endl;
			}
			else{
				this->t->TablaPorDefecto();
			}
			break;
		case 4 :
			this->t->EliminarTabla();
			break;
		case 5 :
			this->t->PrintTabla();
			break;
		case 6 :
			this->FuncionalidadInsertarUsuarioC();
			break;
		case 7 :
			this->FuncionalidadEliminarUsuario();
			break;
		case 8 :
			this->FuncionalidadBuscarUsuario();
			break;
		case 9 :
			this->OrdenarTabla();
			break;
		case 10 :
			this->FuncionalidadAnadirFoto();
			break;
		case 11:
			this->FuncionalidadEliminarFotoUsuario();
			break;
		case 12 :
			this->MostrarFotosUsuario();
			break;
		case 15 :
			this->FunionalidadEliminarUsuariosMinFotos();
			break;
		case 13 :
				if (this->t->getTotalUsuarios() > 0){
					this->t->EliminarTabla();
					this->t = 0;
				}
				else{
				this->t = 0;
				}
				cout << RED << "ADIOS MUCHACHO" << RESTORE << endl;
				interactua = false;// En este momento se sale del menu
			break;

		default :
			cout << RED << "Has pulsado una tecla que no es valida, vuelve a intentarlo haciendole caso al enunciado por favor ;)" << RESTORE << endl;
		}
	}
}

int main (){
Vista Mivista;

Mivista.menu();

/************** PRUEBA DE SOBRECARGA DE OPERADORES DE FOTO *************/
/*
Foto f;
Foto f2;
	cin >> f;
	cout << f;
	f2 = f;
	cout << f2;
*/

/************** PRUEBA DE SOBRECARGA DE OPERADORES DE USUARIO *************/
/*
cout << RED << "USUARIO ADMIN" << RESTORE << endl;
Admin *a = new Admin();
cin >> a;
cout << a;
cout << RED << "USUARIO NORMAL" << RESTORE << endl;
Normal *u = new Normal();
cin >> u;
cout << u;
*/
}
