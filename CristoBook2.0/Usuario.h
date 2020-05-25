#include <iostream>
#include "Foto.h"
using namespace std;
/***********************************
** Definición del OBJETO Usuario  **
************************************/
class Usuario {
	private:
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
	~Usuario(); //Destructor
};

class Admin {
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

class Normal {
	private:
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
};
