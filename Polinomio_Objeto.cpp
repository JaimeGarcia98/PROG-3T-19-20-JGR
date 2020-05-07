#include <iostream>
#include <string>
#include <stdlib.h>
#define RESTORE "\033[1;0m"
#define GREY "\033[1;30m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
using namespace std;
/*************************************
** Definición del OBJETO Polinomio  **
**************************************/

class Polinomio {

	private:
		float *coef;		// Vector con los coeficientes
		int grado;			// Grado del polinomio
		int max_grado;	   	// Maximo grado permitido en este polinomio
		void resize(int i);		//Funcion privada para redimensionar el tamaño del vector de coeficientes de un objeto polinomio

	public:
		Polinomio();			 //Constructor por defecto
		Polinomio(int maxGrado); //Otro constructor
		Polinomio(const Polinomio &p);
		void setCoeficienteV1(int i, float c);
		void setCoeficienteV2(int i, float c);
		void setCoeficienteV3 (int i, float c);
		float getCoeficiente(int i) const;
		int getGrado() const;
		int getMaxGrado () const;
		void print() const;
		~Polinomio();    //Destructor
};
Polinomio::Polinomio (){
	int dim_nueva = 5;
	
	coef = new float [dim_nueva];
	for (int i = 0; i < dim_nueva; i++){
		coef[i] = 0.0;
	}
	grado = 0;
	max_grado = 5;

}
Polinomio::Polinomio (int maxGrado){
	
	coef = new float [maxGrado + 1];
	if (coef == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);//Salida forzada del programa para terminar el proceso.
    }
	for (int i = 0; i < maxGrado + 1; i++){
		coef[i] = 0;
	}
	grado = 0;
	max_grado = maxGrado;
}
void Polinomio::setCoeficienteV1 (int i, float c) {
	if (i >= 0){
		coef[i] = c;
		if(c != 0.0 && i > grado){
			grado = i;
		}
	}
}
void Polinomio::setCoeficienteV2 (int i, float c) {
	if (i >= 0){ 
		if (i > max_grado){ //Si el indice del coeficiente es mayor que el maximo grado permitido en nuestro polinomio, necesitamos mas espacio
			cout << RED << "DEBUG : Ampliando espacio... " << RESTORE << endl;
			float *	v_aux = new float[i + 1];
			if (v_aux == 0){
        		cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        		exit(-1);//Salida forzada del programa para terminar el proceso.
    		}
			//Copiamos los coeficientes en el auxiliar
			for(int j = 0; j <= grado; j++){
				v_aux[j] = coef[j];
			}		
			cout << GREEN << "DEBUG : Espacio ampliado... " << RESTORE << endl;
			cout << RED << "DEBUG : Liberando memoria antigua... " << RESTORE << endl;
			delete [] coef; //Aqui libero la memoria 
			coef = v_aux; //Cambio los punteros de coeficientes	
			cout << GREEN << "DEBUG : Memoria antigua liberada correctamente... " << RESTORE << endl;
			//Pongo a 0.0 los nuevos coeficientes
			for(int k = grado + 1; k <= i; k++){
				coef[k] = 0.0; 
			}
			max_grado = i; //Cambio el nuevo grado maximo del polinomio
		}
		coef[i] = c; //Aqui asigno el nuevo coeficiente
		//Aqui cambio el grado actual del polinomio
		if(c != 0.0 && i > grado){
			grado = i;
		}
		else if(c == 0.0 && i == grado){//
			while(coef[grado] == 0.0 && grado > 0){//Aqui cambio el grado por el primer coeficiente que encuentre distinto de 0
				grado = grado - 1;//Aqui he tenido problemas al poner el -- y no se porque me da fallo, al ponerlo asi si funciona
			}
		}
	}
	else{
		cout << RED << "No se puede introducir un monomio de grado negativo " << RESTORE << endl;
	}
}
void Polinomio::resize(int i){
		float *	v_aux = new float[i + 1];
			if (v_aux == 0){
        		cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        		exit(-1);//Salida forzada del programa para terminar el proceso.
    		}
			//Copiamos los coeficientes en el auxiliar
			for(int j = 0; j <= grado; j++){
				v_aux[j] = coef[j];
			}		
			cout << GREEN << "DEBUG : Modificando espacio... " << RESTORE << endl;
			cout << RED << "DEBUG : Liberando memoria antigua... " << RESTORE << endl;
			delete [] coef; //Aqui libero la memoria 
			coef = v_aux; //Cambio los punteros de coeficientes	
			cout << GREEN << "DEBUG : Memoria antigua liberada correctamente... " << RESTORE << endl;
			//Pongo a 0.0 los nuevos coeficientes
			for(int k = grado + 1; k <= i; k++){
				coef[k] = 0.0; 
			}
			max_grado = i; //Cambio el nuevo grado maximo del polinomio
}
void Polinomio::setCoeficienteV3 (int i, float c) {
	if (i >= 0){ 
		if (i > max_grado){ //Si el indice del coeficiente es mayor que el maximo grado permitido en nuestro polinomio, necesitamos mas espacio
			cout << RED << "DEBUG : Ampliando espacio... " << RESTORE << endl;
			resize(i);
		}
		coef[i] = c; //Aqui asigno el nuevo coeficiente
		//Aqui cambio el grado actual del polinomio
		if(c != 0.0 && i > grado){
			grado = i;
		}
		else if(c == 0.0 && i == grado){//
			while(coef[grado] == 0.0 && grado > 0){//Aqui cambio el grado por el primer coeficiente que encuentre distinto de 0
				grado = grado - 1;//Aqui he tenido problemas al poner el -- y no se porque me da fallo, al ponerlo asi si funciona
			}
			if (grado < max_grado){
				cout << RED << "DEBUG : Disminuyendo espacio... " << RESTORE << endl;
				resize(grado);
			}
		}
	}
	else{
		cout << RED << "No se puede introducir un monomio de grado negativo " << RESTORE << endl;
	}
}
float Polinomio::getCoeficiente (int i) const {
/**
* @brief Metodo público del objeto polinomio, este metodo devuelve el valor del coeficiente de la posicion i del polinomio, esta definido como metodo constante para impedir que se pueda modificar algun dato miembro de polinomio
* @pre 
* @return Devuelve el coeficiente de la posicion i del vector de coeficientes del objeto polinomio
* @post 
*/
	if (i > grado){
		return 0.0;
	}
	else{
		return coef[i];	
	}
}
int Polinomio::getGrado () const {

/**
* @brief Metodo público del objeto polinomio, este metodo devuelve el valor del grado actual del polinomio, esta definido como metodo constante para impedir que se pueda modificar algun dato miembro de polinomio
* @pre 
* @param () 
* @return Devuelve el valor del grado actual del polinomio 
* @post 
*/
	return grado;

}
int Polinomio::getMaxGrado () const {

/**
* @brief Metodo público del objeto polinomio, este metodo devuelve el valor del grado actual del polinomio, esta definido como metodo constante para impedir que se pueda modificar algun dato miembro de polinomio
* @pre 
* @param () 
* @return Devuelve el valor del grado actual del polinomio 
* @post 
*/
	return max_grado;

}
void Polinomio::print () const {

/**
* @brief Modulo el cual imprime por pantalla un polinomio de la forma de 1.1 x^2 (+ o -) 1.1 x^1 (+ o -) 1.1 x (+ o -) 1
* @pre 
* @param () 
* @return 
* @post Se debera de mostrar por pantalla el polinomio de manera correcta y de la forma en la cual se especifica
*/

	cout << BLUE << getCoeficiente(getGrado());
	cout << BLUE << "x^" << getGrado();
	for ( int i = getGrado() - 1 ; i >= 0; i--){
		if (getCoeficiente(i) != 0.0){

			cout << " + " << getCoeficiente(i) << "x^" << i;
		}
	}
	cout << RESTORE << endl;
}
Polinomio::~Polinomio(){
	cout << RED << "DEBUG: Eliminando polinomio... " << RESTORE << endl;
		//1º)Pongo los coeficientes del polinomio a 0.0
		for(int i = 0; i < max_grado; i++){
			coef[i] = 0.0;
		}
		//2º) Pongo el grado actual del polinomio a 0
		grado = 0;
		//3º) Pongo el grado maximo permitido en este polinomio a 0
		max_grado = 0;
		//Libero el espacio en memoria dinamica
		delete [] coef;
		coef = 0;
	cout << RED << "DEBUG: Polinomio ELiminado... " << RESTORE << endl;
}
void Test_caso1(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 1: Insertar un monomio de grado menor que el grado actual
* @pre 
* @param () 
* @return 
* @post 
*/

	cout << endl << CYAN << "***** Ejecutando el caso de testing 1 ***** " << RESTORE << endl;
	
	p->setCoeficienteV3(3,5.5);
	cout << GREEN << "Introducido el valor por defecto" << endl;
	p->print();
	cout << RED << "DEBUG : Introduciendo un valor menor al grado actual " << RESTORE << endl;
	p->setCoeficienteV3(2,3.3);
	cout << GREEN << "DEBUG : Introducido el valor correctamente, imprimiendo nuevo polinomio... " << RESTORE << endl;
	p->print();
}
void Test_caso2(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 2: Insertar un monomio de grado negativo
* @pre 
* @param () 
* @return 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 2 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado negativo " << RESTORE << endl;
	p->setCoeficienteV3(-2,1.3);
	cout << GREEN << "DEBUG : Previamente a esta sentencia debe de haber salido un mensaje de error... " << RESTORE << endl;
	p->print();
}
void Test_caso3(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 3: Insertar un monomio de grado mayor al grado actual pero menor que max_grado
* @pre 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 3 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado mayor que el actual pero menor que el maximo" << RESTORE << endl;
	cout << RED << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	p->setCoeficienteV3(4,6.7);
	cout << GREEN << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	p->print();
}
void Test_caso4(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 4: Insertar un monomio de grado mayor al grado actual y mayor que max_grado
* @pre 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 4 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado mayor que el actual pero menor que el maximo" << RESTORE << endl;
	cout << RED << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo base --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->setCoeficienteV3(7,8.7);
	cout << GREEN << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->print();
}
void Test_caso5(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 4: Insertar un monomio de grado igual al grado actual y cuyo coeficiente es 0
* @pre 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 5 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado igual al grado actual y cuyo coeficiente es 0" << RESTORE << endl;
	cout << RED << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo base --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->setCoeficienteV3(7,0.0);
	cout << GREEN << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->print();
}
void ModuloTesting(Polinomio *p){
	
	Test_caso1(p);
	Test_caso2(p);
	Test_caso3(p);
	Test_caso4(p);
	Test_caso5(p);
}
Polinomio::Polinomio(const Polinomio &p){
	cout << RED << "Iniciando el constructor por copia " << RESTORE << endl;
	max_grado = p.max_grado;
	grado = p.grado;
	coef = new float[max_grado + 1];
	if (coef == 0){
        		cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        		exit(-1);//Salida forzada del programa para terminar el proceso.
    }
	for(int i = 0; i <= max_grado; i++){
		coef[i] = p.coef[i];
	}
}
int main (){

	Polinomio *Polinom = new Polinomio();
	Polinomio poli_est;
	
	/*Polinom.setCoeficienteV1(1,3);
	Polinom.setCoeficienteV1(2,4);
	Polinom.print();
	cout << GREEN << "DEBUG: Primera parte (setCoeficienteV1) listo... " << RESTORE << endl;*/
	/*Polinom.setCoeficienteV2(1,1);
	Polinom.setCoeficienteV2(9,3);
	Polinom.print();
	cout << GREEN << "DEBUG: Segunda parte (setCoeficienteV2) lista... " << RESTORE << endl;*/

	// ********************* Parte del testing ************************
	/*cout << GREEN << "DEBUG : Empezando el testing a poli_est(version estática)" << RESTORE << endl;
	ModuloTesting(&poli_est);
	cout << PURPLE << "DEBUG : Acabado el testing a poli_est(version estática)" << RESTORE << endl;
	cout << GREEN << "DEBUG : Empezando el testing a *Polinom(version dinámica)" << RESTORE << endl;
	ModuloTesting(Polinom);
	cout << RED << "DEBUG : Liberando memoria dinamica..." << RESTORE << endl;
	delete Polinom;
	cout << GREEN << "DEBUG : Memoria dinámica borrada correctamente" << RESTORE << endl;*/

	// ********************* Parte del constructor por copia ************************
		//Parte dinamica
	Polinom->setCoeficienteV3(2,5.5);
	Polinom->setCoeficienteV3(4,1.1);
	cout << GREEN << "DEBUG : Grado actual --> " <<  Polinom->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  Polinom->getMaxGrado() << RESTORE << endl;
	cout << RED << "A continuacion vamos a crear una copia del polinomio mostrado..." << RESTORE << endl;
	Polinom->print();
	Polinomio *Copia_pol = new Polinomio(*Polinom);
	cout << GREEN << "DEBUG : Grado actual --> " <<  Copia_pol->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  Copia_pol->getMaxGrado() << RESTORE << endl;
	Copia_pol->print();
	cout << endl;
	cout << BLUE << "CAMBIANDO A LA PARTE ESTATICA DEL TESTING " << RESTORE << endl;
	cout << endl;
		//Parte estatica
	poli_est.setCoeficienteV3(2,5.5);
	poli_est.setCoeficienteV3(4,1.1);
	cout << GREEN << "DEBUG : Grado actual --> " <<  poli_est.getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  poli_est.getMaxGrado() << RESTORE << endl;
	cout << RED << "A continuacion vamos a crear una copia del polinomio mostrado..." << RESTORE << endl;
	poli_est.print();
	Polinomio Copia_est = Polinomio(poli_est);
	cout << GREEN << "DEBUG : Grado actual --> " <<  Copia_est.getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  Copia_est.getMaxGrado() << RESTORE << endl;
	Copia_est.print();



}
