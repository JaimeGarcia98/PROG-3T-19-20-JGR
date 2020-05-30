#include <iostream>
#include <string>
using namespace std;
/***********************************
** Definición del OBJETO Usuario  **
************************************/
class Foto {
	private:
	string ruta;
	string tipo;
	unsigned long int tamanio;
	bool debug;
	public:
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	Foto(); //Constructor por defecto
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	~Foto(); //Destructor


	/******** SETS ********/

	/**
 	* @brief Módulo que introduce un valor a una ruta a una variable de tipo Foto
 	* @param string ruta Cadena de caracteres que hace referencia a la ruta de una imagen, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro primero de la variable tipo Foto, será modificado.
 	*/
	void setRuta(string ruta);
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void setDebug(bool debug);
	/**
 	* @brief Módulo que introduce un valor a un tipo de una variable de tipo Foto
 	* @param string tipo Cadena de caracteres que hace referencia al tipo de una imagen, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro segundo de la variable tipo Foto, será modificado.
 	*/
	void setTipo(string tipo);
	/**
 	* @brief Módulo que introduce un valor al tamanio de una variable de tipo Foto
 	* @param int tamanio Tamaño en bytes de la foto a la cual se hace referencia, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro tercero de la variable tipo Foto, será modificado.
 	*/
	void setTamanio(int tamanio);

	/******** GETS ********/
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	bool getdebug();
	/**
 	* @brief Modulo que devuelve el valor del miembro ruta de la variable de tipo Foto
 	* @return Devuelve el valor de la variable f->ruta que es un valor de tipo string
	*/
	string getRuta();
	/**
 	* @brief Modulo que devuelve el valor del miembro tipo de la variable de tipo Foto
 	* @return Devuelve el valor de la variable f->tipo que es un valor de tipo string
	*/
	string getTipo();
	/**
 	* @brief Modulo que devuelve el valor del miembro tamanio de la variable de tipo Foto
 	* @return Devuelve el valor de la variable f->tamanio que es un valor de tipo int
	*/
	unsigned long int getTamanio();

	/******** MODULOS DE UTILIDAD ********/

	/**
	* @brief Modulo el cual imprime por pantalla una foto
	* @post Este modulo debe de mostrar por pantalla la ruta el tipo y el peso en bytes de la foto
	*/
	void PrintFoto();
	/**
	* @brief Modulo en el cual vamos a borrar el contenido de  una variable de tipo Foto
	* @post Cuando este modulo finalice el contenido de una variable de tipo Foto debe de estar a reseteado.
	*/
	void borrarFoto();

};
