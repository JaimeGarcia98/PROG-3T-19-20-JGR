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

	public:
		Polinomio();			 //Constructor por defecto
		Polinomio(int maxGrado); //Otro constructor
		void setCoeficienteV1(int i, float c);
		void setCoeficienteV2(int i, float c);
		float getCoeficiente(int i) const;
		int getGrado() const;
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
int main (){

	Polinomio Polinom;
	
	/*Polinom.setCoeficienteV1(1,3);
	Polinom.setCoeficienteV1(2,4);
	Polinom.print();
	cout << GREEN << "DEBUG: Primera parte (setCoeficienteV1) listo... " << RESTORE << endl;*/
	Polinom.setCoeficienteV2(1,1);
	Polinom.setCoeficienteV2(9,3);
	Polinom.print();
	cout << GREEN << "DEBUG: Segunda parte (setCoeficienteV2) lista... " << RESTORE << endl;
}
