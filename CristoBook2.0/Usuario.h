#include <iostream>
#include "Foto.h"
using namespace std;
/***********************************
** Definición del OBJETO Usuario  **
************************************/
class Usuario {
	protected:
	string login;
	string nombre;
	string apellido;
	string perfil_usuario;

	public:
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	Usuario(); //Constructor por defecto
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	virtual ~Usuario(); //Destructor

	/******** SETS ********/

	/**
 	* @brief Módulo que introduce un valor a un login de una variable de tipo Usuario
 	* @param string login Cadena de caracteres que hace referencia al login de un usuario, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro primero de la variable tipo Usuario, será modificado.
 	*/
	void setLogin(string login);
	/**
 	* @brief Módulo que introduce un valor a un nombre de una variable de tipo Usuario
 	* @param string nombre Cadena de caracteres que hace referencia al nombre de un usuario, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro segundo de la variable tipo Usuario, será modificado.
 	*/
	void setNombre(string nombre);
	/**
 	* @brief Módulo que introduce un valor a un apellido de una variable de tipo Usuario
 	* @param string apellido Cadena de caracteres que hace referencia al apellido de un usuario, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro tercero de la variable tipo Usuario, será modificado.
 	*/
	void setApellido(string apellido);
	/**
 	* @brief Módulo que introduce un valor a un perfil de usuario de una variable de tipo Usuario
 	* @param string perfil_usuario Cadena de caracteres que hace referencia al perfil de un usuario, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro cuarto de la variable tipo Usuario, será modificado.
 	*/
	void setPerfil_usuario(string perfil_usuario);


	/******** GETS ********/

	/**
 	* @brief Modulo que devuelve el valor del miembro login de la variable de tipo Usuario
 	* @return Devuelve el valor de la variable u->login que es un valor de tipo string
	*/
	string getLogin();

	/**
 	* @brief Modulo que devuelve el valor del miembro nombre de la variable de tipo Usuario
 	* @return Devuelve el valor de la variable u->nombre que es un valor de tipo string
	*/
	string getNombre();

	/**
 	* @brief Modulo que devuelve el valor del miembro apellido de la variable de tipo Usuario
 	* @return Devuelve el valor de la variable u->apellido que es un valor de tipo string
	*/
	string getApellido();
	/**
 	* @brief Modulo que devuelve el valor del miembro perfil_usuario de la variable de tipo Usuario
 	* @return Devuelve el valor de la variable u->perfil_usuario que es un valor de tipo string
	*/
	string getPerfil_usuario();
	/**
	* @brief Modulo en el cual vamos a borrar el contenido de una direccion de memoria dinamica la cual apunta a una variable de tipo Usuario
	* @post Cuando este modulo finalice tanto el puntero como su contenido debe de estar a NULL
	*/
	void borrarUsuario(Usuario *u);
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	virtual void PrintUsuario(Usuario *u);

};

class Admin : public Usuario {
	private:
	int total_consultas;
	public:
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	Admin(); //Constructor por defecto
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	~Admin(); //Destructor
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void getTotalconsultas();
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void BuscarFotografias(string cadena);

	
};

class Normal : public Usuario {
	protected:
	Foto* v_fotos;
	int totalFotosUsuario;
	double saldo;
	int dim_fotos;
	public:
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	Normal(); //Constructor por defecto
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	~Normal(); //Destructor
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void PrintFotosUsuarioNormal();
	/**
 	* @brief Módulo que introduce un valor que corresponde a las utiles del vector de fotos de una variable de tipo Usuario
 	* @param Usuario u Una variable de tipo Usuario por referencia (E/S)
 	* @param int totalfotos Variable de tipo int que se corresponde a las utiles del vector de fotos de un usuario, se pasa por copia porque solo la vamos a utilizar de lectura
 	* @post El valor del miembro septimo de la variable tipo Usuario, será modificado.
 	*/
	void setTotalFotosUsuario(int totalfotos);


};
