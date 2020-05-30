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
void Filtro(){
/**
* @brief Filtro para limpiar el buffer y que no se cuelgue
* @pre Ninguna 
* @param Ninguno
* @return No devuelve nada es una funcion tipo void (procedimiento)
* @post Ninguna
*/
	cin.clear();
	cin.ignore(256, '\n');
}
class Vista {
	private:
	TablaUsuarios* t;
	bool debug;
	public:
	Vista();
	~Vista();
	void setDebug(bool debug);
	bool getdebug();
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
void Vista::menu(){
	bool interactua = true;
	while (interactua == true){
	int a;
	int num;
	bool opc;
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
	cout << BLUE << "13.Salir." << RESTORE << endl;

	cin >> a;
	while(!cin){
		cout << RED << "NO INTRODUZCAS LETRAS, POR FAVOR VUELVE A INTENTARLO..." << RESTORE << endl;
		Filtro();
		cin >> a;
	}

	switch (a) {

		case 1 :
			cout << BLUE << "Para activar debug pulsa [1], para desactivarlo pulsa [2] " << RESTORE << endl;
			cin >> num;
			while(!cin){
				cout << RED << "NO INTRODUZCAS LETRAS, POR FAVOR VUELVE A INTENTARLO..." << RESTORE << endl;
				Filtro();
				cin >> a;
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
			t->PrintTabla();
			break;
		case 6 :
			this->t->FuncionalidadInsertarUsuario();
			break;
		case 7 :
			this->t->EliminarUsuario();
			break;
		case 8 :
			this->t->BusquedayMuestraUsuarioPorLogin();
			break;
		case 9 :
			this->t->OrdenarTabla();
			break;
		case 10 :
			this->t->AnadirFotoUsuario();
			break;
		case 11:
			this->t->EliminarFoto();
			break;
		case 12 :
			this->t->ImprimirFotosUsuario();
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
}
