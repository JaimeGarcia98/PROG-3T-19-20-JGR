#include <iostream>
#include "Usuario.h"
using namespace std;
/*****************************************
** Definición del OBJETO TablaUsuarios  **
******************************************/

class TablaUsuarios {
	private:
	Usuario** punteroapuntero;
	int totalusuarios
	
	/******** SETS ********/

	/**
	* @brief Módulo que introduce un valor al miembro totaltuplas de una variable de tipo TablaUsuarios
	* @param TablaUsuarios tabla Una variable de tipo TablaUsuarios por referencia (E/S)
	* @param int totalTuplas Variable de tipo int que se corresponde al total de tuplas de una variable de tipo TablaUsuarios, se pasa por copia porque solo la vamos a utilizar de lectura
	* @post El valor del miembro segundo de la variable tipo TablaUsuarios, será modificado.
	*/
	void setTotaltuplas(int totalTuplas);

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
	int getTotaltuplas();
	/**
	* @brief Modulo que "Inserta" un usuario en la tabla de usuarios. El funcionamiento es que el vector que se encuente en "pos" apunte al usuario requerido.
	* @pre El usuario debe de contener todos los datos rellenos previamente para ser introducido en la tabla
	* @post El usuario debe de quedar apuntado por el vector que se encuentre en "pos" para posteriormente poder acceder a sus datos.
	*/
	void insertarUsuarioenTabla (Usuario *u, int pos);
	/**
	* @brief Modulo que imprime el vector de punteros de la tabla con todas las componentes de sus respectivos usuarios, imprimiendo por pantalla de manera obligatoria el login mas el 		usuario y dando de manera optativa al usuario imprimir 
	* @pre El vector de punteros de la tabla debe de estar apuntando a 1 usuario como mínimo.
	* @post Se debe de imprimir por pantalla primeramente tanto el login como el nombre del usuario y luego se debe de mostrar un "submenú" con el cual se le da al usuario la opción de 			imprimir más datos de los usuarios
	*/
	void PrintTabla();
	
};
