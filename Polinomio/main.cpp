#include <iostream>
#include <string>
#include <stdlib.h>
#include "Polinomio.h"
#define RESTORE "\033[1;0m"
#define GREY "\033[1;30m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
using namespace std;

class Vista{
	private:
	Polinomio** VectorPoli; //Vector de Punteros a polinomios
	int dim; //Dimension del Vector
	void resize(int i);
	void InsertarPolinomioEnVector(Polinomio *p, int pos);
	public:
	Vista();
	void CrearPolinomio(Polinomio &p);
	void EliminarPolinomio(int pos);
	void SumaPolinomios();
	void PrintMenu();
	void testing ();
	
};
Vista::Vista(){
	cout << RED << "DEBUG: Llamando al constructor de clase vista..." << RESTORE << endl;
	int tamanio = 0;
	VectorPoli = new Polinomio* [tamanio];
	if (VectorPoli == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
	for(int i = 0; i < tamanio; i++){
		VectorPoli[i] = new Polinomio();
	}
	dim = tamanio;
}
void Vista::resize(int i){
	Polinomio** v_aux = new Polinomio* [i + 1];
	for(int a = 0; a < i + 1; a++){
		v_aux[a] = new Polinomio();
	}
	if (v_aux == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);//Salida forzada del programa para terminar el proceso.
    }
	for(int j = 0; j <= dim; j++){
		v_aux[j] = VectorPoli[j];
	}
	delete [] VectorPoli; //Aqui libero la memoria 
	VectorPoli = v_aux; //Cambio los punteros de coeficientes	
	//Pongo a 0.0 los nuevos coeficientes
	for(int k = dim + 1; k <= i; k++){
		VectorPoli[k] = 0; 
	}
	dim = i; //Cambio el nuevo grado maximo del polinomio
}

void Vista::CrearPolinomio(Polinomio &p){
	int grado;
	float coef;
	int cont;
	cout << BLUE << "¿Cuantos monomios vas a introducir? " << RESTORE << endl;
	cin >> cont;
	for(int i = 0; i < cont; i++){
		cout << "Introduce el valor del coeficiente... " << endl;
		cin >> coef;
		cout << "Introduce el grado del monomio... " << endl;
		cin >> grado;
		if(grado >= 0){
			p.setCoeficienteV3(grado,coef);
		}
	}
}
void Vista::InsertarPolinomioEnVector(Polinomio *p, int pos){
	
	if(pos > dim){
		VectorPoli[pos] = p;
	}
	else{
		resize(pos);
		VectorPoli[pos] = p;
	}
	
}
void Vista::InsertarPolinomioEnVector(Polinomio *p, int pos){
	cout << RED << "Paso 2.5 comienza" << RESTORE << endl;
	if(pos > dim){
		VectorPoli[pos] = p;
	}
	else{
		resize(pos);
		VectorPoli[pos] = p;
	}
	cout << RED << "Paso 2.5 realizado" << RESTORE << endl;
}
void Vista::PrintMenu(){
bool interactua = true;
	while (interactua == true){//Bucle para que se repita el menu hasta que interactua se haga false (solo ocurre al pulsar la tecla exit)
	int a;
	Polinomio p;
	cout << BLUE << "1.Crear Polinomio" << RESTORE << endl;
	cout << BLUE << "2.Insertar Polinomio en vector" << RESTORE << endl;
	cout << BLUE <<	"3.Sumar Polinomios" << RESTORE << endl;
	cout << BLUE << "4.Eliminar Polinomio" << RESTORE << endl;
	cout << BLUE << "5.Salir" << RESTORE << endl;

	cin >> a;
		switch (a) {
			case '1' :
				CrearPolinomio(p);
				break;
			case '2' :
				InsertarPolinomioEnVector(&p, dim + 1);
				break;
			case '3' :
				
				break;
			case '4' :
			
				break;
			case '5' :
				interactua = false;// En este momento se sale del menu
				break;
		}
	}
}
void Vista::testing (){
Polinomio p;
	CrearPolinomio(p);
	cout << RED << "Paso 1 realizado" << RESTORE << endl;
	InsertarPolinomioEnVector(&p, 3);
	cout << RED << "Paso 2 realizado" << RESTORE << endl;
	cout << *VectorPoli[3];
	cout << RED << "Paso 3 realizado" << RESTORE << endl;
	
}
int main (){

	/*Polinomio *Polinom = new Polinomio();
	Polinomio poli_est;*/
	
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
	/*Polinom->setCoeficienteV3(2,5.5);
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
	Copia_est.print();*/

	/*Polinom->setGrado(9);//Tras ponerlo en privado no debe de dejar que esta sentencia se ejecute
	Polinom->setCoeficienteV3(1,1.1);
	Polinom->print();*/

	// ********************* Parte del modulo de suma de polinomios ************************
		
		//Version 1.0 del metodo de suma de polinomios.(Se almacena el resultado de la suma en el polinomio que llama al metodo)
	/*Polinomio p;
	
	Polinom->setCoeficienteV3(2,5.5);
	Polinom->setCoeficienteV3(3,4);
	p.setCoeficienteV3(2,1);
	p.setCoeficienteV3(1,7);
	p.print();
	cout << p.getMaxGrado() << endl;
	cout << Polinom->getMaxGrado() << endl;
	Polinom->print();
	Polinom->SumaV1(p);
	cout << p.getMaxGrado() << endl;
	cout << Polinom->getMaxGrado() << endl;
	Polinom->print();*/

		//Version 2.0 del metodo de suma de polinomios.(Se almacena el resultado de la suma de dos polinomios externos en el OBJETO Polinomio que llama al metodo)
	/*Polinomio p1;
	Polinomio p2;
		//RELLENAR EL POLINOMIO P1 Y LO MUESTRO POR PANTALLA
	p1.setCoeficienteV3(1,1);
	p1.setCoeficienteV3(3,7);
	p1.print();
		//RELLENAR EL POLINOMIO P2 Y LO MUESTRO POR PANTALLA
	p2.setCoeficienteV3(2,3);
	p2.setCoeficienteV3(4,5);
	p2.print();
		//LLAMO AL METODO DE SUMA DE POLINOMIO V2
	Polinom->SumaV2(p1, p2);
	Polinom->print();*/

		//Version 3.0 del metodo de suma de polinomios.(Se devuelve un OBJETO Polinomio que posteriormente se asigna a un Polinomio resultado)
	/*Polinomio p1;
	Polinomio p2;

		//RELLENAR EL POLINOMIO P1 Y LO MUESTRO POR PANTALLA
	p1.setCoeficienteV3(1,1);
	p1.setCoeficienteV3(3,7);
	p1.print();
		//RELLENAR EL POLINOMIO P2 Y LO MUESTRO POR PANTALLA
	p2.setCoeficienteV3(2,3);
	p2.setCoeficienteV3(6,5);
	p2.print();
		//LLAMO AL METODO DE SUMA DE POLINOMIO V3
	Polinomio resultado = p1.SumaV3(p2);
	resultado.print();*/

		//Version 4.0 del metodo de suma de polinomios.(Se devuelve un OBJETO Polinomio que posteriormente se asigna a un Polinomio resultado)
	/*Polinomio *polinom = new Polinomio();
	Polinomio *p4 = new Polinomio();
		//RELLENAR EL POLINOMIO Polinom Y LO MUESTRO POR PANTALLA
	polinom->setCoeficienteV3(2,5.5);
	polinom->setCoeficienteV3(4,1.1);
	polinom->print();
		//RELLENAR EL POLINOMIO P4 Y LO MUESTRO POR PANTALLA
	p4->setCoeficienteV3(2,2.6);
	p4->setCoeficienteV3(3,3.1);
	p4->print();
		//LLAMO AL METODO DE SUMA DE POLINOMIO V4
	Polinomio *resultado = polinom->SumaV4(p4);
	resultado->print();
		//LIBERO LA MEMORIA DINAMICA
	delete polinom;
	delete p4;
	delete resultado;*/

	// ********************* Parte del modulo de sobrecarga de operadores ************************

		//Sobrecarga del operador +
	/*Polinomio p1;
	Polinomio p2;

		//RELLENAR EL POLINOMIO P1 Y LO MUESTRO POR PANTALLA
	p1.setCoeficienteV3(1,1);
	p1.setCoeficienteV3(3,7);
	p1.print();
		//RELLENAR EL POLINOMIO P2 Y LO MUESTRO POR PANTALLA
	p2.setCoeficienteV3(2,3);
	p2.setCoeficienteV3(6,5);
	p2.print();
		//Uso el operador + una vez sobrecargado para sumar 2 polinomios
	Polinomio resultado = p1 + p2;
	resultado.print();*/

		//Sobrecarga del operador =
	/*Polinomio p1;
	Polinomio p2;

		//RELLENAR EL POLINOMIO P1 Y LO MUESTRO POR PANTALLA
	p1.setCoeficienteV3(1,1);
	p1.setCoeficienteV3(3,7);
	p1.print();
		//RELLENAR EL POLINOMIO P2 Y LO MUESTRO POR PANTALLA
	p2.setCoeficienteV3(2,3);
	p2.setCoeficienteV3(6,5);
	p2.print();
		//Uso el operador = para asignar a 2 nuevos polinomios los antiguos y los vuelvo a mostrar por pantalla
	Polinomio copia1;
	Polinomio copia2;
	copia1 = p1;
	copia2 = p2;
	copia1.print();
	copia2.print();*/

		//Sobrecarga del operador << 
	/*Polinomio p1;
	Polinomio p2;

		//RELLENAR EL POLINOMIO P1 Y LO MUESTRO POR PANTALLA MEDIANTE LA SOBRECARGA DEL OPERADOR <<
	p1.setCoeficienteV3(1,1);
	p1.setCoeficienteV3(3,7);
	cout << p1;
		//RELLENAR EL POLINOMIO P2 Y LO MUESTRO POR PANTALLA MEDIANTE LA SOBRECARGA DEL OPERADOR <<
	p2.setCoeficienteV3(2,3);
	p2.setCoeficienteV3(6,5);
	cout << p2;*/

		//Sobrecarga del operador >>
	/*Polinomio p1;
	Polinomio p2;

		//RELLENAR EL POLINOMIO P1 MEDIANTE LA SOBRECARGA DEL OPERADOR >> Y LO MUESTRO POR PANTALLA MEDIANTE LA SOBRECARGA DEL OPERADOR <<
	cin >> p1;
	cout << p1;
		//RELLENAR EL POLINOMIO P2 MEDIANTE LA SOBRECARGA DEL OPERADOR >> Y LO MUESTRO POR PANTALLA MEDIANTE LA SOBRECARGA DEL OPERADOR <<
	cin >> p2;
	cout << p2;*/

	Vista mivista;
	//mivista.testing();	
	mivista.PrintMenu();
}
