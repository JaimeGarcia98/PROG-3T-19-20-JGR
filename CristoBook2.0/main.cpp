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
	public:
	Vista();
	~Vista();
	void menu();
	void testing();
};

Vista::Vista(){

	t = new TablaUsuarios;
	if (t == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
	
}
Vista::~Vista(){

	delete [] t;
	t = 0;
}

void Vista::menu(){
	bool interactua = true;
	while (interactua == true){
	char a;
	cout << BLUE << "BIENVENIDO A CRISTOBOOK " << RESTORE << endl;
	cout << BLUE << "1.Crear tabla Usuarios[c]" << RESTORE << endl;
	cout << BLUE << "2.Eliminar tabla Usuarios[d]" << RESTORE << endl;
	cout << BLUE <<	"3.Imprimir tabla Usuarios [p]" << RESTORE << endl;
	cout << BLUE << "4.Insertar Usuario en tabla Usuarios [i]" << RESTORE << endl;
	cout << BLUE << "5.Eliminar Usuario en tabla Usuarios [x]" << RESTORE << endl;
	cout << BLUE << "6.Buscar Usuario por Atributo Login en tabla Usuarios (utilizar la búsqueda secuencial)[s]" << RESTORE << endl;
	cout << BLUE << "7.Ordenar tabla Usuarios por Atributo totalFotosUsuario y por atributo login [o]" << RESTORE << endl;
	cout << BLUE << "8.Añadir Fotografía a Usuario. [a]" << RESTORE << endl;
	cout << BLUE << "9.Eliminar Fotografía de un Usuario. [w]" << RESTORE << endl;
	cout << BLUE << "10.Imprimir las Fotografías de un Usuario. [b]" << RESTORE << endl;
	cout << BLUE << "11.Buscar coincidencias de fotos. [f]" << RESTORE << endl;
	cout << BLUE << "12.Eliminar usuarios por numero de fotos. [y]" << RESTORE << endl;
	cout << BLUE << "13.Eliminar usuarios por numero de fotos. [z]" << RESTORE << endl;
	cout << BLUE << "14.Salir [e]" << RESTORE << endl;

	cin >> a;
	while (!cin){//Condicion para filtrar las letras
		cout << "No metas numeros, intentalo de nuevo" << endl;
		Filtro();
		cin >> a;
	}

	switch (a) {

		case 'c' :
			
			break;
		case 'd' :
			
			break;
		case 'p' :
			
			break;
		case 'i' :
			
			break;
		case 'x' :
			
			break;
		case 's' :
			
			break;
		case 'o' :
			
			break;
		case 'a' :
			
			break;
		case 'w' :
			
			break;
		case 'b' :
			
			break;
		case 'f' :
			
			break;
		case 'y' :

			break;
		case 'z' :
			
			break;
		case 'e' :

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
