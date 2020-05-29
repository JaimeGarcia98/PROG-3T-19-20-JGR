#include <iostream>
#include "Usuario.h"
using namespace std;
/*****************************************
** Definición del OBJETO TablaUsuarios  **
******************************************/

class TablaUsuarios {
	private:
	Usuario** punteroapuntero;
	int totalusuarios;
	
	/******** SETS ********/

	/**
	* @brief Módulo que introduce un valor al miembro totaltuplas de una variable de tipo TablaUsuarios
	* @param TablaUsuarios tabla Una variable de tipo TablaUsuarios por referencia (E/S)
	* @param int totalTuplas Variable de tipo int que se corresponde al total de tuplas de una variable de tipo TablaUsuarios, se pasa por copia porque solo la vamos a utilizar de lectura
	* @post El valor del miembro segundo de la variable tipo TablaUsuarios, será modificado.
	*/
	void setTotalUsuarios(int totalusuarios);

	public:
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	TablaUsuarios(); //Constructor por defecto
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	~TablaUsuarios(); //Destructor
	
	/******** GETS ********/
	
	/**
 	* @brief Modulo que devuelve el valor del miembro totaltuplas de la variable de tipo TablaUsuarios
 	* @return Devuelve el valor de la variable tabla->totaltuplas que es un valor de tipo int
	*/
	int getTotalUsuarios();
	/**
	* @brief Modulo de redimension para el vector de punteros, este modulo aumentará en 1 la dimensión del vector de punteros, al tener este vector la dimension justa, no es necesario el 		empleo de utiles ya que en su defecto siempre estará lleno por completo.(!Apunte: Realizo las modificaciones en un vector auxiliar para mayor seguridad)
	* @pre El vector de punteros debe de estar creado previamente
	* @return Devuelve un vector de punteros, el cual tendrá una dimensión 1 unidad más grande
	* @post El vector de punteros que es devuelto, debe de tener como máximo una variación de 1 unidad de tamaño respecto a la de la entrada original, siendo más grande
	*/
	void resizeTablaUsuariosCrecer (int dim_nueva);
	/**
	* @brief Modulo de redimension para el vector de punteros, este modulo disminuirá en 1 unidad la dimensión del vector de punteros, al tener este vector la dimension justa, no es 			necesario el empleo de utiles ya que en su defecto siempre estará lleno por completo.(!Apunte: Realizo las modificaciones en un vector auxiliar para mayor seguridad)
	* @pre El vector de punteros debe de estar creado previamente
	* @return Devuelve un vector de punteros, el cual tendrá una dimensión 1 unidad más pequeña que la original
	* @post El vector de punteros que es devuelto, debe de tener como máximo una variación de 1 unidad de tamaño respecto a la de la entrada original, siendo más pequeño 
	*/
	void resizeTablaUsuariosDisminuir (int dim_nueva, int posicion);
	/**
	* @brief Modulo que "Inserta" un usuario en la tabla de usuarios. El funcionamiento es que el vector que se encuente en "pos" apunte al usuario requerido.
	* @pre El usuario debe de contener todos los datos rellenos previamente para ser introducido en la tabla
	* @post El usuario debe de quedar apuntado por el vector que se encuentre en "pos" para posteriormente poder acceder a sus datos.
	*/
	void insertarUsuarioenTabla (Usuario *u, int pos);
	/**
	* @brief Modulo que crea e inserta en una Tabla de usuarios 5 usuarios por defecto.
	* @pre La tabla debe de estar previamente creada y el vector de punteros(punteroapuntero) debe de estar creado y con una dimensión dinámica
	* @param (TablaUsuarios) *tabla Variable
	* @post En el vector de punteros(punteroapuntero) los punteros deben de apuntar al Usuario que corresponda y tener una dimensión total máxima igual al numero de Usuarios(teniendo en 		cuenta que empieza en 0)
	*/
	void TablaPorDefecto();
	/**
	* @brief Modulo que hace la funcionalidad de insertar un usuario en la tabla de usuarios
	* @pre Debe de existir una tabla cread, de lo contrario saltará un mensaje de error
	* @post El usuario debe de quedar introducido en la tabla de usuarios
	*/
	void FuncionalidadInsertarUsuario();
	/**
	* @brief Modulo que primeramente pide al usuario un login, comprueba si esta en la tabla de usuarios, en caso de que se encuentre se le vuelven a pedir datos para rellenar los 		miembros de una Foto que una vez introducidos se asingnan al vector de fotos del usuario buscado mediante el login. En caso de no encontrar al usuario, se mostrará un mensaje por 		pantalla diciendo que no se ha encontrado ningun usuario que coincida con el login buscado y se volverá al menu principal
	* @pre Previamente debe de haber una tabla con usuarios en su interior creada, y en el usuario en concreto a buscar debe de haber suficiente hueco en el vector de fotos(se 			redimensionará en caso de que se necesite)
	* @post La foto introducida por el usuario debe de guardarse dentro del vector de fotos del usuario mostrado, si hay una redimension en el vector de fotos el miembro dim_vfotos debe 		de ser modificado y el miembro totalfotos tambien debe de ser modificado en 1 unidad más una vez acabe este modulo.
	*/
	void AnadirFotoUsuario();
	/**
	* @brief Modulo que imprime las fotos de un usuario en concreto buscado por el login.
	* @pre El usuario elegido debe de tener al menos una foto, de lo contrario se mostrará un mensaje de error
	* @post Se deben de mostrar por pantalla las fotos del usuario elegido en caso de que tenga, en caso contrario se mostrara un mensaje de error
	*/
	void ImprimirFotosUsuario();
	/**
	* @brief Modulo que compara las cadenas de caracteres que contienen los logins de los usuarios de la tabla de usuarios, para determinar la posicion en la cual se encuentra el usuario 		cuyo login coincide con la cadena que buscamos
	* @pre Todos los usuarios deben de tener un login obligatoriamente distinto y debe de ser obligatorio tener el login registrado
	* @return Devuelve una variable de tipo int la cual contiene la posicion del puntero en el vector de punteros el cual apunta al usuario cuyo login coincide con el buscado
	* @post La variable pos_busq debe de ser como minimo 0 y como maximo el numero total de tuplas - 1.
	*/
	int BusquedaLogin(string login);
	/**
	* @brief Modulo que pide al usuario que introduzca un login para buscar un usuario de la tabla cuyo login coincida con el introducido por el usuario. Despues de introducir el login, 		se llama al modulo BusquedaLogin el cual mediante una busqueda secuencial devuelve la posicion del puntero que apunta a dicho usuario del vector de punteros de tabla. Una vez con la 		posicion encontrada, se muestra por pantalla los datos de dicho usuario. En caso de que no se encuentre se mostrará un mensaje por pantalla el cual se le dice al usuario que no se ha 		encontrado ninguna coincidencia con el login introducido y vuelve al menú principal del programa
	* @pre Debe de ehaber una tabla creada con al menos un usuario dentro.
	* @post Se debe de mostrar por pantalla los datos del usuario cuyo login coincide con el que se introdujo, en caso de no encontrarlo, se mostrará un mensaje por pantalla indicando 	que no se encontró ningun usuario cuyo login coincida con el introducido y se volvera al menu principal del programa.
	*/
	void BusquedayMuestraUsuarioPorLogin();
	/**
	* @brief Modulo que imprime el vector de punteros de la tabla con todas las componentes de sus respectivos usuarios, imprimiendo por pantalla de manera obligatoria el login mas el 		usuario y dando de manera optativa al usuario imprimir 
	* @pre El vector de punteros de la tabla debe de estar apuntando a 1 usuario como mínimo.
	* @post Se debe de imprimir por pantalla primeramente tanto el login como el nombre del usuario y luego se debe de mostrar un "submenú" con el cual se le da al usuario la opción de 			imprimir más datos de los usuarios
	*/
	
	void PrintTabla();
	
};
