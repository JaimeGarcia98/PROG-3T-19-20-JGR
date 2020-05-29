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
	* @brief Modulo el cual pide al usuario los datos necesarios para rellenar un usuario en el programa de CRISTOBOOK	
	* @pre Para crear el usuario, el login debe de ser unico, por lo tanto en caso de repetirse se pedira al usuario que introduzca de nuevo el login
	* @return Devuelve una variable u que contiene el usuario relleno  por el usuario
	* @post Debe de quedar un usuario del programa CRISTOBOOK relleno completamente por el usuario
	*/
	virtual void RellenarUsuario();
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	virtual void PrintUsuario();

};

class Admin : public Usuario {
	protected:
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
	int getTotalconsultas();
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void setTotalConsultas(int total);
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	void BuscarFotografias(string cadena);

	void RellenarUsuario();

	void PrintUsuario();

	
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
	/**
	* @brief
	* @pre 
	* @param () 
	* @return 
	* @post 
	*/
	int getTotalFotosUsuario();

	void setDimFotos(int dim);

	int getDimFotos();

	void InsertarFotoEnUsuario(Foto f);
	/**
	* @brief Modulo de redimension para el vector de fotos, este modulo aumentará en 1 la dimensión del vector de fotos(!Apunte: Realizo las modificaciones en un vector auxiliar para 		mayor seguridad)
	* @pre El vector de fotos debe de estar creado previamente
	* @return Devuelve un vector de fotos, el cual tendrá una dimensión 1 unidad más grande
	* @post El vector de fotos que es devuelto, debe de tener como máximo una variación de 1 unidad de tamaño respecto a la de la entrada original, siendo más grande
	*/
	void ResizeAumentarVectorFotos(int dim_nueva);

	void RellenarUsuario();

	void PrintUsuario();
	
};
