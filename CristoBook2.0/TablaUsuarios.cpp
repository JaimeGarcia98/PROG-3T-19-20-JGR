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

void TablaUsuarios::Filtro(){

	cin.clear();
	cin.ignore(256, '\n');
}
/*----- CONSTRUCTOR Y DESTRUCTOR -----*/

TablaUsuarios::TablaUsuarios(){
	if(this->getdebug() == true){
		cout << RED << "CREANDO TABLA DE USUARIOS... " RESTORE << endl;
	}
	int totalusuarios = 0;
	setTotalUsuarios(totalusuarios);
	this->punteroapuntero = new Usuario* [getTotalUsuarios()];
    if (this->punteroapuntero == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
}

TablaUsuarios::~TablaUsuarios(){
	if(this->getdebug() == true){
		cout << RED << "ELIMINANDO TABLA DE USUARIOS... " RESTORE << endl;
	}
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

void TablaUsuarios::setDebug(bool debug){
	this->debug = debug;
	for(int i = 0; i < this->getTotalUsuarios(); i++){
		this->punteroapuntero[i]->setDebug(debug);
	}
}
/*----- GETS -----*/
bool TablaUsuarios::getdebug(){
	return this->debug;
}
int TablaUsuarios::getTotalUsuarios(){

    return this->totalusuarios;
}

/************************
** MODULOS DE UTILIDAD **
*************************/

void TablaUsuarios::resizeTablaUsuariosCrecer (int dim_nueva){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: ENTRANDO EN RESIZE DE TABLAUSUARIOS +... " << RESTORE << endl;
	}
	Usuario** vector_ampliado;
	//1) Creo el vector de punteros nuevo con una dimensión 1 unidad mayor.
	vector_ampliado = new Usuario* [dim_nueva];
    	if (vector_ampliado == 0){
        	cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        	exit(-1);
    	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG: VECTOR AUXILIAR CREADO " << RESTORE << endl;
	}
	//2)Copio el vector antiguo en el vector nuevo
	for (int i = 0; i < this->getTotalUsuarios(); i++){
		vector_ampliado[i] = this->punteroapuntero[i];
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG: COPIA DEL VECTOR REALIZADA " << RESTORE << endl;
	}
	//3)Borro el vector antiguo
	delete [] this->punteroapuntero;
	this->punteroapuntero = 0;
	if(this->getdebug() == true){
		cout << RED << "DEBUG: VECTOR ANTIGUO ELIMINADO " << RESTORE << endl;
	}
	//4)Asigno al miembro punteroapuntero de la tabla el nuevo vector de punteros con 1 unidad más de tamaño
	this->punteroapuntero = vector_ampliado;
	this->setTotalUsuarios(dim_nueva);
	if(this->getdebug() == true){
		cout << RED << "DEBUG: REASIGNACION REALIZADA, ACABANDO EL RESIZE... " << RESTORE << endl;
	}
	
}
void TablaUsuarios::resizeTablaUsuariosDisminuir (int dim_nueva){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: ENTRANDO EN RESIZE DE TABLAUSUARIOS -... " << RESTORE << endl;
	}
	Usuario** vector_aux;
	//1) Creo el vector de punteros nuevo con la misma dimensión que la original.
	vector_aux = new Usuario* [this->getTotalUsuarios()];
    	if (vector_aux == 0){
        	cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        	exit(-1);
    	}
	//2)Copio el vector antiguo en el vector nuevo
	for (int i = 0; i < this->getTotalUsuarios(); i++){
		vector_aux[i] = this->punteroapuntero[i];
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG: COPIA DEL VECTOR REALIZADA " << RESTORE << endl;
	}
	//3)Borro el vector antiguo
	delete [] this->punteroapuntero;
	this->punteroapuntero = 0;
	if(this->getdebug() == true){
		cout << RED << "DEBUG: VECTOR ANTIGUO ELIMINADO " << RESTORE << endl;
	}
	//4)Asigno al miembro punteroapuntero de la tabla el nuevo vector de punteros con 1 unidad más de tamaño
	this->punteroapuntero = vector_aux;
	setTotalUsuarios(dim_nueva);
	if(this->getdebug() == true){
		cout << RED << "DEBUG: REASIGNACION REALIZADA, ACABANDO EL RESIZE... " << RESTORE << endl;
	}
}
void TablaUsuarios::insertarUsuarioenTabla (Usuario *u, int pos){

	this->punteroapuntero[pos] = u;
}

void TablaUsuarios::TablaPorDefecto(){

	if(this->getdebug() == true){
		cout << YELLOW << "CREANDO TABLA POR DEFECTO... " << RESTORE << endl;
	}
	Admin* Jaime = new Admin();
	Normal* Jose = new Normal();
	Admin* Juan = new Admin();
	Normal* Pepe = new Normal();
	Admin* Antonio = new Admin();
	Normal* Pablo = new Normal();
	Admin* Manuel = new Admin();
	Foto jose;
	Foto jose2;
	Foto pepe;
	Foto pepe1;
	Foto pepe2;
	Foto pablo;
	
/*-----------------------------------------------*/
	Jaime->setLogin("@Champi");
	Jaime->setNombre("Jaime");
	Jaime->setApellido("García");
	Jaime->setPerfil_usuario("Pogramador León");
	Jaime->setTotalConsultas(0);
	this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
	insertarUsuarioenTabla (Jaime, 0);//Inserto el usuario 0 en la tabla

/*-----------------------------------------------*/
	Jose->setLogin("@JoseHenrique");
	Jose->setNombre("Jose Henrique");
	Jose->setApellido("Ortis");
	Jose->setPerfil_usuario("Waterpolista de alto riesgo");
	jose.setRuta("../Escritorio/Imagenes/imagen1"); 
	jose.setTipo("png");
	jose.setTamanio(15);
	Jose->InsertarFotoEnUsuario(jose);
	Jose->setTotalFotosUsuario(1);
	jose2.setRuta("../Escritorio/Imagenes/imagen1"); 
	jose2.setTipo("png");
	jose2.setTamanio(15);
	Jose->InsertarFotoEnUsuario(jose2);
	Jose->setTotalFotosUsuario(2);
	this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
	insertarUsuarioenTabla (Jose, 1);//Inserto el usuario 1 en la tabla
	
/*-----------------------------------------------*/
	Juan->setLogin("@Juansiyo");
	Juan->setNombre("Juan");
	Juan->setApellido("López");
	Juan->setPerfil_usuario("Portador del COVID-19");
	Juan->setTotalConsultas(0);
	this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
	insertarUsuarioenTabla (Juan, 2);//Inserto el usuario 2 en la tabla

/*-----------------------------------------------*/
	Pepe->setLogin("@Pepiyo");
	Pepe->setNombre("Pepe");
	Pepe->setApellido("Heredia");
	Pepe->setPerfil_usuario("Pelador de cable profesional");
	pepe.setRuta("../Escritorio/cable1"); 
	pepe.setTipo("png");
	pepe.setTamanio(21);
	Pepe->InsertarFotoEnUsuario(pepe);
	Pepe->setTotalFotosUsuario(1);
	pepe1.setRuta("../Escritorio/cable2"); 
	pepe1.setTipo("png");
	pepe1.setTamanio(20);
	Pepe->InsertarFotoEnUsuario(pepe1);
	Pepe->setTotalFotosUsuario(2);
	pepe2.setRuta("../Escritorio/cable3"); 
	pepe2.setTipo("png");
	pepe2.setTamanio(19);
	Pepe->InsertarFotoEnUsuario(pepe2);
	Pepe->setTotalFotosUsuario(3);
	this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
	insertarUsuarioenTabla (Pepe, 3);//Inserto el usuario 3 en la tabla

/*-----------------------------------------------*/
	Antonio->setLogin("@Antoñin");
	Antonio->setNombre("Antonio");
	Antonio->setApellido("Hernández");
	Antonio->setPerfil_usuario("Jugador de parchís techado");
	Antonio->setTotalConsultas(0);	
	this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
	insertarUsuarioenTabla (Antonio, 4);//Inserto el usuario 4 en la tabla

/*-----------------------------------------------*/
	
	Pablo->setLogin("@Pablisho");
	Pablo->setNombre("Pablo");
	Pablo->setApellido("Fernández");
	Pablo->setPerfil_usuario("Humano");
	pablo.setRuta("../Escritorio/Pablo/Fotos/ViajeGrecia/img2"); 
	pablo.setTipo("png");
	pablo.setTamanio(42);
	Pablo->InsertarFotoEnUsuario(pablo);
	Pablo->setTotalFotosUsuario(1);
	this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
	insertarUsuarioenTabla (Pablo, 5);//Inserto el usuario 5 en la tabla
	
/*-----------------------------------------------*/
	
	Manuel->setLogin("@Maolillo");
	Manuel->setNombre("Manuel");
	Manuel->setApellido("Agudo");
	Manuel->setPerfil_usuario("Apicultor");
	Manuel->setTotalConsultas(0);
	this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
	insertarUsuarioenTabla (Manuel, 6);//Inserto el usuario 6 en la tabla

	if(this->getdebug() == true){
		cout << YELLOW << "TABLA POR DEFECTO CREADA" << RESTORE << endl;
	}
}
void TablaUsuarios::AnadirFotoUsuario(){
Foto f;
string login;
string ruta;
string extension;
int tamanio = 0;
int posicion = 0;
	if(this->getdebug() == true){
		cout << RED << "DEBUG: ENTRANDO EN AÑADIR FOTO A USUARIO " << RESTORE << endl;
	}
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
			while(!cin){
				cout << RED << "No introduzcas letras, intentalo de nuevo" << RESTORE << endl;	
				Filtro();
				cin >> tamanio;
			}
			f.setTamanio(tamanio);
			cout << us2->getTotalFotosUsuario() << endl;
			cout << us2->getDimFotos() << endl;
			if(us2->getTotalFotosUsuario() >= us2->getDimFotos()){
				us2->ResizeAumentarVectorFotos(us2->getTotalFotosUsuario() + 1);
					if(this->getdebug() == true){
						cout << RED << "DEBUG: INTRODUCIENDO FOTO EN EL VECTOR DINAMICO DE FOTOS DE UN USUARIO... " << RESTORE << endl;
					}
				us2->InsertarFotoEnUsuario(f);
					if(this->getdebug() == true){
						cout << GREEN << "FOTO INTRODUCIDA CORRECTAMENTE" << RESTORE << endl;
					}
			}
			else{
				us2->InsertarFotoEnUsuario(f);
				
			}
		}
		else{
			cout << RED << "USUARIO NO VALIDO PARA GUARDAR FOTOS, VOLVIENDO AL MENU PRINCIPAL..." << RESTORE << endl;
		}
	}
}

void TablaUsuarios::ImprimirFotosUsuario(){
string login;
int posicion = 0;
	if(this->getdebug() == true){
		cout << RED << "DEBUG: ENTRANDO A IMPRIMIR FOTOS DE UN USUARIO " << RESTORE << endl;
	}
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
	if(this->getdebug() == true){
		cout << RED << "DEBUG: REALIZANDO BUSQUEDA DE LOGIN " << RESTORE << endl;
	}
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
	if(this->getdebug() == true){
		cout << RED << "DEBUG : ENTRANDO EN BUSQUEDA Y MUESTRA DE USUARIO POR LOGIN..." << RESTORE << endl;
	}
	cout << PURPLE "Introduce el login del usuario el cual quieres buscar..." << RESTORE << endl;
	cin >> login;
	posicion = this->BusquedaLogin(login);
	if (posicion == -1){
		cout << RED << "EL LOGIN INTRODUCIDO NO CORRESPONDE CON NINGUN USUARIO, NO SE MOSTRARÁ NINGÚN USUARIO, VOLVIENDO AL MENÚ PRINCIPAL..." << RESTORE << endl;
	}
	else{
		this->punteroapuntero[posicion]->PrintUsuario();
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG : BUSQUEDA Y MUESTRA DE USUARIO POR LOGIN COMPLETADA" << RESTORE << endl;
	}
}
void TablaUsuarios::EliminarFoto(){
string login;
int posicion = 0;
int elim = 0;
	if(this->getdebug() == true){
		cout << RED << "DEBUG : ENTRANDO EN ELIMINAR UNA FOTO DE UN USUARIO..." << RESTORE << endl;
	}
	cout << PURPLE "Introduce el login del usuario en el cual quieres eliminar una foto..." << RESTORE << endl;
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
			if ((us2->getTotalFotosUsuario()) == 0){
				cout << RED << "EL USUARIO NO TIENE FOTOS, POR FAVOR ASEGURESE DE QUE EL USUARIO ELEGIDO TENGA AL MENOS UNA FOTO PARA ELIMINAR... " << RESTORE << endl;
			}			
			else{
				cout << "Introduce el numero de la foto la cual quieres eliminar " << endl;
				cin >> elim;
				if(elim > us2->getTotalFotosUsuario() || elim == 0){
					cout << RED << "NUMERO DE FOTO NO VALIDA, VOLVIENDO AL MENU PRINCIPAL..." << RESTORE << endl;
				}
				else{	
					cout << RED << "ELIMINANDO FOTO..." << RESTORE << endl;
					us2->EliminarFotoUsuario(elim);
					cout << GREEN << "FOTO ELIMINADA CORRECTAMENTE" << RESTORE << endl;
				}
			}
		}
		else{
			cout << RED << "USUARIO NO VALIDO PARA MOSTRAR FOTOS, VOLVIENDO AL MENU PRINCIPAL..." << RESTORE << endl;
		}
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG : FOTO ELIMINADA CORRECTAMENTE" << RESTORE << endl;
	}
}
void TablaUsuarios::FuncionalidadInsertarUsuario(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG : ENTRANDO EN INSERTAR USUARIO..." << RESTORE << endl;
	}
	if(this->getdebug() == true){
		cout << RED << "DEBES DE CREAR ANTES UNA TABLA" << endl;
	}
	else{
		Admin* admin = new Admin();
		Normal* normal = new Normal();
		int a;
		int pos = 0;
		cout << BLUE << "Elige que tipo de Usuario quieres crear" << RESTORE << endl;
		cout << BLUE << "Para Usuario Normal pulsa [1], para Usuario Administrados pulsa [2]" << RESTORE << endl;
		cin >> a;
		while(!cin){
			cout << RED << "No introduzcas letras, intentalo de nuevo" << RESTORE << endl;	
			Filtro();
			cin >> a;
		}
		
		switch (a) {
	
			case 1 :
					normal->RellenarUsuario();
					pos = BusquedaLogin(normal->getLogin());
					if (pos == -1){
						this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
						insertarUsuarioenTabla (normal, getTotalUsuarios() - 1);
					}
					else{
						cout << RED << "El login introducido ya se encuentra en uso, no se procedera a la insercion del usuario, volviendo al menu..." << RESTORE << endl;
					}
				break;
	
			case 2 :
					admin->RellenarUsuario();
					pos = BusquedaLogin(normal->getLogin());
					if (pos == -1){
						this->resizeTablaUsuariosCrecer(this->getTotalUsuarios() + 1);
						insertarUsuarioenTabla (admin, getTotalUsuarios() - 1);
					}
					else{
						cout << RED << "El login introducido ya se encuentra en uso, no se procedera a la insercion del usuario, volviendo al menu..." << RESTORE << endl;
					}
				break;
		
			default :
			cout << RED << "Has pulsado una tecla que no es valida, volviendo al menu principal..." << RESTORE << endl;
		}
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG : USUARIO INSERTADO" << RESTORE << endl;
	}
}
void TablaUsuarios::EliminarUsuario(){
string login;
int posicion = 0;
int elim = 0;
	if(this->getdebug() == true){
		cout << RED << "DEBUG : ENTRANDO EN ELIMINAR USUARIO..." << RESTORE << endl;
	}
	cout << PURPLE "Introduce el login del usuario el cual quieres eliminar..." << RESTORE << endl;
	cin >> login;
	posicion = BusquedaLogin(login);
	if (posicion == -1){
		cout << RED << "EL LOGIN INTRODUCIDO NO CORRESPONDE CON NINGUN USUARIO, NO SE PUEDE INTRODUCIR FOTO, VOLVIENDO AL MENÚ PRINCIPAL..." << RESTORE << endl;
	}
	else{
		if(this->getTotalUsuarios() == 0){
			cout << RED << "NO HAY USUARIOS EN LA TABLA, VOLVIENDO AL MENU PRINCIPAL" << RESTORE << endl;
		}
		else{
			this->punteroapuntero[posicion]->~Usuario();
			this->punteroapuntero[posicion] = 0;
			this->punteroapuntero[posicion] = this->punteroapuntero[this->getTotalUsuarios() - 1];
			this->resizeTablaUsuariosDisminuir(this->getTotalUsuarios() - 1);
		}
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG : USUARIO ELIMINADO" << RESTORE << endl;
	}	
}
void TablaUsuarios::OrdenarPorLogin (){
	
	int izquierda = 0;//Variable que apunta a la primera posicion de la parte desordenada
	Usuario* aux; //Variable que utilizaremos como cajon para ayudar a intercambiar Usuarios
	int index = 0;//Indice que va marcando la posicion del vector por la que vamos 
	bool cambio = true;//Booleano que nos permite acortar el bucle en caso de que no haya mas cambios porque si no hay mas cambios esta todo ordenado

	if(this->getdebug() == true){
		cout << RED << "DEBUG : ORDENANDO ALFABETICAMENTE POR LOGIN..." << RESTORE << endl;
	}
	for (izquierda = 0; izquierda < this->getTotalUsuarios() && cambio == true; izquierda++){
		cambio = false;
		for (index = (this->getTotalUsuarios() - 1); index > izquierda; index--){
			if (this->punteroapuntero[index]->getLogin() < this->punteroapuntero[index - 1]->getLogin()){
				cambio = true;
				//Aqui hacemos el intercambio
				aux = (this->punteroapuntero[index]);
				(this->punteroapuntero[index]) = (this->punteroapuntero[index - 1]);
				(this->punteroapuntero[index - 1]) = aux;
			}
		}
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG : TABLA ORDENADA" << RESTORE << endl;
	}
}

void TablaUsuarios::OrdenarPorTotalFotos(){
	
	int izquierda = 0;//Variable que apunta a la primera posicion de la parte desordenada
	Normal* aux; //Variable que utilizaremos como cajon para ayudar a intercambiar Usuarios
	int index = 0;//Indice que va marcando la posicion del vector por la que vamos 
	bool cambio = true;//Booleano que nos permite acortar el bucle en caso de que no haya mas cambios porque si no hay mas cambios esta todo ordenado
	int pos = 0;
	Normal* us1;
	Normal* us2;
	Normal* us3;
	Normal* us4;
	if(this->getdebug() == true){
		cout << RED << "DEBUG : ORDENANDO POR LOGIN TOTAL DE FOTOS..." << RESTORE << endl;
	}
	for (izquierda = 0; izquierda < this->getTotalUsuarios() && cambio == true; izquierda++){
	if(us1 = dynamic_cast < Normal* > (this->punteroapuntero[izquierda])){
		pos = izquierda;
		cambio = false;
		for (index = (this->getTotalUsuarios() - 1); index > izquierda; index--){	
			us2 = us1;
				if(us3 = dynamic_cast < Normal* > (this->punteroapuntero[index])){
					us4 = us3;
					if (us2->getTotalFotosUsuario() > us4->getTotalFotosUsuario()){
						cambio = true;
						//Aqui hacemos el intercambio
						aux = us2;
						this->punteroapuntero[izquierda] = us4;
						this->punteroapuntero[index] = aux;
					
					}
				}
			}
		}
	}
	if(this->getdebug() == true){
		cout << RED << "DEBUG : TABLA ORDENADA" << RESTORE << endl;
	}
}
void TablaUsuarios::OrdenarTabla(){
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
			this->OrdenarPorLogin ();
			break;
		case 2 :
			this->OrdenarPorTotalFotos();
			break;
		default :
			cout << RED << "Has pulsado una tecla que no es valida, vuelve a intentarlo haciendole caso al enunciado por favor ;)" << RESTORE << endl;
		}
	if(this->getdebug() == true){
		cout << RED << "DEBUG: TABLA ORDENADA " << RESTORE << endl;
	}
}
void TablaUsuarios::EliminarTabla(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: ELIMINANDO TABLA " << RESTORE << endl;
	}
	if(this->getTotalUsuarios() == 0){
		cout << "NO HAY NINGUNA TABLA..." << RESTORE << endl;
	}
	else{
		for(int i = 0; i < this->getTotalUsuarios(); i++){
			delete this->punteroapuntero[i];
		}
		this->setTotalUsuarios(0);
	}
}
void TablaUsuarios::Testing(){
	//Caso de testing
		//Se repite 5 veces
		for(int i = 0; i < 5; i++){
			//Creamos una tabla
			this->TablaPorDefecto();
			for(int j = 0; j < 3; j++){
				//Insertamos 3 usuarios en esta tabla
				this->FuncionalidadInsertarUsuario();
			}
			//Mostramos por pantalla la tabla
			this->PrintTabla();
			for(int k = 0; k < 5; k++){
				//Eliminamos 5 usuarios de la tabla
				this->EliminarUsuario();
			}
			//Volvemos a mostrar la tabla por pantalla
			this->PrintTabla();
			for(int l = 0; l < 3; l++){
				//Insertamos 3 usuarios de nuevo en la tabla
				this->FuncionalidadInsertarUsuario();
			}
			//Volvemos a mostrar la tabla por pantalla
			this->PrintTabla();
			for(int m = 0; m < 5; m++){
				//Eliminamos 3 usuarios de nuevo en la tabla
				this->EliminarUsuario();
			}
			//Volvemos a mostrar la tabla por pantalla
			this->PrintTabla();
		}
}
void TablaUsuarios::PrintTabla(){
	if(this->getdebug() == true){
		cout << RED << "DEBUG: MOSTRANDO TABLA " << RESTORE << endl;
	}
	if (getTotalUsuarios() == 0){
		cout << RED << "LA TABLA NO EXISTE O HA SIDO BORRADA, POR FAVOR CREE UNA NUEVA TABLA" << RESTORE << endl;
	}
	else{
		//cout << RED << "DEBUG: " << "Entra en el printTabla" << RESTORE << endl;
		cout << YELLOW << "*****TABLA DE USUARIOS*****" << RESTORE << endl;
		for (int i = 0; i < getTotalUsuarios(); i++){
			this->punteroapuntero[i]->PrintUsuario();
		}
	}
}
