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

class Polinmio {

	private:
		float *coef;		// Vector con los coeficientes
		int grado;			// Grado del polinomio
		int max_grado;	   	// Maximo grado permitido en este polinomio

	public:
		Polinomio();			 //Constructor por defecto
		Polinomio(int maxGrado); //Otro constructor
		void setCoeficiente(int i, float c);
		float getCoeficiente(int i) const;
		int getGrado() const;
		void print() const;

};

float Polinomio :: getCoeficiente (int i) const {
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

int Polinomio :: getGrado () const {
/**
* @brief Metodo público del objeto polinomio, este metodo devuelve el valor del grado actual del polinomio, esta definido como metodo constante para impedir que se pueda modificar algun dato miembro de polinomio
* @pre 
* @param () 
* @return Devuelve el valor del grado actual del polinomio 
* @post 
*/
	return grado;

}
//void Polinomio :: print () const {
/**
* @brief Modulo el cual imprime por pantalla un polinomio de la forma de 1.1 x^2 (+ o -) 1.1 x^1 (+ o -) 1.1 x (+ o -) 1
* @pre 
* @param () 
* @return 
* @post Se debera de mostrar por pantalla el polinomio de manera correcta y de la forma en la cual se especifica
*/

	/*cout << getCoeficiente(getGrado());
	cout << "x^" << getGrado();
	for ( int i = getGrado() - 1 ; i >= 0; i--){
		if (getCoeficiente != 0.0){

		 	//Aqui iria un + o un - 
			//		 |
			//		 V 
			cout << " " << getCoeficiente(i) << "x^" << i;
		}
	}
	cout << endl;
}*/
int main (){

}
